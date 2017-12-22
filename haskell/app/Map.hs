module Map
  ( displayMap
  ) where

import           Cube                      (vertex3f)
import           Graphics.Rendering.OpenGL
import           Graphics.UI.GLUT
import           Points

gridline :: Float -> Int -> [(GLfloat, GLfloat, GLfloat)]
gridline k n =
  [ (offset k, -1.0, 0.0)
  , (offset k, 1.0, 0.0)
  , (-1.0, offset k, 0.0)
  , (1.0, offset k, 0.0)
  ]
  where
    offset k' = ((2 * k') / n') - 1.0
    n' = fromIntegral n

gridlines :: Int -> Int -> [(GLfloat, GLfloat, GLfloat)]
gridlines 0 n = gridline 0 n
gridlines k n = gridline (fromIntegral k) n ++ gridlines (k - 1) n

displayMap :: IO ()
displayMap = do
  color $ Color3 (0 :: GLfloat) 1 0
  renderPrimitive Polygon $ do
    vertex $ Vertex3 (-1 :: GLfloat) (-1 :: GLfloat) (0.1 :: GLfloat)
    vertex $ Vertex3 (-1 :: GLfloat) (1 :: GLfloat) (0.1 :: GLfloat)
    vertex $ Vertex3 (1 :: GLfloat) (1 :: GLfloat) (0.1 :: GLfloat)
    vertex $ Vertex3 (1 :: GLfloat) (-1 :: GLfloat) (0.1 :: GLfloat)
  color $ Color3 (0 :: GLfloat) 0 0
  renderPrimitive Lines $ mapM_ vertex3f (gridlines 10 10)
