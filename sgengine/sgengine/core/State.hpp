#pragma once

namespace SG
{
	class SpriteBatch;

	/// <summary>
	/// This abstract class has 4 functions that must be implemented, Startup Update Draw and End.  Handle input is also brought in
	/// </summary>
	class  State
	{

	public:
		virtual ~State() = default;
		virtual void Startup() = 0;
		virtual void Update(const double& deltaTime) = 0;
		virtual void Draw(SpriteBatch& spriteBatch) = 0;
		virtual void HandleInput();
		virtual void End() = 0 ;

	protected:

	};

	inline void State::HandleInput()
	{
	}
}
