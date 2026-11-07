// 实验2-1 任务三：简易多功能计算器
// 考察点：inline 内联函数、带默认参数的函数、函数重载
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// 1. 内联函数：计算平方，适合这种短小且频繁调用的函数
inline double square(double x) {
    return x * x;
}

// 2. 带默认参数的函数：不给出指数时默认计算平方
double power(double base, int exponent = 2) {
    int e = (exponent < 0) ? -exponent : exponent;
    double result = 1.0;
    for (int i = 0; i < e; ++i) {
        result *= base;
    }
    return (exponent < 0) ? 1.0 / result : result;
}

// 把操作数打印成 3 而不是 3.00 的形式
std::string numToStr(double x) {
    std::ostringstream oss;
    oss << std::defaultfloat << x;
    return oss.str();
}

// 3. 重载版本一：double 运算
double calc(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0.0) {                       // 除数为 0 的错误处理
                std::cout << "Error: divide by zero" << std::endl;
                return std::numeric_limits<double>::quiet_NaN();
            }
            return a / b;
        default:
            std::cout << "Error: unknown operator" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
    }
}

// 3. 重载版本二：int 运算（整数实参优先匹配本版本）
double calc(int a, int b, char op) {
    return calc(static_cast<double>(a), static_cast<double>(b), op);
}

int main() {
    double a = 0.0;
    double b = 0.0;
    char op = ' ';

    if (!(std::cin >> a >> b >> op)) {
        std::cout << "Error: invalid input" << std::endl;
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "square(" << numToStr(a) << ") = " << square(a) << std::endl;
    std::cout << "power(" << numToStr(a) << ",3) = "
              << power(a, 3) << std::endl;        // 显式给出指数 3

    // 两个操作数都是整数时调用 int 版本，否则调用 double 版本
    double result = 0.0;
    bool bothInteger = (a == std::floor(a)) && (b == std::floor(b));
    if (bothInteger) {
        result = calc(static_cast<int>(a), static_cast<int>(b), op);
    } else {
        result = calc(a, b, op);
    }

    if (!std::isnan(result)) {                    // 出错时不打印结果行
        std::cout << numToStr(a) << " " << op << " " << numToStr(b)
                  << " = " << result << std::endl;
    }
    return 0;
}
