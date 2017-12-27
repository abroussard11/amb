module Main where

import           Bindings
import           Data.IORef
import           Graphics.UI.GLUT
import           Lib

main :: IO ()
main = do
  (_progName, _args) <- getArgsAndInitialize
  --mapM_ print _tiles
  initialDisplayMode $= [WithDepthBuffer, DoubleBuffered]
  _window <- createWindow "Hello World"
  windowSize $= Size (1080::GLsizei) (800::GLsizei)
  reshapeCallback $= Just reshape
  depthFunc $= Just Less
  angle <- newIORef 0
  delta <- newIORef 0.1
  pos <- newIORef (0, 0)
  keyboardMouseCallback $= Just (keyboardMouse delta pos)
  idleCallback $= Just (idle angle delta)
  displayCallback $= display angle pos
  mainLoop
