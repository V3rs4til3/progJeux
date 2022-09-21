///@file Application.h
///@brief Application
///@author Jeremie Perreault 1751707@etu.cegep-lanaudiere.qc.ca

#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "SDLEvent.h"
#include "Window.h"
#include <map>

using namespace std;

/// @class Application
/// @brief Classe permettant de gerer l'application
class Application
{
private:
    map<unsigned int,Window*> windows; ///< Fenetres de l'application
public:
    /// @brief 
    /// @param window 
    void addWindow(Window* window){
        windows[window->getId()] = window;
    }
    /// @brief 
    void start(){
        while (windows.size()){
            //gestion des evenments
            while (SDLEvent::poll()){
                switch (SDLEvent::GetType()){
                    case SDL_WINDOWEVENT:
                        switch(SDLEvent::GetWindowEventType()){
                            case SDL_WINDOWEVENT_CLOSE :
                                delete windows[SDLEvent::GetWindowId()];
                                windows.erase(SDLEvent::GetWindowId());
                                break;
                        }
                        break;
                    }
            }
           for(auto w : windows){
                w.second->clear();
                w.second->refresh();
           }
        }
    }
    Application(){
        SDL_Init(SDL_INIT_EVERYTHING);
    };
    ~Application(){
        for(auto w : windows){
           delete w.second;
        }
        windows.clear();
       
        SDL_QUIT;
    };
};

