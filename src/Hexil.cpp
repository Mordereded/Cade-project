#pragma once
#include "Hexil.hpp"
Helix3D::Helix3D(): step(0), radius(0), Curvel("Helix")
{
}
Helix3D::Helix3D(int step, int radius) :step(step), Curvel("Helix")
{
	try
	{
		if (radius < 0)
		{
			throw std::runtime_error("Radius can't be negative");
		}
		this->radius = radius;
	}
	catch (std::runtime_error error)
	{
		std::cout << error.what() << std::endl;
		std::cout << "Radius =" << 0;
		this->radius = 0;
	}

}

void Helix3D::Print() 
{
	std::cout << "\n[Name - " << this->GetName() << "]" << std::endl;
	std::cout << "[step - " << step << "]" << std::endl;
	std::cout << "[radius - " << radius << "]" << std::endl;
}

const Point& Helix3D::GetCurvePoint(const double t) 
{
	return Point
	(
		radius * std::cos(t) * t,
		radius * std::cos(t) * t,
		step * t
	);
}

const Point& Helix3D::GetDerivative(const double t)
{
	return Point
	(
		radius *(std::cos(t) - t * std::acos(t)),
		radius *(std::sin(t) - t * std::asin(t)),
		step
	);
}
