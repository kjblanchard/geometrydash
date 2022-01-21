  ////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
namespace SG
{
	/**
	 * \brief Has a X and a Y integer that can be used for many things.
	 */
	struct Point
	{
		Point()
			:X(0), Y(0)
		{

		}
		Point(int xy): X(xy), Y(xy)
		{
		}

		Point(int x, int y)
			:X(x), Y(y)
		{

		}
		Point operator * (int mult)
		{
			return Point(X * mult, Y * mult);
		}
		int X;
		int Y;
	};

	inline Point operator+(const Point &lhs, const Point &rhs)
	{
		auto sum = lhs;
		sum.X += rhs.X;
		sum.Y += rhs.Y;
		return sum;
	}
}
