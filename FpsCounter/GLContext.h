#pragma once
#include "Window.h"
#include <SDL2/SDL_opengl.h>
#include "Matrix44d.hpp"
#include "TTFont.hpp"
#include "Texture.hpp"

using namespace std;

class GLContext : public Window
{
private:
    SDL_GLContext glContext;
    Matrix44d projectionMatrix;
    unsigned int textureId;
    int width, height;
    TTF_Font* font;
public:
    void clear(){
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void refresh(){ 
        SDL_GL_SwapWindow(sdlWindow);
    }

    void drawTexture(Texture* laTexture, int x, int y, int w, int h){
        glBindTexture(GL_TEXTURE_2D, laTexture->getTextureID());
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex2f(x, y);
            glTexCoord2f(1, 0); glVertex2f(x + w, y);
            glTexCoord2f(1, 1); glVertex2f(x + w, y + h);
            glTexCoord2f(0, 1); glVertex2f(x, y + h);
        glEnd();
    }

    void draw(){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMultMatrixd(projectionMatrix.elements);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        glBegin(GL_QUADS);
            glTexCoord2d(0.0, 0.0); glVertex3d(0.0, 0.0, 0.0);
            glTexCoord2d(1.0, 0.0); glVertex3d(400, 0.0, 0.0);
            glTexCoord2d(1.0, 1.0); glVertex3d(400, 200, 0.0);
            glTexCoord2d(0.0, 1.0); glVertex3d(0.0, 200, 0.0);

        glEnd();
    }
    GLContext(const char* name = "", int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED ,
     int w = 640, int h = 480, unsigned int Wflags = 0)
     : Window(name, x , y , w, h, Wflags | SDL_WINDOW_OPENGL){
        glContext = SDL_GL_CreateContext(sdlWindow);
        projectionMatrix.loadOrthographic(w, h);

        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

        TTF_Init();
        //SDL_Surface* sdlSurface =  IMG_Load("wow.png");
        Texture* texture = new Texture("wow.png");
        //font = TTF_OpenFont("SideLove.ttf", 42);
        

    };
    ~GLContext(){
        //delete fpsFont;
        SDL_GL_DeleteContext(glContext);
        glDeleteTextures(1,&textureId);
    };
};

