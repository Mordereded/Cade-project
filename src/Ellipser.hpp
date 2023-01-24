#pragma once
#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Curvel.hpp"
class Ellipse3D : public Curvel
{
private:
	double radius_F1, radius_F2;
public:
	Ellipse3D();
	explicit Ellipse3D(const double radius_F1, const double radius_F2);
	virtual void Print() override;
	virtual const Point& GetCurvePoint(const double t) override;
	virtual const Point& GetDerivative(const double t) override;
};
#endif 

