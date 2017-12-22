module Display
  ( display
  , idle
  ) where

import           Control.Monad
import           Cube
import           Data.IORef
import           Graphics.UI.GLUT
import Map
import           Player
import           Points

display :: IORef GLfloat -> IORef (GLfloat, GLfloat) -> DisplayCallback
display angle pos = do
  clear [ColorBuffer, DepthBuffer]
  clear [ColorBuffer]
  loadIdentity
  preservingMatrix $ displayMap pos
  preservingMatrix displayPlayer
  --preservingMatrix $ displayCubes angle pos -- this is leftover from the openGL tutorial
  swapBuffers

idle :: IORef GLfloat -> IORef GLfloat -> IdleCallback
idle angle delta = do
  d <- get delta
  angle $~! (+ d)
  postRedisplay Nothing
