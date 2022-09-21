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
   GLContext glcontext; ///< Fenetres de l'application
public:
    /// @brief 
    bool isUp = true;
    void start(){
        while (isUP){
            //gestion des evenments
            while (SDLEvent::poll()){
                case SDL_QUIT:
                    isUp = false;
                    break;
            }
            //gestion de l'affichage
            glcontext.clear();
            glcontext.refresh();
        }
    }
    Application(){
        SDL_Init(SDL_INIT_EVERYTHING);
    };
    ~Application(){   
        SDL_QUIT();
    };
};

