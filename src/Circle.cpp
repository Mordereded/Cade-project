#pragma once
#include "Circle.hpp"

	Circle3D::Circle3D() : radius(0), Curvel("Curcle")
	{
	}
	explicit Circle3D::Circle3D(const double radius) : Curvel("Curcle")
	{
		try
		{

			if (radius > 0)
			{
				this->radius = radius;

			}
			else
			{
				throw std::runtime_error("Radius can not be negative");
			}

		}
		catch (std::runtime_error& error)
		{
			std::cout << error.what() << std::endl;
			std::cout << "Radius =" << 0;
			this->radius = 0;
		}
	}
	void Circle3D::Print()
	{
		std::cout << "\n[Name - " << this->GetName() << "]" << std::endl;
		std::cout << "[radius - " << radius << "]" << std::endl;
	}
	void Circle3D::SetRadius(int value)
	{
		this->radius = value;
	}
	double Circle3D::GetRadius()
	{
		return radius;
	}
	const Point& Circle3D::GetCurvePoint(const double t)
	{
		return Point
		(
			std::asin(t) * radius,
			std::sin(t) * radius,
			0
		);
	}
	const Point& Circle3D::GetDerivative(const double t)
	{
		return Point
		(
			-1 * radius * std::sin(t),
			radius * std::cos(t),
			0
		);
	}

};