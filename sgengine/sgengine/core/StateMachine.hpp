#pragma once
#include <map>
#include <memory>
#include <sgengine/core/State.hpp>



namespace SG
{
	/// <summary>
	/// Used to control changing between different states, used for many things
	/// </summary>
	/// <typeparam name="T">Should be an enum value used to switch between states and for the dictionary key</typeparam>
	template<typename T>
	class StateMachine
	{
	public:

		virtual ~StateMachine() = default;
		/// <summary>
		/// Adds a state to the dictionary
		/// </summary>
		/// <param name="enumKey">An enum used for retrieving the state for changing</param>
		/// <param name="state">The actual state for the dictionary value</param>
		void AddStateToGameStateList(T enumKey, std::unique_ptr<SG::State> state);
		/// <summary>
		/// Change to the state with the enum value
		/// </summary>
		/// <param name="stateToChangeTo">An enum value of the state you wish to change to</param>
		void ChangeState(T stateToChangeTo);
		/// <summary>
		/// Calls the update function on the current state
		/// </summary>
		/// <param name="deltaTime">Time in between frames</param>
		void Update(const double& deltaTime) const;
		/// <summary>
		/// Calls the draw function on the current state
		/// </summary>
		/// <param name="spritebatch">The spritebatch for the graphics</param>
		void Draw(SpriteBatch& spritebatch) const;
		/// <summary>
		/// Gets the current state in the state machine
		/// </summary>
		/// <returns>Current state</returns>
		State* CurrentState() const
		{
			return _currentState;

		}
		/// <summary>
		/// Gets the previous state in the state machine
		/// </summary>
		/// <returns>Previous state</returns>
		const State* PreviousState() const
		{
			return _previousState;
		}


	private:
		std::map<T, std::unique_ptr<SG::State>> _gameStates;
		State* _currentState = nullptr;
		State* _previousState = nullptr;

	};

	template <typename T>
	void StateMachine<T>::AddStateToGameStateList(T enumKey, std::unique_ptr<SG::State> state)
	{
		_gameStates.insert({ enumKey,std::move(state )});
	}


	template <typename T>
	void StateMachine<T>::ChangeState(T stateToChangeTo)
	{
		if (_currentState)
		{
			_currentState->End();
			_previousState = _currentState;
		}
		_currentState = _gameStates.at(stateToChangeTo).get();
		if (_currentState)
			_currentState->Startup();
	}

	template <typename T>
	void StateMachine<T>::Update(const double& deltaTime) const
	{
		if(_currentState)
			_currentState->Update(deltaTime);
	}

	template <typename T>
	void StateMachine<T>::Draw(SpriteBatch& spritebatch) const
	{
		_currentState->Draw(spritebatch);
	}

}
