#include <iostream>
#include <vector>

// Функция, описывающая дифференциальное уравнение dy/dt = f(t, y)
double f(double t, double y)
{
    // Здесь нужно задать ваше дифференциальное уравнение
    return t * t + y;
}

// Класс для кубического сплайна
class CubicSpline {
private:
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> a;
    std::vector<double> b;
    std::vector<double> c;
    std::vector<double> d;

public:
    CubicSpline(const std::vector<double>& x, const std::vector<double>& y)
    {
        int n = x.size();
        this->x = x;
        this->y = y;

        // Вычисление коэффициентов сплайна
        std::vector<double> h(n);
        for (int i = 0; i < n - 1; i++) {
            h[i] = x[i + 1] - x[i];
        }

        std::vector<double> alpha(n);
        for (int i = 1; i < n - 1; i++) {
            alpha[i] = 3.0
                    * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1]);
        }

        std::vector<double> l(n);
        std::vector<double> mu(n);
        std::vector<double> z(n);
        l[0] = 1.0;
        mu[0] = 0.0;
        z[0] = 0.0;

        for (int i = 1; i < n - 1; i++) {
            l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
            mu[i] = h[i] / l[i];
            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
        }

        l[n - 1] = 1.0;
        z[n - 1] = 0.0;
        c.resize(n);
        b.resize(n);
        d.resize(n);

        c[n - 1] = 0.0;
        for (int i = n - 2; i >= 0; i--) {
            c[i] = z[i] - mu[i] * c[i + 1];
            b[i] = (y[i + 1] - y[i]) / h[i]
                    - h[i] * (c[i + 1] + 2.0 * c[i]) / 3.0;
            d[i] = (c[i + 1] - c[i]) / (3.0 * h[i]);
        }
    }

    // Вычисление значения сплайна в точке t
    double operator()(double t)
    {
        int n = x.size();
        if (t <= x[0]) {
            return y[0];
        }
        if (t >= x[n - 1]) {
            return y[n - 1];
        }
        int i = 0;
        int j = n - 1;
        while (i + 1 < j) {
            int k = i + (j - i) / 2;
            if (t <= x[k]) {
                j = k;
            } else {
                i = k;
            }
        }
        double dx = t - x[i];
        return y[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
    }
};

// Функция для решения дифференциального уравнения методом Рунге-Кутта 2 порядка
double rungeKutta2(double t0, double y0, double h)
{
    double t = t0;
    double y = y0;

    while (t < 1) {
        double k1 = h * f(t, y);
        double k2 = h * f(t + h, y + k1);
        y = y + (k1 + k2) / 2;
        t = t + h;
    }

    return y;
}

// Функция для решения дифференциального уравнения методом Рунге-Кутта 4 порядка
double rungeKutta4(double t0, double y0, double h)
{
    double t = t0;
    double y = y0;

    while (t < 1) {
        double k1 = h * f(t, y);
        double k2 = h * f(t + h / 2, y + k1 / 2);
        double k3 = h * f(t + h / 2, y + k2 / 2);
        double k4 = h * f(t + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        t = t + h;
    }

    return y;
}

int main()
{
    double h = 0.1; // Шаг
    double t0 = 0;  // Начальное значение t
    double y0 = 1;  // Начальное значение y

    // Решение методом Рунге-Кутта 2 порядка
    double y_rk2 = rungeKutta2(t0, y0, h);

    // Решение методом Рунге-Кутта 4 порядка
    double y_rk4 = rungeKutta4(t0, y0, h);

    std::cout << "Решение методом Рунге-Кутта 2 порядка: " << y_rk2
              << std::endl;
    std::cout << "Решение методом Рунге-Кутта 4 порядка: " << y_rk4
              << std::endl;

    // Интерполяция с помощью кубического сплайна
    std::vector<double> x = {0, 0.2, 0.4, 0.6, 0.8, 1.0};
    std::vector<double> y = {0, 0.2, 0.4, 0.6, 0.8, y_rk4}; // Используем решение методом Рунге-Кутта 4 порядка

    CubicSpline spline(x, y);

    std::cout << "Интерполированное значение при t = 0.5: " << spline(0.5)
              << std::endl;

    return 0;
}
