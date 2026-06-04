#include "Circle.h"
#include <iostream>
#include <corecrt_math_defines.h>

Circle::Circle(double r) {
	this->radius = r;
	center = Point2D(0, 0);
}

Circle::Circle(double r, Point2D center) {
	this->radius = r;
	this->center = center;
}


std::string Circle::getName() const { return "Коло"; }
double Circle::getArea() const { return M_PI * radius * radius; }
void Circle::setRadius(double r) {
	if (r < 0) {
		throw std::invalid_argument("Радіус не може бути від'ємним.");
	}
	this->radius = r;
}
double Circle::getRadius() const { return radius; }
void Circle::setCenter(Point2D center) {
	this->center = center;
}
Point2D Circle::getCenter() const { return center; }

Circle operator*(const Circle& circle1, const Circle& circle2) {
	double newArea = circle1.getArea() + circle2.getArea();
	double newRadius = std::sqrt(newArea / M_PI);
	double centerX = (circle1.getCenter().GetX() + circle2.getCenter().GetX()) / 2;
	double centerY = (circle1.getCenter().GetY() + circle2.getCenter().GetY()) / 2;
	Point2D newCenter(centerX, centerY);
	return Circle(newRadius, newCenter);
}

std::ostream& operator<<(std::ostream& os, const Circle& circle)
{
	os << "Радіус: " << circle.getRadius() << std::endl;
	os << "Координати центра: (" << circle.getCenter().GetX() << ", " << circle.getCenter().GetY() << ")" << std::endl;
    os << "Площа: " << circle.getArea() << std::endl;
    return os;
}
