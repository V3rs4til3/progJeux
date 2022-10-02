///\file SDLEvent.h
///\brief Conteneur d'information d'evenement
///\author Jeremie Perreault (1751707@etu.cegep-lanaudiere.qc.ca)

#pragma once
#include <SDL2/SDL.h>


///\class SDLEvent
///\brief Classe permettant d'obtenir l'information d'evenement
class SDLEvent
{
private:
    static SDL_Event sdlEvent; ///< Conteneur d'information d'evenement
public:
    ///\brief Obtention des informations du prochain evenement
    ///\return Le nombre d'evenement restant dans la file
    static int poll(){
        return SDL_PollEvent(&sdlEvent);
    };
    ///\brief Obtention du type d'evenement
    ///\return Le type d'evenement
    static unsigned int GetType(){
        return sdlEvent.type;
    };
};

SDL_Event SDLEvent::sdlEvent;

