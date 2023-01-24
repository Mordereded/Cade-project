#pragma once
#ifndef POINT_HPP
#define POINT_HPP

struct Point
{
	double x, y, z;
	Point() :x(0), y(0), z(0) {}
	Point(double _x, double _y, double _z) :x(_x), y(_y), z(_z){}
	friend std::ostream& operator<<(std::ostream&, const Point&);
};


#endif 
