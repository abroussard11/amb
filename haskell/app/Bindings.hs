module Bindings
  ( display
  , idle
  , reshape
  , keyboardMouse
  ) where

import           Data.IORef
import           Display
import           Graphics.UI.GLUT

strideLength :: GLfloat
strideLength = 0.0125

reshape :: ReshapeCallback
reshape size = do
  viewport $= (Position 0 0, size)

keyboardMouse ::
     IORef GLfloat -> IORef (GLfloat, GLfloat) -> KeyboardMouseCallback
keyboardMouse a p key Down _ _ =
  case key of
    (Char ' ')            -> a $~! negate
    (Char '+')            -> a $~! (* 2)
    (Char '-')            -> a $~! (/ 2)
    (SpecialKey KeyLeft)  -> p $~! \(x, y) -> (x - strideLength, y)
    (SpecialKey KeyRight) -> p $~! \(x, y) -> (x + strideLength, y)
    (SpecialKey KeyUp)    -> p $~! \(x, y) -> (x, y + strideLength)
    (SpecialKey KeyDown)  -> p $~! \(x, y) -> (x, y - strideLength)
    _                     -> return ()
keyboardMouse _ _ _ _ _ _ = return ()
