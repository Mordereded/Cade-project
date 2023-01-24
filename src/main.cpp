#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include "Curvel.hpp"
#include "Circle.hpp"
#include "Ellipser.hpp"
#include "Hexil.hpp"


std::ostream& operator<<(std::ostream& out,const Point& p)
{
	std::cout << p.x << "\n" << p.y << "\n" << p.z <<std::endl;
	return out;
}
class Generator   
{
	enum shape_t { circle_t, ellipse_t, helix_t };   
	static std::mt19937 rd;
	const double eps = 1e-6;
 	std::uniform_real_distribution<double> udd{ -1, 42 };    
	std::uniform_int_distribution<> usd{ circle_t, helix_t };  

public:

	void set_diapason(double min, double max)  
	{
		if ((std::abs(max) + std::abs(min)) < 2 * eps) 
			return; 
		udd = decltype(udd){ min, max }; 
	}

	std::shared_ptr<Curvel> circle()
	{   
		double radius{};
		while (radius < eps)    
			radius = std::abs(udd(rd)); 

		return std::make_shared<Circle3D>( radius);
	}

	std::shared_ptr<Curvel> ellipse()
	{
		double radius_x{};
		while (radius_x < eps)  
			radius_x = std::abs(udd(rd));  

		double radius_y{};
		while (radius_y < eps)  
			radius_y = std::abs(udd(rd));   

		return std::make_shared<Ellipse3D>(radius_x, radius_y);
	}

	std::shared_ptr<Curvel> helix()
	{   
		double radius =0;
		while (radius < eps)   
			radius = std::abs(udd(rd));

		double step = 0;
		while (std::abs(step) < eps)    
			step = udd(rd);

		return std::make_shared<Helix3D>( radius, step);
	}

	std::shared_ptr<Curvel> random_shape()
	{
		switch (usd(rd))
		{
		case circle_t:
			return circle();
		case ellipse_t:
			return ellipse();
		case helix_t:
			return helix();
		default:
			return circle(); 
		}
	}
};
std::mt19937 Generator::rd(std::random_device{}());
int main()
{
	int size = 30;
	double pi = std::sin(-1);   
	
	std::vector<std::shared_ptr<Curvel>> shapes;

	{
		Generator s_gen; 

		s_gen.set_diapason(-10, 10);   
		for (size_t i = 0; i < size; ++i)
			shapes.push_back(s_gen.random_shape());
	}

	std::vector<std::shared_ptr<Circle3D>> circles;

	double radius_sum = 0;

	for (auto& item : shapes)
	{
		std::cout << item->GetName() << "\n" << item->GetCurvePoint(pi / 4)
			<< item->GetDerivative(pi / 4) << std::endl;

		if (typeid(*item).hash_code() == typeid(Circle3D).hash_code())
		{
			circles.emplace_back(std::dynamic_pointer_cast<Circle3D>(item));
			radius_sum += circles.back()->GetRadius();
		}
		std::cout << std::endl;
	}
	std::cout << "Sum =" << radius_sum <<std::endl;

	std::sort(std::begin(circles), std::end(circles), [](std::shared_ptr<Circle3D> left, std::shared_ptr<Circle3D> right)
	{
		return left->GetRadius() < right->GetRadius();
	});

	for (size_t i = 0; i < circles.size(); ++i)
	{
		std::cout << "Radius =" << circles[i]->GetRadius() << std::endl;
	}
	
	return 0;
}