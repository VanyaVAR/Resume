#include <iostream>
#include <cstdlib> // Для генерации случайных чисел
#include <math.h>
using namespace std;

class figure
{
protected:
    int x_;
    int y_;

public:
    figure() : x_(0), y_(0) {} // Конструктор по умолчанию инициализирует координаты нулями
    figure(int x, int y) : x_(x), y_(y) {}
    
    ~figure() {} // Виртуальный деструктор для корректной очистки памяти

    void input()
    {
        cout << "Enter x coordinate: ";
        cin >> x_;
        cout << "Enter y coordinate: ";
        cin >> y_;
    }

    void display()
    {
        cout << "x coordinate: " << x_ << endl;
        cout << "y coordinate: " << y_ << endl;
    }
};

class circle : public figure
{
	private:
	    int radius_;
	
	public:
	    circle() : figure(), radius_(0) {} // Конструктор по умолчанию инициализирует радиус нулем
	    circle(int x, int y, int radius) : figure(x, y), radius_(radius) {}
	    
	    void input()
	    {
	        figure::input(); // Вызов метода input() базового класса
	        cout << "Enter radius: ";
	        cin >> radius_;
	    }
	
	    void display()
	    {
	        figure::display(); // Вызов метода display() базового класса
	        cout << "Radius: " << radius_ << endl;
	    }
};

class ellipse : public circle
{
private:
    int radius2_;

public:
    ellipse() : circle(), radius2_(0) {} // Конструктор по умолчанию инициализирует второй радиус нулем
    ellipse(int x, int y, int radius1, int radius2) : circle(x, y, radius1), radius2_(radius2) {}
    
    void input() 
    {
        circle::input(); // Вызов метода input() класса circle
        cout << "Enter second radius: ";
        cin >> radius2_;
    }

    void display()
    {
        circle::display(); // Вызов метода display() класса circle
        cout << "Second radius: " << radius2_ << endl;
    }
};

class line : public figure
{
	protected:
	    int x2_;
	    int y2_;
	    double length_;
	
	public:
	    line() : figure(), x2_(0), y2_(0), length_(0.0) {}
	    line(int x1, int y1, int x2, int y2) : figure(x1, y1), x2_(x2), y2_(y2)
	    {
	        calculateLength();
	    }
	    
	    void input() 
	    {
	        figure::input(); // Вызов метода input() базового класса
	        cout << "Enter second point's x coordinate: ";
	        cin >> x2_;
	        cout << "Enter second point's y coordinate: ";
	        cin >> y2_;
	        calculateLength();
	    }
	
	    void display() 
	    {
	        figure::display(); // Вызов метода display() базового класса
	        cout << "Second point's x coordinate: " << x2_ << endl;
	        cout << "Second point's y coordinate: " << y2_ << endl;
	        cout << "Length: " << length_ << endl;
	    }
	
	    double calculateLength()
	    {
	        length_ = sqrt((x2_ - x_) * (x2_ - x_) + (y2_ - y_) * (y2_ - y_));
	        return length_;
	    }
};

class square : public line
{
	public:
	    square() : line() {}
	    square(int x1, int y1, int x2, int y2) : line(x1, y1, x2, y2) {}
	
	    double calculatePerimeter()
	    {
	        return (4 * length_);
	    }
	
	    double calculateArea()
	    {
	        return length_ * length_;
	    }
};

class rectangle : public square
{
	public:
	    rectangle() : square() {}
	    rectangle(int x1, int y1, int x2, int y2) : square(x1, y1, x2, y2) {}
	
	    double calculatePerimeter()
	    {
	        return 2 * (length_ + line::calculateLength());
	    }
	
	    double calculateArea()
	    {
	        return length_ * line::calculateLength();
	    }
};

int main()
{
    circle c1(1, 2, 3);
    cout << "Circle Data:" << endl;
    c1.display();
    cout << endl;

    ellipse e1(4, 5, 6, 7);
    cout << "Ellipse Data:" << endl;
    e1.display();
    cout << endl;

    line l1(8, 9, 10, 11);
    cout << "Line Data:" << endl;
    l1.display();
    cout << "Length of the line: " << l1.calculateLength() << endl;
	cout << endl;
	
    square s1(12, 13, 14, 15);
    cout << "Square Data:" << endl;
    s1.display();
    cout << "Perimeter of the square: " << s1.calculatePerimeter() << endl;
    cout << "Area of the square: " << s1.calculateArea() << endl;
	cout << endl;

    rectangle r1(16, 17, 18, 19);
    cout << "Rectangle Data:" << endl;
    r1.display();
    cout << "Perimeter of the rectangle: " << r1.calculatePerimeter() << endl;
    cout << "Area of the rectangle: " << r1.calculateArea() << endl;
    cout << endl;

    // Создание динамического массива из 3 объектов класса Прямоугольник
    rectangle* rectangles = new rectangle[3];

    // Ввод значений координат для каждого объекта
    for (int i = 0; i < 3; ++i)
    {
        cout << "Enter data for Rectangle " << i + 1 << ":" << endl;
        rectangles[i].input();
        cout << endl;
    }

    // Вычисление периметров и площадей для каждого объекта и вывод на экран
    for (int i = 0; i < 3; ++i)
    {
        cout << "Data for Rectangle " << i + 1 << ":" << endl;
        rectangles[i].display();
        cout << "Perimeter: " << rectangles[i].calculatePerimeter() << endl;
        cout << "Area: " << rectangles[i].calculateArea() << endl;
        cout << endl;
    }

    // Удаление динамического массива
    delete[] rectangles;

    return 0;
}

