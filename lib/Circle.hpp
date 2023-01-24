#pragma once

#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "Curvel.hpp"
class Circle3D : public Curvel
{
private:
	double radius;
public:
	Circle3D();

	explicit Circle3D(const double radius);
	virtual void Print() override;
	void SetRadius(int value);
	double GetRadius();
	virtual const Point& GetCurvePoint(const double t) override;
	virtual const Point& GetDerivative(const double t) override;
};
#endif 

