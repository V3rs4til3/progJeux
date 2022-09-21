#pragma once
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_opengl.h>
#include <string>

using namespace std;

class GLContext : public Window
{
private:
    SDL_GLContext glContext;
public:
    void clear(){
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void refresh(){ 
        SDL_GL_SwapWindow(sdlWindow);
    }
    GLContext(const char* name = "", int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED ,
     int w = 640, int h = 480, unsigned int Wflags = 0)
     : Window(name, x , y , w, h, Wflags){
        glContext = SDL_GL_CreateContext(sdlWindow);
    };
    ~GLContext(){
        SDL_GL_DeleteContext(glContext);
    };
};

