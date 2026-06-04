#pragma once
#include <string>
#include "Point2D.h"
#include <ostream>

class Circle
{
private:
    double radius;
	Point2D center;
public:
    Circle(double r);
	Circle(double r, Point2D center);

    std::string getName() const;
    double getArea() const;
    void setRadius(double r);
    double getRadius() const;
    void setCenter(Point2D center);
    Point2D getCenter() const;
    friend Circle operator*(const Circle& circle1, const Circle& circle2);
    friend std::ostream& operator<<(std::ostream& os, const Circle& circle); // Add this line
};

