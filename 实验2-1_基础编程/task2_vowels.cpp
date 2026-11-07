// 实验2-1 任务二：统计字符串中的元音字母个数
// 考察点：指向常量的指针 const char* 遍历字符串
#include <cctype>
#include <iostream>
#include <string>

// 形参是“指向常量的指针”：函数内部只能读取 *p，不能修改字符串内容
int countVowels(const char *p) {
    int count = 0;
    while (*p != '\0') {
        // 统一转成小写，实现大小写不敏感统计
        char ch = static_cast<char>(
            std::tolower(static_cast<unsigned char>(*p)));
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++count;
        }
        ++p;  // 指针后移，指向下一个字符
    }
    return count;
}

int main() {
    std::string line;
    std::getline(std::cin, line);          // 读取一整行，可含空格
    std::cout << "Number of vowels: "
              << countVowels(line.c_str()) << std::endl;
    return 0;
}
