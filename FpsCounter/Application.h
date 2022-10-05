///@file Application.h
///@brief Application
///@author Jeremie Perreault 1751707@etu.cegep-lanaudiere.qc.ca

#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "SDLEvent.h"
#include "Window.h"
#include "GLContext.h"
#include "Texture.hpp"
#include "Chrono.hpp"

using namespace std;

/// @class Application
/// @brief Classe permettant de gerer l'application
class Application
{
private:
    static Application instance;
    GLContext glcontext; ///< Fenetres de l'application
public:
    /// @brief 
    
    static Application& getInstance(){
        return instance;
    }

    void start(){
        Texture* laTexture = new Texture("bricks.png");
        TTFont* laFont = new TTFont("CreepyPumkin.ttf", 20);
        Texture* textureFont = new Texture(laFont->renderText("Hello World!", {250, 0, 0, 250}));

        bool isUp = true;
        while (isUp){
            //gestion des evenments
            while (SDLEvent::poll()){
                switch (SDLEvent::GetType()){
                    case SDL_QUIT:
                        isUp = false;
                        break;
                }
            }
            //gestion de l'affichage
            glcontext.clear();
            glcontext.draw();
            //glcontext.drawTexture(laTexture, 0, 0, 400, 200);
            glcontext.drawTexture(textureFont, 0, 0,textureFont->getHeigth() , textureFont->getWitdh());
            glcontext.refresh();
        }
        delete laTexture;
        delete laFont;
        delete textureFont;
    }
    Application(){
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG);
        TTF_Init();
    };
    ~Application(){   
        SDL_Quit();
        IMG_Quit();
        TTF_Quit();
        
    };
};

Application Application::instance;