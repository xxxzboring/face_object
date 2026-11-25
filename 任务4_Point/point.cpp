#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Point {
public:
    Point(double x = 0, double y = 0, double z = 0);
    void Init(double x, double y, double z);
    double getX();
    double getY();
    double getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void display();
    double distanceTo(const Point &other);

    friend double euclideanDistance(const Point &a, const Point &b);
    friend double manhattanDistance(const Point &a, const Point &b);
    friend double chebyshevDistance(const Point &a, const Point &b);
    friend Point midpoint(const Point &a, const Point &b);

private:
    double x;
    double y;
    double z;
};

Point::Point(double x, double y, double z) : x(x), y(y), z(z)
{
}

void Point::Init(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

double Point::getZ()
{
    return z;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::setZ(double z)
{
    this->z = z;
}

void Point::display()
{
    cout << fixed << setprecision(2);
    cout << "(" << x << ", " << y << ", " << z << ")";
}

double Point::distanceTo(const Point &other)
{
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double euclideanDistance(const Point &a, const Point &b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double manhattanDistance(const Point &a, const Point &b)
{
    return fabs(a.x - b.x) + fabs(a.y - b.y) + fabs(a.z - b.z);
}

double chebyshevDistance(const Point &a, const Point &b)
{
    double dx = fabs(a.x - b.x);
    double dy = fabs(a.y - b.y);
    double dz = fabs(a.z - b.z);
    double m = dx > dy ? dx : dy;
    return m > dz ? m : dz;
}

Point midpoint(const Point &a, const Point &b)
{
    return Point((a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) / 2);
}

int main()
{
    double x1, y1, z1, x2, y2, z2;
    cout << "Input point A (x y z):" << endl;
    cin >> x1 >> y1 >> z1;
    cout << "Input point B (x y z):" << endl;
    cin >> x2 >> y2 >> z2;

    Point a(x1, y1, z1);
    Point b(x2, y2, z2);

    cout << fixed << setprecision(2);
    cout << "A = ";
    a.display();
    cout << endl;
    cout << "B = ";
    b.display();
    cout << endl;

    cout << "Euclidean distance: " << euclideanDistance(a, b) << endl;
    cout << "Manhattan distance: " << manhattanDistance(a, b) << endl;
    cout << "Chebyshev distance: " << chebyshevDistance(a, b) << endl;

    cout << "Midpoint: ";
    Point m = midpoint(a, b);
    m.display();
    cout << endl;

    cout << "a.distanceTo(b) = " << a.distanceTo(b) << endl;

    return 0;
}
