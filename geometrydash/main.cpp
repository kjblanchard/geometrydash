#include <iostream>
#include "SDL.h"
#include "initialize_audio.h"

int main()
{
    if (SDL_INIT_AUDIO)
        std::cout << "Initialized audio!    ";
    else
        std::cout << "Borked";

    std::cout << "Hello world!" << std::endl;
    destroy();
}