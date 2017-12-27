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
  if x > 50 && x < 55 && y > 50 && y < 55
    then IronOre ((x - 50.0) / 50.0) ((y - 50.0) / 50.0)
    else Grass ((x - 50.0) / 50.0) ((y - 50.0) / 50.0)

data Tile
  = Grass GLfloat
          GLfloat
  | IronOre GLfloat
            GLfloat
  deriving (Show)

drawTile :: Tile -> IO ()
drawTile (IronOre x y) =
  preservingMatrix $ do
    color $ Color3 (0 :: GLfloat) 0 1
    renderPrimitive Polygon $ drawRectangle x y 0.1
    color $ Color3 (0 :: GLfloat) 0 0
    renderPrimitive LineLoop $ drawRectangle x y 0.09
drawTile (Grass x y) =
  preservingMatrix $ do
    color $ Color3 (0 :: GLfloat) 1 0
    renderPrimitive Polygon $ drawRectangle x y 0.1
    color $ Color3 (0 :: GLfloat) 0 0
    renderPrimitive LineLoop $ drawRectangle x y 0.09

drawRectangle :: GLfloat -> GLfloat -> GLfloat -> IO ()
drawRectangle x y z = do
  vertex $ Vertex3 (x - 0.01) (y - 0.01) z
  vertex $ Vertex3 (x - 0.01) (y + 0.01) z
  vertex $ Vertex3 (x + 0.01) (y + 0.01) z
  vertex $ Vertex3 (x + 0.01) (y - 0.01) z
