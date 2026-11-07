// CampusCardSystem.cpp
// 校园一卡通消费管理系统：主控程序（用户交互与功能调用）
#include "card_operations.h"

#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "请输入学生数量：";
    int n = 0;
    if (!(std::cin >> n)) {
        std::cerr << "输入错误：学生数量必须是整数。" << std::endl;
        return 1;
    }

    Card *cards = NULL;
    try {
        cards = createCards(n);   // 动态创建账户数组
    } catch (const std::exception &e) {
        std::cerr << "创建账户失败：" << e.what() << std::endl;
        return 1;
    }

    try {
        inputCards(cards, n);     // 录入账户信息

        card::title("Campus Card System");

        deposit(cards[0], 100.0);                 // 充值 100 元，默认费率 2%
        spend(cards[0], 8.5, "食堂午餐");          // 带项目的消费
        showBalance(cards[0]);                    // 常引用只读查询
        viewStudentID(&cards[0]);                 // 指向常量的指针查询
        std::cout << "换算为分：" << toCent(cards[0].balance) << std::endl;
        std::cout << std::endl;

        printReport(cards, n);                    // 输出全部账户报表
    } catch (const std::exception &e) {
        std::cerr << "操作失败：" << e.what() << std::endl;
    }

    destroyCards(cards);                          // 释放动态内存
    return 0;
}
