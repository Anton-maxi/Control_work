#include "Point2D.h"
#include <cmath>

Point2D::Point2D()
{
    this->X = 0;
    this->Y = 0;
}

Point2D::Point2D(double x, double y)
{
    this->X = x;
    this->Y = y;
}

void Point2D::SetX(double x) { this->X = x; }
void Point2D::SetY(double y) { this->Y = y; }
double Point2D::GetX() const { return X; }
double Point2D::GetY() const { return Y; }

double Point2D::DistanceTo(Point2D other) const {
    return std::sqrt(std::pow(other.X - X, 2) + std::pow(other.Y - Y, 2));
}