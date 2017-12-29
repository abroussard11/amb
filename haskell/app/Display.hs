module Display
  ( display
  , idle
  , printActiveTile
  ) where

import           Control.Monad
import           Cube
import           Data.IORef
import           Graphics.UI.GLUT
import           Map
import           Player
import           Points
import           Overlay

display :: IORef GLfloat -> IORef (GLfloat, GLfloat) -> IORef GLfloat -> DisplayCallback
display angle pos invCount = do
  clear [ColorBuffer, DepthBuffer]
  clear [ColorBuffer]
  loadIdentity
  preservingMatrix $ displayMap pos invCount
  preservingMatrix $ displayPlayer
  preservingMatrix $ displayOverlay invCount
  swapBuffers

idle :: IORef GLfloat -> IORef GLfloat -> IdleCallback
idle angle delta = do
  d <- get delta
  angle $~! (+ d)
  postRedisplay Nothing
