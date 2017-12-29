module Map
  ( displayMap
  , _tiles
  , printActiveTile
  ) where

import           Control.Monad
import           Cube                      (vertex3f)
import           Data.IORef
import           Graphics.Rendering.OpenGL
import           Graphics.UI.GLUT
import           Numeric
import           Points

_tiles = [genTerrain x y | x <- [0 .. 100], y <- [0 .. 100]]

displayMap :: IORef (GLfloat, GLfloat) -> IORef GLfloat -> IO ()
displayMap pos invCount = do
  scale 10 10 (1 :: GLfloat)
  (x', y') <- get pos
  mapM_ (updateInv invCount x' y') _tiles
  translate $ Vector3 (-x') (-y') 0
  mapM_ drawTile _tiles

genTerrain :: GLfloat -> GLfloat -> Tile
genTerrain x y =
  let x' = ((x - 50.0) / 50.0) :: GLfloat
      y' = ((y - 50.0) / 50.0) :: GLfloat
  in if x > 50 && x < 55 && y > 50 && y < 55
       then Tile x' y' (Color3 (0 :: GLfloat) 0 1)
       else Tile x' y' (Color3 (0 :: GLfloat) 1 0)

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

-- this does not belong here
updateInv :: IORef GLfloat -> GLfloat -> GLfloat -> Tile -> IO ()
updateInv inv playerPosX playerPosY tile =
  when (isActiveTile playerPosX playerPosY tile) $ inv $~! (+ 1.0)

floatPrecision = Just 3
-- this does not belong here either
printActiveTile :: IORef (GLfloat, GLfloat) -> IO ()
printActiveTile pos = do
  (x, y) <- get pos
  putStrLn ("\nplayer -> " ++ (showFFloat floatPrecision x ", ") ++ (showFFloat floatPrecision y ""))
  mapM_ (\tile -> when (isActiveTile x y tile) $ putStrLn ("  tile -> " ++ (showFFloat floatPrecision (xPos tile) ", ") ++ showFFloat floatPrecision (yPos tile) " ")) _tiles

closenessTolerance = 0.01 :: GLfloat
isActiveTile :: GLfloat -> GLfloat -> Tile -> Bool
isActiveTile playerPosX playerPosY tile =
  let withinX = abs (playerPosX - (xPos tile)) < closenessTolerance
      withinY = abs (playerPosY - (yPos tile)) < closenessTolerance
      isOreTile = color3 tile == Color3 (0 :: GLfloat) 0 1
  in withinX && withinY && isOreTile
