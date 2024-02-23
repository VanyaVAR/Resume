#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES

using namespace std;
struct point
{
    float x, y;
};

class Shape
{
public:
    static inline unsigned Lcount{};
    static inline unsigned Rcount{};
    static inline unsigned Scount{};
    static inline unsigned Ccount{};
    static inline unsigned Ecount{};

    virtual float GetPerimeter()
    {
        return 0;
    };
    virtual float GetArea()
    {
        return 0;
    };
};

class Line : public Shape
{
public:
    point a;
    point b;
    float length;

    Line()
    {
        Lcount++;
        this->a.x = rand() % 100;
        this->a.y = rand() % 100;
        this->b.x = this->a.x + rand() % 50;
        this->b.y = this->a.y + rand() % 50;
        this->length = pow(pow(this->b.x - this->a.x, 2) + pow(this->b.y - this->a.y, 2), 0.5);
    }
    ~Line()
    {
        Lcount--;
    }

    int GetCount()
    {
        return Lcount;
    }

    void PrintLength()
    {
        printf("Length: %.2f\n", this->length);
    }

    void PrintCoords()
    {
        printf("x1: %.2f| y1: %.2f\n", this->a.x, this->a.y);
        printf("x2: %.2f| y2: %.2f\n", this->b.x, this->b.y);
    }
};

class Square : public Line
{
public:
    Square()
    {
        Scount++;
        this->a.x = rand() % 100;
        this->a.y = rand() % 100;
        int n = rand() % 50;
        this->b.x = this->a.x + n;
        this->b.y = this->a.y + n;
        this->length = this->b.x - this->a.x;
    }
    ~Square()
    {
        Scount--;
    }

    int GetCount()
    {
        return Scount;
    }

    float GetPerimeter()
    {
        return length * 4;
    }

    float GetArea()
    {
        return length * length;
    }
};

class Rectangle : public Square
{
    float length2;

public:
    Rectangle()
    {
        Rcount++;
        this->a.x = rand() % 100;
        this->a.y = rand() % 100;
        this->b.x = this->a.x + rand() % 50;
        this->b.y = this->a.y + rand() % 50;
        this->length = this->b.x - this->a.x;
        this->length2 = this->b.y - this->a.y;
    }
    Rectangle(int _x1, int _y1, int _x2, int _y2)
    {
        Rcount++;
        this->a.x = _x1;
        this->a.y = _y1;
        this->b.x = _x2;
        this->b.y = _y2;
        this->length = this->b.x - this->a.x;
        this->length2 = this->b.y - this->a.y;
    }
    ~Rectangle()
    {
        Rcount--;
    }

    int GetCount()
    {
        return Rcount;
    }

    void PrintLength()
    {
        printf("Length A: %.2f\n", this->length);
        printf("Length B: %.2f\n", this->length2);
    }

    float GetPerimeter()
    {
        return (length + length2) * 2;
    }

    float GetArea()
    {
        return length * length2;
    }
};

class Circle : public Shape
{
public:
    float r;

    Circle()
    {
        this->r = rand() % 100;
    }

    Circle(float r)
    {
        Ccount++;
        this->r = r;
    }

    ~Circle()
    {
        Ccount--;
    }

    int GetCount()
    {
        return Ccount;
    }

    float GetPerimeter()
    {
        return M_PI * 2 * r;
    }

    float GetArea()
    {
        return M_PI * r * r;
    }
};

class Elipse : public Circle
{
public:
    float r2;

    Elipse()
    {
        Ecount++;
        this->r = rand() % 100;
        this->r2 = rand() % 100;
    }

    Elipse(float r, float r2)
    {
        Ecount++;
        this->r = r;
        this->r2 = r2;
    }

    ~Elipse()
    {
        Ecount--;
    }

    int GetCount()
    {
        return Ecount;
    }

    float GetPerimeter()
    {
        return M_PI * 2 * sqrt(pow(r, 2) + pow(r2, 2));
    }
    float GetArea()
    {
        return M_PI * r * r + M_PI * r2 * r2;
    }
};

int main()
{
    srand(time(NULL));
    Line L;
    Square S;
    Rectangle R;
    Circle C;
    Elipse E;
    printf("Rectangles: %d\n", R.GetCount());

    Rectangle *Rptr;
    printf("Rectangles: %d\n", R.GetCount());
    Rptr = new Rectangle();
    printf("Rectangles: %d\n", R.GetCount());

    Shape **Shapes = new Shape *[4];
    Shapes[0] = new Rectangle();
    Shapes[1] = new Square();
    Shapes[2] = new Circle();
    Shapes[3] = new Elipse();
    printf("Rectangles: %d\n", R.GetCount());
    for (int i = 0; i < 4; i++)
    {
        printf("Perimeter: %.2f\n", Shapes[i]->GetPerimeter());
    }
    delete Rptr;
    for (int i = 0; i < 4; i++) {
        delete[] Shapes[i];
    }
    delete[] Shapes;
    
    printf("Rectangles: %d\n", R.GetCount());
    return 0;
}