// card_operations.cpp
// 校园一卡通消费管理系统：各功能模块的函数定义
#include "card_operations.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace card {

void printLine(char c, int len) {
    if (len <= 0) {
        return;
    }
    std::cout << std::string(len, c) << std::endl;
}

void title(const std::string &s) {
    std::cout << "==== " << s << " ====" << std::endl;
}

}  // namespace card

Card *createCards(int n) {
    if (n <= 0) {
        throw std::invalid_argument("账户数量必须为正整数");
    }

    Card *arr = NULL;
    try {
        arr = new Card[n];  // 动态申请 n 个账户
    } catch (const std::bad_alloc &) {
        throw std::runtime_error("内存分配失败，程序无法继续");
    }

    for (int i = 0; i < n; ++i) {
        arr[i].id = 0;
        arr[i].balance = 0.0;
        arr[i].transactions = 0;
    }
    return arr;
}

void destroyCards(Card *p) {
    delete[] p;  // 释放 new[] 申请的内存
}

void inputCards(Card *arr, int n) {
    for (int i = 0; i < n; ++i) {
        while (true) {
            try {
                std::cout << "请输入第 " << (i + 1)
                          << " 个账户（学号 姓名 初始余额）：";
                Card temp;
                temp.transactions = 0;

                if (!(std::cin >> temp.id >> temp.name >> temp.balance)) {
                    if (std::cin.eof()) {
                        throw std::runtime_error("输入流已结束");
                    }
                    throw std::runtime_error("学号、姓名或余额格式错误");
                }
                if (temp.balance < 0.0) {
                    throw std::invalid_argument("余额不能为负数");
                }

                arr[i] = temp;
                break;
            } catch (const std::invalid_argument &e) {
                std::cout << "输入错误：" << e.what()
                          << "，请重新输入该账户。" << std::endl;
            } catch (const std::runtime_error &e) {
                if (std::cin.eof()) {
                    throw;  // 没有后续输入，无法重试，交给主程序处理
                }
                std::cout << "输入错误：" << e.what()
                          << "，请重新输入该账户。" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
            }
        }
    }
}

void deposit(Card &c, double amount, double fee) {
    if (amount <= 0.0) {
        throw std::invalid_argument("充值金额必须大于 0");
    }
    if (fee < 0.0 || fee >= 1.0) {
        throw std::invalid_argument("手续费率不合法");
    }

    c.balance += amount * (1.0 - fee);  // 扣除手续费后入账
    ++c.transactions;
}

bool spend(Card &c, double cost) {
    if (cost < 0.0) {
        throw std::invalid_argument("消费金额不能为负数");
    }
    if (cost > c.balance) {
        throw std::runtime_error("余额不足，消费失败");
    }

    c.balance -= cost;
    ++c.transactions;
    return true;
}

bool spend(Card &c, double cost, const std::string &item) {
    std::cout << "消费项目：" << item << std::endl;
    return spend(c, cost);  // 调用上面的重载版本完成扣款
}

// 常引用：只读访问，避免拷贝，也防止函数修改账户
void showBalance(const Card &c) {
    std::cout << c.name << " 当前余额为："
              << std::fixed << std::setprecision(2) << c.balance << std::endl;
}

// 指向常量的指针：通过指针只能读取，不能修改
void viewStudentID(const Card *p) {
    if (p == NULL) {
        return;
    }
    std::cout << "账户ID为：" << p->id << std::endl;
}

int toCent(double amount) {
    if (amount < 0.0) {
        throw std::invalid_argument("金额不能为负数");
    }
    return static_cast<int>(amount * 100.0 + 0.5);  // 元 -> 分，四舍五入
}

void printReport(const Card *arr, int n) {
    if (arr == NULL || n <= 0) {
        return;
    }

    card::printLine('=', 60);
    std::cout << std::left << std::setw(8) << "ID"
              << std::setw(15) << "Name"
              << std::right << std::setw(10) << "Balance"
              << std::setw(15) << "Transactions" << std::endl;
    card::printLine('-', 60);

    std::cout << std::fixed << std::setprecision(2);
    int warningCount = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << std::left << std::setw(8) << arr[i].id
                  << std::setw(15) << arr[i].name
                  << std::right << std::setw(10) << arr[i].balance
                  << std::setw(15) << arr[i].transactions << std::endl;
        if (arr[i].balance < WARNING_BALANCE) {
            ++warningCount;
        }
    }

    card::printLine('=', 60);
    if (warningCount > 0) {
        std::cout << "提示：有 " << warningCount
                  << " 个账户余额低于警戒值 " << std::fixed
                  << std::setprecision(2) << WARNING_BALANCE << " 元。"
                  << std::endl;
    }
}
