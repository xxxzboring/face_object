// 实验2-1 任务四：用引用交换两个整数（并重载指针版本）
// 考察点：引用传参、函数重载
#include <iostream>

// 引用版本：x、y 是实参的别名，函数内修改的就是调用者的变量
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// 重载版本：指针方式交换
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 0;
    int y = 0;
    if (!(std::cin >> x >> y)) {
        return 1;
    }

    std::cout << "Before swap: x=" << x << ", y=" << y << std::endl;
    swap(x, y);                                   // 调用引用版本
    std::cout << "After  swap: x=" << x << ", y=" << y << std::endl;

    swap(&x, &y);                                 // 调用指针重载版本
    std::cout << "Pointer swap: x=" << x << ", y=" << y << std::endl;
    return 0;
}
