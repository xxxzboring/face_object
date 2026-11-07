// card_operations.h
// 校园一卡通消费管理系统的函数声明与数据结构定义
#ifndef CARD_OPERATIONS_H
#define CARD_OPERATIONS_H

#include <string>

// 系统常量
const double FEE_RATE = 0.02;         // 充值手续费率
const double WARNING_BALANCE = 10.0;  // 低余额警戒值

// 学生一卡通账户
struct Card {
    int id;            // 学号
    std::string name;  // 姓名
    double balance;    // 当前余额（元）
    int transactions;  // 交易次数
};

// 输出辅助模块：封装分隔线与标题的输出
namespace card {
void printLine(char c = '-', int len = 60);
void title(const std::string &s);
}  // namespace card

// 动态内存管理
Card *createCards(int n);
void destroyCards(Card *p);

// 账户录入
void inputCards(Card *arr, int n);

// 账户操作
void deposit(Card &c, double amount, double fee = FEE_RATE);
bool spend(Card &c, double cost);
bool spend(Card &c, double cost, const std::string &item);
void showBalance(const Card &c);
void viewStudentID(const Card *p);

// 金额换算与报表输出
int toCent(double amount);
void printReport(const Card *arr, int n);

#endif  // CARD_OPERATIONS_H
