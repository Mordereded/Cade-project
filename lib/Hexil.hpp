#pragma once
#ifndef HEXIL_HPP
#define HEXIL_HPP
#include "Curvel.hpp"

class Helix3D : public Curvel
{
private:
	double step, radius;
public:
	Helix3D();
	explicit Helix3D(int step, int radius);
	virtual void Print() override;
	virtual const Point& GetCurvePoint(const double t) override;
	virtual const Point& GetDerivative(const double t) override;
}
#endif
