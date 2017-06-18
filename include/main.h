#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "window.h"
#include "sprite.h"
#include "utility.h"
#include "texture.h"
#include "timer.h"
#include "defines.h"

#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

class BoulderDash
{
    public:
        // Needs to be 640x480 by default
        BoulderDash(std::string title, int width, int height);

        // Deallocates memory
        ~BoulderDash();

        // Update the game model
        void Update();

        // Render the game model
        void Render();

        // Render the main menu
        void RenderMainMenu();

        // Render necessary text
        void RenderText();

        // Handle user input
        bool HandleInput(SDL_Event &event);

        // Load a map file
        void LoadNextCave();

        // Game main loop
        void MainLoop();

        // Load the playlist
        void LoadPlaylist();

        // Process intent for moveable game objects
        void ProcessIntent(Boulder* o, Direction d);
        void ProcessIntent(Coin* o, Direction d);
        void ProcessIntent(Player* o, Direction d);
        void ProcessIntent(Amoeba* o, Direction d);
        void ProcessIntent(Butterfly* o, Direction d);
        void ProcessIntent(Firefly* o, Direction d);

        // Check whether a tile is occupied
        Sprite* GetTile(int x, int y);

        // Check whether a sprite is a solid object
        bool IsSolid(Sprite* s);

        // Remove a game object
        void RemoveGameObject(Sprite* s);

    private:
        // Pointer to the game window
        Window* m_window = nullptr;

        // Pointer to the timer
        Timer* m_gametimer = nullptr;

        // Pointer to cave timer
        Timer* m_cavetimer = nullptr;

        // Pointer to the texture sheet
        TextureSheet m_sprites;

        // Pointer to the text sheet
        TextureSheet m_text;

        // All game objects for currently loaded cave
        std::vector<Sprite*> m_objects;

        // Keep seperate references to the player and the exit
        // when loading cave data/symbols
        Player* m_player;
        Exit* m_exit;

        // Quit boolean for game
        bool m_quit = false;

        // Bool for main menu
        bool m_mainMenu = true;

        // Check whether a cave is loaded
        bool m_caveLoaded = false;

        // Width and height of tiles
        int m_cw;
        int m_ch;

        // Player score
        int m_totalScore;

        // Coins collected;
        int m_coinsCollected;

        // Required coins to leave cave
        int m_requiredCoins;

        // Cave time
        int m_timeInCave;

        // Boolean to test if map is closed or open
        bool m_isMapOpen;

        // Boolean to test if player is at the exit
        bool m_isPlayerExit;

        // Save key-press states
        std::map<int, bool> m_keyboard;

        // Caves in current playlist
        std::vector<Cave> m_caves;

        // Coordinates where the player spawned
        Coordinates m_spawncoords;

        // Index of the current cave into m_caves
        int m_currentcave;

        //  Number of lives the player has
        int m_lives;
};

#endif // MAIN_H
