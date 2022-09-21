#pragma once
#include "Window.h"
#include <SDL2/SDL_opengl.h>
#include "Matrix44d.hpp"

using namespace std;

class GLContext : public Window
{
private:
    SDL_GLContext glContext;
    Matrix44d projectionMatrix;
public:
    void clear(){
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void refresh(){ 
        SDL_GL_SwapWindow(sdlWindow);
    }
    void draw(){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMultMatrixd(projectionMatrix.elements);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glBegin(GL_QUADS);
            glColor4d(1.0, 0.0, 0.0, 1.0);
            glVertex3d(25.0, 25.0, 0.0);
            glVertex3d(125.0, 25.0 , 0.0);
            glVertex3d(125.0, 125.0, 0.0);
            glVertex3d(25.0, 125.0, 0.0);
        glEnd();
    }
    GLContext(const char* name = "", int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED ,
     int w = 640, int h = 480, unsigned int Wflags = 0)
     : Window(name, x , y , w, h, Wflags | SDL_WINDOW_OPENGL){
        glContext = SDL_GL_CreateContext(sdlWindow);
        projectionMatrix.loadOrthographic(w, h);
    };
    ~GLContext(){
        SDL_GL_DeleteContext(glContext);
    };
};

