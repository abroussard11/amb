module Player
  ( displayPlayer
  ) where

import           Graphics.UI.GLUT
import           Points

playerScale :: GLfloat
playerScale = 0.05

-- Player is just a silly orange polygon for now :)
displayPlayer :: IO ()
displayPlayer = do
  scale playerScale playerScale playerScale
  color $ Color3 (1 :: GLfloat) 0 0
  renderPrimitive Polygon $
    mapM_ (\(x, y, z) -> vertex $ Vertex3 x y z) (points 10)
