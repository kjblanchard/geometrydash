#include "fmod_studio.hpp"
#include "fmod.hpp"
#include <sgengine/core/World.hpp>
#include <sgengine/core/Point.hpp>

#include <iostream>

FMOD::Studio::System* destroy()
{
    FMOD::Studio::System *system = nullptr;
    auto result = FMOD::Studio::System::create(&system);
    FMOD::System *coreSystem = nullptr;
    system->getCoreSystem(&coreSystem);
    coreSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_STEREO, 0);
    system->initialize(1024, FMOD_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr);
    FMOD::Studio::Bank* mainBank = nullptr;
    result = system->loadBankFile("sfx/Master.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &mainBank);
    FMOD::Studio::Bank* stringsBank = nullptr;
    result = system->loadBankFile("sfx/Master.strings.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &mainBank);
    FMOD::Studio::EventDescription* loadedEventDescription = nullptr;
    result = system->getEvent("event:/main", &loadedEventDescription);
    FMOD::Studio::EventInstance* loadedEventInstance = nullptr;
    result = loadedEventDescription->createInstance(&loadedEventInstance);
    result = loadedEventInstance->start();
    std::cout << result;
    return system;
}