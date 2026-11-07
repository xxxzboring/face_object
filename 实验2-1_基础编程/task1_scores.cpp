// 实验2-1 任务一：学生成绩统计与输出
// 考察点：cin/cout 输入输出控制、iomanip 格式控制、输出列对齐
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 学生信息：姓名 + 三门课成绩 + 平均分
struct Student {
    string name;
    double chinese;
    double math;
    double english;
    double average;
};

int main() {
    int n = 0;
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid student number." << endl;
        return 1;
    }

    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].chinese
            >> students[i].math >> students[i].english;
        students[i].average =
            (students[i].chinese + students[i].math + students[i].english) / 3.0;
    }

    // 表头：姓名左对齐，成绩右对齐
    cout << std::left << std::setw(12) << "Name"
         << std::right << std::setw(9) << "Chinese"
         << std::setw(9) << "Math"
         << std::setw(9) << "English"
         << std::setw(10) << "Average" << "  Remark" << endl;
    cout << string(60, '-') << endl;

    // fixed + setprecision(2)：固定小数点后两位
    cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < n; ++i) {
        cout << std::left << std::setw(12) << students[i].name
             << std::right << std::setw(9) << students[i].chinese
             << std::setw(9) << students[i].math
             << std::setw(9) << students[i].english
             << std::setw(10) << students[i].average;
        if (students[i].average >= 90.0) {
            cout << "  Excellent";
        }
        cout << endl;
    }
    return 0;
}
