////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <vector>
#include <sgengine/core/Component.hpp>
#include <sgengine/core/Point.hpp>
#include <sgengine/interfaces/IUpdate.hpp>


namespace SG
{
	class SpriteBatch;
	struct Component;

	/// <summary>
	/// The different types of GameObjects inside of the game
	/// </summary>
	enum class GameObjectTypes
	{
		Default,
		Tile,
		SolidTile,
		Enemy,
		Player
	};

	/// <summary>
	/// Class that is likely inherited by any player or enemy in the game.  Is a IUpdate interface
	/// </summary>
	class GameObject : public IUpdate
	{
	public:

		/// <summary>
		/// This constructor shouldn't really be used, defaults to 0,0 location
		/// </summary>
		GameObject();
		/// <summary>
		/// Base class for tons of things
		/// </summary>
		/// <param name="location">Vector3 of the initial location</param>
		/// <param name="gameObjectType">The type of gameobject this is</param>
		GameObject(Point location, GameObjectTypes gameObjectType = GameObjectTypes::Default);
		virtual ~GameObject() = default;

		/// <summary>
		/// This function should be called only once, and should do most of the "work" of initializing after the constructor
		/// </summary>
		void Startup() override {};

		/// <summary>
		/// This is to be called once every frame, even if the game is lagging this will still be called as much as possible (60 times per second)
		/// </summary>
		/// <param name="deltaTime">The current time between frames, usually 16.6667, passed in from the current level</param>
		void Update(const double& deltaTime) override {};

		/// <summary>
		/// This will draw something to the screen, make sure to add to the spritebatch
		/// </summary>
		/// <param name="spriteBatch">Reference to a spritebatch, likely passed from the game level</param>
		void Draw(SpriteBatch& spriteBatch ) override {};

		/// <summary>
		/// Should be ran to bring things to the default on this object, if you don't want to delete it
		/// </summary>
		virtual void Reset() {};

		/// <summary>
		/// Gets the should update value
		/// </summary>
		/// <returns>If this game object should run its update function</returns>
		bool ShouldUpdate() const { return _shouldUpdate; };

		/// <summary>
		/// Each ID should be unique, and added to every game object
		/// </summary>
		uint16_t Id;

		GameObject* ReturnItself() { return this; }

		GameObjectTypes GameObjectType;

		//TODO Fix this up
		/// <summary>
		/// Gets the first component of the type that you pass in, This is an expensive operation and can potentially fail on things like animation controllers
		/// </summary>
		/// <typeparam name="T">Should be a component type if you want to get anything back</typeparam>
		/// <returns>The component that you searched for if it exists, else a null ptr</returns>
		template <typename T >
		T* GetComponent();
		/// <summary>
		/// Not as useful as the template, as you'll need to cast this to what you want after you get it back, and it only retrieves from the component types built in
		/// </summary>
		/// <param name="componentType"></param>
		/// <returns></returns>
		Component* GetComponent(SGComponentTypes componentType);

		/// <summary>
		/// Adds a component to the list of components on this gameobject
		/// </summary>
		/// <param name="component">Pointer to a component</param>
		void AddComponent(Component* component) { _components.push_back(component); };

		/// <summary>
		/// Returns the location of the gameobject.
		/// </summary>
		/// <returns>Returns the location in a vector3.  Z is used in the draw order</returns>
		Point Location() const { return _location; };

	protected:

		/// <summary>
		/// Space saver, you should put this in your update function and call the update function on all of your components
		/// </summary>
		/// <param name="deltaTime">Delta time from the update function</param>
		virtual void ComponentUpdate(const double& deltaTime) {};

		inline static unsigned int GameObjectCount = 0;

		Point _location;
		bool _shouldUpdate = true;
		std::vector<Component*> _components;

	};

	template <typename T>
	T* GameObject::GetComponent()
	{
		for (auto*  component : _components)
		{
			auto result = dynamic_cast<T*> (component);
			if (result)
				return result;
		}
		return nullptr;
	}

}
