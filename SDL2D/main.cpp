#include "GLContext.h"
#include "SDLRenderer.h"
#include "Application.h"

int main(int argc, char* argv[]) {
    Application* app = new Application();

    app->addWindow(new SDLRenderer());                   
 
    app->addWindow(new GLContext());
    app->start();
    return 0;
}