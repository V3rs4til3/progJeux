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

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        
        
        TTF_Init();
        //SDL_Surface* sdlSurface =  IMG_Load("wow.png");
        font = TTF_OpenFont("SideLove.ttf", 42);
        SDL_Surface* sdlSurface = TTF_RenderText_Blended(font, "Hello World", {0, 255, 0, 255});
        
        unsigned int realPitch = sdlSurface->w * sdlSurface->format->BytesPerPixel;
        unsigned char* srcPointer = (unsigned char*)sdlSurface->pixels;
        unsigned char* dstPointer = srcPointer;
        for(size_t i = 0; i < sdlSurface->h; i++){
            memmove(dstPointer, srcPointer, realPitch);
            dstPointer += realPitch;
            srcPointer += sdlSurface->pitch;
        }
        sdlSurface->pitch = realPitch;

        #ifdef _APPLE_
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sdlSurface->w, sdlSurface->h,
                        0, GL_RGBA, GL_UNSIGNED_BYTE, sdlSurface->pixels);
        #else
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sdlSurface->w, sdlSurface->h,
                        0, GL_BGRA /*GL_RGBA*/, GL_UNSIGNED_BYTE, sdlSurface->pixels);
        #endif
        
        SDL_FreeSurface(sdlSurface);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    };
    ~GLContext(){
        TTF_CloseFont(font);
        SDL_GL_DeleteContext(glContext);
        glDeleteTextures(1,&textureId);
    };
};

