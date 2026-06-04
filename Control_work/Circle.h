#pragma once
#include <string>
#include "Point2D.h"
#include <ostream>

enum class Color {
    Red,
    Green,
    Blue,
    Yellow,
    White,
	Black
};

std::string colorToString(Color color);

class Circle
{
private:
    double radius;
	Point2D center;
    Color color;
public:
    Circle(double r, Color c = Color::Black);
	Circle(double r, Point2D center, Color c = Color::Black);

    double getArea() const;

    void setRadius(double r);
    double getRadius() const;
    void setCenter(Point2D center);
    Point2D getCenter() const;

    void setColor(Color c);
    Color getColor() const;

    friend Circle operator*(const Circle& circle1, const Circle& circle2);
    friend std::ostream& operator<<(std::ostream& os, const Circle& circle); // Add this line
};

