module Map
  ( displayMap
  , _tiles
  ) where

import           Cube                      (vertex3f)
import           Data.IORef
import           Graphics.Rendering.OpenGL
import           Graphics.UI.GLUT
import           Points

_tiles = [genTerrain x y | x <- [0 .. 100], y <- [0 .. 100]]

displayMap :: IORef (GLfloat, GLfloat) -> IO ()
displayMap pos = do
  scale 10 10 (1 :: GLfloat)
  (x', y') <- get pos
  translate $ Vector3 (-x') (-y') 0
  mapM_ drawTile _tiles

genTerrain :: GLfloat -> GLfloat -> Tile
genTerrain x y =
  let x' :: GLfloat
      y' :: GLfloat
      x' = ((x - 50.0) / 50.0)
      y' = ((y - 50.0) / 50.0)
  in if x > 50 && x < 55 && y > 50 && y < 55
       then Tile xPos yPos (Color3 (0 :: GLfloat) 0 1)
       else Tile xPos yPos (Color3 (0 :: GLfloat) 1 0)

data Tile = Tile
  { xPos   :: GLfloat
  , yPos   :: GLfloat
  , color3 :: Color3 GLfloat
  } deriving (Show)

drawTile :: Tile -> IO ()
drawTile tile =
  preservingMatrix $ do
    color $ color3 tile
    renderPrimitive Polygon $ drawRectangle x y 0.1
    color $ Color3 (0 :: GLfloat) 0 0
    renderPrimitive LineLoop $ drawRectangle x y 0.09
  where
    x = xPos tile
    y = yPos tile

drawRectangle :: GLfloat -> GLfloat -> GLfloat -> IO ()
drawRectangle x y z = do
  vertex $ Vertex3 (x - 0.01) (y - 0.01) z
  vertex $ Vertex3 (x - 0.01) (y + 0.01) z
  vertex $ Vertex3 (x + 0.01) (y + 0.01) z
  vertex $ Vertex3 (x + 0.01) (y - 0.01) z
