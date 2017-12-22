module Cube
  ( vertex3f
  , displayCubes
  ) where

import           Data.IORef
import           Graphics.UI.GLUT
import           Points
import           Control.Monad

vertex3f :: (GLfloat, GLfloat, GLfloat) -> IO ()
vertex3f (x, y, z) = vertex $ Vertex3 x y z

cube :: GLfloat -> IO ()
cube w = renderPrimitive Quads $ mapM_ vertex3f
    [ ( w, w, w), ( w, w,-w), ( w,-w,-w), ( w,-w, w),
      ( w, w, w), ( w, w,-w), (-w, w,-w), (-w, w, w),
      ( w, w, w), ( w,-w, w), (-w,-w, w), (-w, w, w),
      (-w, w, w), (-w, w,-w), (-w,-w,-w), (-w,-w, w),
      ( w,-w, w), ( w,-w,-w), (-w,-w,-w), (-w,-w, w),
      ( w, w,-w), ( w,-w,-w), (-w,-w,-w), (-w, w,-w) ]

cubeFrame :: GLfloat -> IO ()
cubeFrame w = renderPrimitive Lines $ mapM_ vertex3f
  [ ( w,-w, w), ( w, w, w),  ( w, w, w), (-w, w, w),
    (-w, w, w), (-w,-w, w),  (-w,-w, w), ( w,-w, w),
    ( w,-w, w), ( w,-w,-w),  ( w, w, w), ( w, w,-w),
    (-w, w, w), (-w, w,-w),  (-w,-w, w), (-w,-w,-w),
    ( w,-w,-w), ( w, w,-w),  ( w, w,-w), (-w, w,-w),
    (-w, w,-w), (-w,-w,-w),  (-w,-w,-w), ( w,-w,-w) ]

displayCubes :: IORef GLfloat -> IORef (GLfloat, GLfloat) -> IO ()
displayCubes angle pos = do
  (x', y') <- get pos
  translate $ Vector3 x' y' 0
  preservingMatrix $ do
    a <- get angle
    rotate a $ Vector3 0 0 1
    rotate a $ Vector3 0 0.1 1
    scale 0.7 0.7 (0.7 :: GLfloat)
    forM_ (points 7) $ \(x, y, z) ->
      preservingMatrix $ do
        color $ Color3 ((x + 1) / 2) ((y + 1) / 2) ((z + 1) / 2)
        translate $ Vector3 x y z
        cube 0.1
        color $ Color3 (0 :: GLfloat) 0 0 -- set outline color to black
        cubeFrame 0.1 -- draw the outline
