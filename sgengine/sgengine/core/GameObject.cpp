#include <sgengine/core/GameObject.hpp>


SG::GameObject::GameObject()
	: GameObjectType(GameObjectTypes::Default), _location{Point()}
{
	++GameObjectCount;
	Id = GameObjectCount;
}


SG::GameObject::GameObject(Point location, GameObjectTypes gameObjectType)
	: GameObjectType(gameObjectType), _location(location)
{
	++GameObjectCount;
	Id = GameObjectCount;
}

SG::Component* SG::GameObject::GetComponent(SGComponentTypes componentType)
{
	for (auto* component : _components)
	{
		if (component->ComponentType() == componentType)
			return component;
	}
	return nullptr;
}







