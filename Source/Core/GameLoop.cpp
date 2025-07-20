#include "../../Header/Core/GameLoop.h"

namespace Core
{
    void GameWindowManager::initialize()
    {
        game_window = new RenderWindow();

        createGameWindow();
    }

    void GameWindowManager::createGameWindow()
    {
        game_window->create(VideoMode(game_window_width, game_window_height), game_title);
    }

    RenderWindow* GameWindowManager::getGameWindow()
    {
        return game_window;
    }

    bool GameWindowManager::isGameRunning()
    {
        return game_window->isOpen();
    }

    void GameWindowManager::clearGameWindow()
    {
        game_window->clear();
    }

    void GameWindowManager::displayGameWindow()
    {
        return game_window->display();
    }

    void GameLoop::initialize()
    {
        //other objects
        gameplay_manager = new GameplayManager();
    }

    void GameLoop::render()
    {
        game_window_manager->clearGameWindow();
        //render the paddles and ball
        gameplay_manager->render(game_window_manager->getGameWindow());

        game_window_manager->displayGameWindow();
    }
}