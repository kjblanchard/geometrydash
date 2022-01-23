////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <memory>
#include <SDL_video.h>
#include <sgengine/core/sound.hpp>

namespace SG
{
	class Sound;
	class GameObjectList;
	class GameObject;
	class Input;
	class Graphics;
	class GameClock;

	/**
	 * \brief This class is used to perform the main game loop, and initialize the proper components needed to initialize the game.  Also currently has a FPS counter in it.
	 */
	class World
	{

	public:
		World();
		virtual ~World();

		/**
		 * \brief Used to initialize the proper components to start the game, this is ran after the constructor and prior to the loop being called.
		 * \return Returns true if things were initialized successfully
		 */
		bool SetupWorldComponents() ;
		/**
		 * \brief Main Game loop, this is called by the main function when the program is started.
		 */
		void Loop();
		/**
		 * @brief Gets the current instance of the world.
		 * 
		 * @return World* To the world
		 */
		static World *GetWorld() { return _instance; }
		/**
		 * @brief Get the Graphics object
		 * 
		 * @return Graphics* 
		 */
		static Graphics *GetGraphics() { return _graphics.get(); }

		static FMOD::Studio::System *_sound;
		/**
		 * @brief The master switch for showing collision debug boxes, you can flip this to override any of the other debug settings.
		 * 
		 */
		inline static bool _isCollisionDebug = true;

	protected:
		/**
		 * \brief Game window,  we can use a Raw pointer here, as this has built in destroy functionality that we will put in the Game destructor
		 */
		SDL_Window *_gameWindow;
		std::unique_ptr<GameClock> _gameClock;

		bool shouldQuit{};
		static std::unique_ptr<Graphics> _graphics;
		static World *_instance;
		std::unique_ptr<Input> _input;

	private:
		/**
		 * \brief Checks the event queue, and if there are any quit events (like from clicking the X) the game will quit.
		 */
		bool HandleEvents();

		/**
		 * \brief Handles the Input for everything that needs their input handled.
		 */
		void HandleInput();

		virtual void Startup() = 0;

		bool InitializeSdl();
		bool InitializeFmod();

		/**
		 * \brief This will run the update function for all game objects
		 * \param deltaTime Milliseconds that have passed since the last frame
		 */
		virtual void Update(const double &deltaTime) = 0;
		/**
		 * \brief This will run the draw function for all game objects.
		 */
		virtual void Draw() = 0;


	};

};
