#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Triangle {
public:
    Triangle(double a = 1, double b = 1, double c = 1);
    void Init(double a, double b, double c);
    bool isTriangle();
    double getSideA();
    double getSideB();
    double getSideC();
    void setSideA(double a);
    void setSideB(double b);
    void setSideC(double c);
    double perimeter();
    double area();
    int typeTriangle();
    void display();

private:
    double a;
    double b;
    double c;

    static bool isPositive(double x);
};

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c)
{
    if (!isPositive(a) || !isPositive(b) || !isPositive(c)) {
        cout << "Invalid sides: they must be positive, set to 1 1 1" << endl;
        this->a = 1;
        this->b = 1;
        this->c = 1;
    }
}

void Triangle::Init(double a, double b, double c)
{
    if (!isPositive(a) || !isPositive(b) || !isPositive(c)) {
        cout << "Invalid sides: they must be positive, keep the old value" << endl;
        return;
    }
    this->a = a;
    this->b = b;
    this->c = c;
}

bool Triangle::isTriangle()
{
    if (!isPositive(a) || !isPositive(b) || !isPositive(c))
        return false;
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double Triangle::getSideA()
{
    return a;
}

double Triangle::getSideB()
{
    return b;
}

double Triangle::getSideC()
{
    return c;
}

void Triangle::setSideA(double a)
{
    if (!isPositive(a)) {
        cout << "Invalid side: " << a << ", ignored" << endl;
        return;
    }
    this->a = a;
}

void Triangle::setSideB(double b)
{
    if (!isPositive(b)) {
        cout << "Invalid side: " << b << ", ignored" << endl;
        return;
    }
    this->b = b;
}

void Triangle::setSideC(double c)
{
    if (!isPositive(c)) {
        cout << "Invalid side: " << c << ", ignored" << endl;
        return;
    }
    this->c = c;
}

double Triangle::perimeter()
{
    return a + b + c;
}

double Triangle::area()
{
    if (!isTriangle()) {
        cout << "Error: cannot form a triangle" << endl;
        return 0;
    }
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int Triangle::typeTriangle()
{
    if (!isTriangle())
        return 0;

    double x = a, y = b, z = c;
    if (x > z) { double t = x; x = z; z = t; }
    if (y > z) { double t = y; y = z; z = t; }

    double diff = x * x + y * y - z * z;
    if (fabs(diff) < 1e-6)
        return 1;
    if (diff > 0)
        return 2;
    return 3;
}

void Triangle::display()
{
    cout << fixed << setprecision(2);
    cout << "Sides: " << a << " " << b << " " << c << endl;
    if (!isTriangle()) {
        cout << "Error: cannot form a triangle" << endl;
        return;
    }
    cout << "Perimeter: " << perimeter() << endl;
    cout << "Area: " << area() << endl;

    static const char *TYPE[] = {"cannot form a triangle", "直角三角形",
                                 "锐角三角形", "钝角三角形"};
    cout << "Type: " << TYPE[typeTriangle()] << endl;
}

bool Triangle::isPositive(double x)
{
    return x > 0;
}

int main()
{
    double a, b, c;
    cout << "Input three sides:" << endl;
    cin >> a >> b >> c;

    Triangle t(a, b, c);
    t.display();

    return 0;
}
