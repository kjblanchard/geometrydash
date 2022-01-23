////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <sgengine/core/StateMachine.hpp>

namespace SG
{
	/// <summary>
	/// This interface brings in a StateMachine, a change state function, and an abstract GenerateStates function
	/// </summary>
	/// <typeparam name="T">The Enum that will be used for all the states ex. "LinkStates"</typeparam>
	template <class T>
	class IObjectStateMachine

	{
	public:
		virtual ~IObjectStateMachine() = default;

	protected:
		/// <summary>
		/// This should be used for adding in all the gamestates for this object at startup, must be implemented
		/// </summary>
		virtual void GenerateStates() = 0;
		/// <summary>
		/// Changes the state to the referenced state
		/// </summary>
		/// <param name="stateToChangeTo">The state to change to</param>
		void ChangeState(T stateToChangeTo) const { _objectStateMachine->ChangeState(stateToChangeTo); }
		/// <summary>
		/// The StatMmachine used by the inheriting class
		/// </summary>
		SG::StateMachine<T>* _objectStateMachine = new SG::StateMachine<T>;
	};
}
