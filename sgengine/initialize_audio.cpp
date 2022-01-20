#include "fmod_studio.hpp"
#include "fmod.hpp"
#include <iostream>


void destroy()
{
    FMOD::Studio::System* system;
    auto result = FMOD::Studio::System::create(&system);
    std::cout << result;

    system->initialize(4,FMOD_INIT_NORMAL,FMOD_INIT_NORMAL,nullptr);
    result = system->update();

}