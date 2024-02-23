#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

class Figure {
    virtual void PrintP() {  // объявляем виртуальный метод
        cout << "Null" << endl;
    }
    virtual void PrintS() {  // объявляем виртуальный метод
        cout << "Null" << endl;
    }
};

class Line : public Figure {
private:
    int x1, x2;
    int y1, y2;
    double len;

public:
    Line() {  // конструктор по умолч случ
        this->x1 = rand() % 10 + 1;
        this->y1 = rand() % 10 + 1;
        this->x2 = rand() % 10 + 1;
        this->y2 = rand() % 10 + 1;
        this->len = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    Line(int x1, int y1, int x2, int y2) {  // конструктор с пар-ми
        this->x1 = x1;
        this->x2 = x2;
        this->x2 = x2;
        this->y2 = y2;
        this->len = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    void getLine() {
        cout << "Line: (" << this->x1 << "," << this->y1 << ") (" << this->x2
            << "," << this->y2 << ")\n";
        cout << "Length:" << setprecision(3) << this->len << endl;
    }

    void setLine(int a, int b, int c, int d) {
        this->x1 = a;
        this->y1 = b;
        this->x2 = c;
        this->y2 = d;
        this->len = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    double getLen() { return this->len; }
    void PrintP() { cout << "None!" << endl; }
    void PrintS() { cout << "None!" << endl; }

    ~Line() {}
};

class Square : public Line {
private:
    Line line1;

public:
    Square() { line1; } //rand
    Square(Line line1) { this->line1 = line1; } //param

    void getSquare() { this->line1.getLine(); }
    void setSquare(Line line1) { this->line1 = line1; }

    void PrintP() { cout << "P: " << setprecision(3) << this->line1.getLen() * 4 << endl; }
    void PrintS() { cout << "S: " << setprecision(3) << pow(this->line1.getLen(), 2) << endl; }

    ~Square() {}
};

class Rectangle : public Square {
private:
    Line line1;
    Line line2;

public:
    Rectangle() { //rand
        line1;
        line2;
    }

    Rectangle(Line line1, Line line2) { //param
        this->line1 = line1;
        this->line2 = line2;
    }

    void getSquare() {
        this->line1.getLine();
        this->line2.getLine();
    }

    void setSquare(Line line1, Line line2) {
        this->line1 = line1;
        this->line2 = line2;
    }

    void PrintP() { cout << "P: " << setprecision(3) << (this->line1.getLen() + this->line2.getLen()) * 2 << endl; }
    void PrintS() { cout << "S: " << setprecision(3) << this->line1.getLen() * this->line2.getLen() << endl; }

    ~Rectangle() {}
};

class Circle : Figure {
private:
    int x1, y1;
    double r1;

public:
    Circle() {
        this->x1 = rand() % 10 + 1;
        this->y1 = rand() % 10 + 1;
        this->r1 = rand() % 10 + 1;
    }

    Circle(int x1, int y1, double r1) {
        this->x1 = x1;
        this->y1 = y1;
        this->r1 = r1;
    }

    void getCircle() {
        cout << "Circle: (" << this->x1 << "," << this->y1 << "," << this->r1 << ")\n";
    }

    void setCircle(int a, int b, int c) {
        this->x1 = a;
        this->y1 = b;
        this->r1 = c;
    }
    void PrintS() { cout << "S: " << M_PI * pow(this->r1, 2) << endl; }
    void PrintP() { cout << "P: " << 2 * M_PI * this->r1 << endl; }

    ~Circle() {}
};

class Ellipse : Circle {
private:
    int x1, y1;
    double r1, r2;

public:
    Ellipse() {
        this->x1 = rand() % 10 + 1;
        this->y1 = rand() % 10 + 1;
        this->r1 = rand() % 10 + 1;
        this->r2 = rand() % 10 + 1;
    }

    Ellipse(int x1, int y1, double r1, double r2) {
        this->x1 = x1;
        this->y1 = y1;
        this->r1 = r1;
        this->r2 = r2;
    }

    void getCircle() {
        cout << "Ellipse: (" << this->x1 << "," << this->y1 << "," << this->r1 << "," << this->r2 << ")\n";
    }

    void setCircle(int a, int b, int c, int d) {
        this->x1 = a;
        this->y1 = b;
        this->r1 = c;
        this->r2 = d;
    }

    void PrintS() { cout << "S: " << M_PI * this->r1 * this->r2 << endl; }
    void PrintP() { cout << "P: " << 2 * M_PI * sqrt((pow(this->r1, 2) + pow(this->r2, 2)) / 2) << endl; }

    ~Ellipse() {}

};

int main() {
    srand(time(NULL));
    Line line;
    cout << "----Line----" << endl;
    line.getLine();
    int a, b, c, d;
    cout << "print a b c d\n";
    cin >> a >> b >> c >> d;
    line.setLine(a, b, c, d);
    line.getLine();
    cout << "\n\n";

    Square square;
    cout << "----Square----" << endl;
    square.getSquare();
    square.PrintP();
    square.PrintS();
    cout << "\n";

    square.setSquare(line);
    square.getSquare();
    square.PrintP();
    square.PrintS();
    cout << "\n\n";

    Rectangle rec;
    cout << "----Rectangle----" << endl;
    rec.getSquare();
    rec.PrintP();
    rec.PrintS();
    cout << "\n";

    Line line1;
    cout << "print a b c d\n";
    cin >> a >> b >> c >> d;
    line1.setLine(a, b, c, d);
    rec.setSquare(line, line1);
    rec.getSquare();
    rec.PrintP();
    rec.PrintS();
    cout << "\n\n";

    Circle circle;
    Circle circle1(a, b, c);
    cout << "----Circle----" << endl;
    circle.getCircle();
    circle.PrintP();
    circle.PrintS();
    cout << "\n";
    circle1.getCircle();
    circle.PrintP();
    circle.PrintS();
    cout << "\n";

    Ellipse el;
    Ellipse el1(a, b, c, d);
    cout << "----Ellipse----" << endl;
    el.getCircle();
    el.PrintP();
    el.PrintS();
    cout << "\n";
    el1.getCircle();
    el1.PrintP();
    el1.PrintS();
    cout << "\n";

    cout << "----Arr of Rect----" << endl;
    int size = 3;
    Rectangle* arr_rec = new Rectangle[size];
    for (int i = 0; i < 3; i++) {
        Line l1, l2;
        Rectangle r(l1, l2);
        arr_rec[i] = r;
    }

    for (int i = 0; i < 3; i++) {
        cout << "Rect " << i + 1 << endl;
        arr_rec[i].PrintP();
        arr_rec[i].PrintS();
        cout << endl;
    }

    delete[] arr_rec;
}