#include "Circle.h"
#include <iostream>
#include <corecrt_math_defines.h>

Circle::Circle(double r, Color c) {
	setRadius(r); 
	this->center = Point2D(0, 0);
	this->color = c;
}

Circle::Circle(double r, Point2D center, Color c) {
	setRadius(r); 
	this->center = center;
	this->color = c;
}

std::string colorToString(Color color) {
	switch (color) {
	case Color::Red:    return "Червоний";
	case Color::Green:  return "Зелений";
	case Color::Blue:   return "Синій";
	case Color::Yellow: return "Жовтий";
	case Color::White:  return "Білий";
	case Color::Black:  return "Чорний";
	default:            return "Невідомий";
	}
}

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

void Circle::setColor(Color c) { this->color = c; }
Color Circle::getColor() const { return color; }

Circle operator*(const Circle& circle1, const Circle& circle2) {
	double newArea = circle1.getArea() + circle2.getArea();
	double newRadius = std::sqrt(newArea / M_PI);
	double centerX = (circle1.getCenter().GetX() + circle2.getCenter().GetX()) / 2;
	double centerY = (circle1.getCenter().GetY() + circle2.getCenter().GetY()) / 2;
	Point2D newCenter(centerX, centerY);
	Color newColor;

	if(circle1.getArea() >= circle2.getArea()) {
		newColor = circle1.getColor();
	} else {
		newColor = circle2.getColor();
	}

	return Circle(newRadius, newCenter, newColor);

}

std::ostream& operator<<(std::ostream& os, const Circle& circle)
{
	os << "Радіус: " << circle.getRadius() << std::endl;
	os << "Координати центра: (" << circle.getCenter().GetX() << ", " << circle.getCenter().GetY() << ")" << std::endl;
	os << "Колір: " << colorToString(circle.getColor()) << std::endl;
    os << "Площа: " << circle.getArea() << std::endl;
    return os;
}
