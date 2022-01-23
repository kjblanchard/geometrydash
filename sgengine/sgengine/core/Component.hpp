////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <sgengine/interfaces/IUpdate.hpp>

namespace SG
{
	class GameObject;

	/// <summary>
	/// The different component types in the gameengine
	/// </summary>
	enum class SGComponentTypes
	{
		Default,
		Image,
		Input,
		Animation,
		BoxCollider
	};

	/// <summary>
	/// The base class for all components, holds it's owner and it's component type, as well as a startup method
	/// </summary>
	struct Component : IUpdate
	{

		Component(GameObject* gameObject);
		Component(GameObject* gameObject, SGComponentTypes componentType);
		SGComponentTypes ComponentType() const { return _componentType; }
		virtual ~Component() = default;

	protected:
		GameObject* _gameObject;
		SGComponentTypes _componentType;
	};
}
