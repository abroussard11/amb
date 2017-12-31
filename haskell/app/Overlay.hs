module Overlay
  ( displayOverlay
  ) where

import           Data.IORef
import           Graphics.UI.GLUT

depth = -0.2 :: GLfloat

hotbarWidth = 1.50 :: GLfloat

hotbarHeight = 0.2 :: GLfloat

hotbarSlotCount = 10 :: GLfloat

gap = 0.02 :: GLfloat

halfGap = gap / 2

slotWidth = hotbarWidth / hotbarSlotCount

slotHeight = hotbarHeight - gap

slotDepth = -0.1 :: GLfloat

minimapWidth = 0.2 :: GLfloat

minimapHeight = 0.2 :: GLfloat

hotbarVerteces =
  concat
    [ [ (x * slotWidth + halfGap, -slotHeight / 2, -0.01)
      , (x * slotWidth + halfGap, slotHeight / 2, -0.01)
      , ((x + 1) * slotWidth - halfGap, slotHeight / 2, -0.01)
      , ((x + 1) * slotWidth - halfGap, -slotHeight / 2, -0.01)
    ]
    | x <- [-5 .. 4]
    ]

gray = 0.5 :: GLfloat

lightGray = 0.6 :: GLfloat

displayOverlay :: IORef GLfloat -> IO ()
displayOverlay invCount = do
  inv <- get invCount
  preservingMatrix $ displayHotbar inv
  preservingMatrix displayMinimap

displayHotbar :: GLfloat -> IO ()
displayHotbar inv = do
  scale (1 :: GLfloat) 1 1
  color $ Color3 gray gray gray
    -- translate to the bottom of the screen
  translate $ Vector3 0.0 (-0.8) depth
    -- draw a rectangle
  renderPrimitive Polygon $ do
    vertex $ Vertex3 (-hotbarWidth / 2) (-hotbarHeight / 2) 0
    vertex $ Vertex3 (-hotbarWidth / 2) (hotbarHeight / 2) 0
    vertex $ Vertex3 (hotbarWidth / 2) (hotbarHeight / 2) 0
    vertex $ Vertex3 (hotbarWidth / 2) (-hotbarHeight / 2) 0
  color $ Color3 lightGray lightGray lightGray
  renderPrimitive Quads $
    mapM_ (\(x, y, z) -> vertex $ Vertex3 x y z) hotbarVerteces
    -- draw the hacky inventory count
  color $ Color3 0 0 (0 :: GLfloat)
  currentRasterPosition $= Vertex4 0 0 depth 1
  renderString Fixed8By13 $ show inv

displayMinimap :: IO ()
displayMinimap = do
  color $ Color3 1 1 (1 :: GLfloat)
  translate $ Vector3 0.75 0.75 depth
  renderPrimitive Polygon $ do
    vertex $ Vertex3 (-minimapWidth) (-minimapHeight) 0
    vertex $ Vertex3 (-minimapWidth) minimapHeight 0
    vertex $ Vertex3 minimapWidth minimapHeight 0
    vertex $ Vertex3 minimapWidth (-minimapHeight) 0
  color $ Color3 0 0 (0 :: GLfloat)
  currentRasterPosition $= Vertex4 0 0 depth 1
  renderString Fixed8By13 "Mini Map"
