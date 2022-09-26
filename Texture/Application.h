///@file Application.h
///@brief Application
///@author Jeremie Perreault 1751707@etu.cegep-lanaudiere.qc.ca

#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "SDLEvent.h"
#include "Window.h"
#include "GLContext.h"

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
            glcontext.refresh();
        }
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
