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
            glcontext.refresh();
        }
    }
    Application(){
        SDL_Init(SDL_INIT_EVERYTHING);
    };
    ~Application(){   
        SDL_Quit();
    };
};

