module Overlay
  ( displayOverlay
  ) where

import       Graphics.UI.GLUT
import           Data.IORef

depth = -0.2 :: GLfloat

hotbarWidth = 0.5 :: GLfloat
hotbarHeight = 0.1 :: GLfloat
minimapWidth = 0.2 :: GLfloat
minimapHeight = 0.2 :: GLfloat

gray = 0.5 :: GLfloat

displayOverlay :: IORef GLfloat -> IO ()
displayOverlay invCount = do
    inv <- get invCount
    preservingMatrix $ displayHotbar inv
    preservingMatrix $ displayMinimap

displayHotbar :: GLfloat -> IO ()
displayHotbar inv = do
    scale (1::GLfloat) 1 1
    color $ Color3 gray gray gray
    -- translate to the bottom of the screen
    translate $ Vector3 0.0 (-0.8) depth
    -- draw a rectangle
    renderPrimitive Polygon $ do
        vertex $ Vertex3 (-hotbarWidth) (-hotbarHeight) 0
        vertex $ Vertex3 (-hotbarWidth) hotbarHeight 0
        vertex $ Vertex3 hotbarWidth hotbarHeight 0
        vertex $ Vertex3 hotbarWidth (-hotbarHeight) 0
    -- draw the hacky inventory count
    color $ Color3 0 0 (0::GLfloat)
    currentRasterPosition $= Vertex4 0 0 depth 1
    renderString Fixed8By13 $ show inv

displayMinimap :: IO ()
displayMinimap = do
    color $ Color3 1 1 (1::GLfloat)
    translate $ Vector3 0.75 0.75 depth
    renderPrimitive Polygon $ do
        vertex $ Vertex3 (-minimapWidth) (-minimapHeight) 0
        vertex $ Vertex3 (-minimapWidth) minimapHeight 0
        vertex $ Vertex3 minimapWidth minimapHeight 0
        vertex $ Vertex3 minimapWidth (-minimapHeight) 0
    color $ Color3 0 0 (0::GLfloat)
    currentRasterPosition $= Vertex4 0 0 depth 1
    renderString Fixed8By13 $ "Mini Map"

