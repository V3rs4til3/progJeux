///@file SDLRenderer.h
///@brief Gestionnaire de rendu
///@author Jeremie Perreault 1751707@etu.cegep-lanaudiere.qc.ca

#pragma once
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <string>

using namespace std;

///@class SDLRenderer
///@brief Gestionnaire de rendu 2D
class SDLRenderer : public Window
{
private:
    SDL_Renderer* sdlRenderer; ///< Gestionnaire de rendu
public:
    void refresh(){
        SDL_RenderPresent(sdlRenderer);
    }
    void clear(){
        SDL_RenderClear(sdlRenderer);
    }
    /// @param name Titre de la fenetre
    /// @param x Position sur l'axe des x
    /// @param y Position sur l'axe des y
    /// @param w Largeur
    /// @param h Hauter
    /// @param Wflags Indicateurs de la fenetre
    /// @param index choix moteur grpahique
    /// @param Rflags Indicateurs du moteur graphique
    SDLRenderer(const char* name = "", int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED 
    , int w = 640, int h = 480, unsigned int Wflags = 0, int index = -1, unsigned int Rflags = 0)
    : Window(name, x, y , w, h, Wflags){
        sdlRenderer = SDL_CreateRenderer(sdlWindow, index, Rflags);
    };
    ~SDLRenderer(){
        SDL_DestroyRenderer(sdlRenderer);
    }
};
