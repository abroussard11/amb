/**
 * The Main program. This is what actually runs when you call ./build/AmbGames
 */

#include <iostream>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include <Menus/MainMenu.h>
//#include <Minigames/MadLib/MadLibMinigame.h>
//#include <Minigames/ProjectEuler/ProjectEulerGame.h>
#include <Minigames/X2048/X2048Minigame.h>

using namespace Minigames;

int main()
{
   sf::RenderWindow window(sf::VideoMode(700, 988), "AmbGames!");

    Menus::MainMenu _mainMenu;

    ////////////////////////////////////////
    /// Main loop
    ////////////////////////////////////////
   while (window.isOpen())
   {
      sf::Event event;
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
         {
            window.close();
         }
         else
         {
            _mainMenu.processEvent(event);
         }

         if (_mainMenu.isGameSelected())
         {
            window.close();
            _mainMenu.getSelectedGame()->play();
            window.create(sf::VideoMode(700, 988), "AmbGames!");
         }
         else
         {
            window.clear();
            window.draw(_mainMenu);
            window.display();
         }
      }
   }

} // End of main routine
