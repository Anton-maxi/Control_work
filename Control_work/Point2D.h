#pragma once
class Point2D
{
private:
    double X;
    double Y;
public:
	void SetX(double x);
    double GetX() const;
	void SetY(double y);
    double GetY() const;

    Point2D();
    Point2D(double x, double y);

    double DistanceTo(Point2D other) const;
};

