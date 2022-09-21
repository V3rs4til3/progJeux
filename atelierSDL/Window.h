///@file Window.h
///@brief Fenetre du systeme d'exploitation
///@author Jeremie Perreault (1751707@etu.cegep-lanaudiere.qc.ca)

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

///@class Window
///@brief Classe representant une fenetre du systeme d'exploitation
class Window
{
protected:
    SDL_Window* sdlWindow; ///< Fenetre
public:

    /// @brief rafraichit la fenetre
    virtual void refresh() = 0;

    /// @brief Vide le contenue de la fenetre
    virtual void clear() = 0;

    /// @brief Obtention de l'identifiant de la fenetre
    /// @return Identifiant
    unsigned int getId(){
        return SDL_GetWindowID(sdlWindow);
    }

    /// @param name Titre de la fenetre
    /// @param x Position sur l'axe des x
    /// @param y Position sur l'axe des y
    /// @param w Largeur
    /// @param h Hauter
    /// @param Wflags Indicateurs
    Window(const char* name = "", int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED ,
     int w = 640, int h = 480, unsigned int Wflags = 0){
        sdlWindow = SDL_CreateWindow(name, x , y , w, h, Wflags);
    }  
    virtual ~Window(){
        SDL_DestroyWindow(sdlWindow);
    }
};



