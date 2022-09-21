#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  if(SDL_Init(SDL_INIT_EVERYTHING))
    cout << "necessite la librairie SDL2" << endl;

  SDL_Event sdlEvent;

  SDL_Window* sdlWindow = SDL_CreateWindow("Ma premiere fenetre", 
                                            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                             1024, 768,
                                             SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  SDL_Renderer* sdlRenderer = SDL_CreateRenderer(sdlWindow, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  //SDL_GLContext glContext = SDL_GL_CreateContext(sdlWindow);

  //glClear(GL_COLOR_BUFFER_BIT);
  //TODO : Draw
  //SDL_GL_SwapWindow(sdlWindow);
  bool isOpen = true;
  while (isOpen){
    //gestion des evenments
    while (SDL_PollEvent(&sdlEvent)){
        switch (sdlEvent.type){
          case SDL_QUIT:
            isOpen = false;
            break;
        }
      }

    //gestion des mises a jours
    SDL_RenderClear(sdlRenderer);
    //gestion de l'affichage
    SDL_RenderPresent(sdlRenderer);
  }

  SDL_DestroyRenderer(sdlRenderer);
  //SDL_GL_DeleteContext(glContext);
  SDL_DestroyWindow(sdlWindow);

  SDL_Quit();
  return 0;
}
