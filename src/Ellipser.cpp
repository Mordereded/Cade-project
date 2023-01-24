#include "Ellipser.hpp"


Ellipse3D::Ellipse3D() : radius_F1(0), radius_F2(0), Curvel("Ellipse")
{

}
explicit Ellipse3D::Ellipse3D(const double radius_F1, const double radius_F2) :Curvel("Ellipse")
{
	try
	{
		if (radius_F1 < 0 || radius_F2 < 0)
		{
			throw std::runtime_error("Radius can not be negative");
		}
		else
		{
			this->radius_F1 = radius_F1;
			this->radius_F2 = radius_F2;
		}
	}
	catch (std::runtime_error)
	{
		if (radius_F1 < 0) this->radius_F1 = 0;
		if (radius_F2 < 0) this->radius_F2 = 0;
		std::cout << "\nRadius_F1 = " << this->radius_F1 << "\nRadius_F2 = " << this->radius_F2 << std::endl;
	}
}

void Ellipse3D::Print() 
{
	std::cout << "\n[Name - " << this->GetName() << "]" << std::endl;
	std::cout << "[radius_F1 - " << radius_F1 << "]" << std::endl;
	std::cout << "[radius_F2 - " << radius_F2 << "]" << std::endl;
}
const Point& Ellipse3D::GetCurvePoint(const double t) 
{
	return Point
	(
		std::asin(t) * radius_F1,
		std::sin(t) * radius_F2,
		0.0
	);
}

const Point& Ellipse3D::GetDerivative(const double t) 
{
	return Point
	(
		-1 * radius_F1 * std::sin(t),
		radius_F2 * std::cos(t),
		0.0
	);
}