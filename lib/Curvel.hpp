#pragma once
#ifndef CURVEL_HPP
#define CURVEL_HPP
#include "Point.hpp"
#include <iostream>
#include <string>


class Curvel
{
private:
	std::string name; 
	
public:
	Curvel(std::string name):name(name){}
	std::string GetName() { return name; }
	virtual const Point& GetCurvePoint(const double) = 0;
	virtual const Point& GetDerivative(const double) = 0;
	virtual void Print() = 0;
	~Curvel()
	{}


};

#endif