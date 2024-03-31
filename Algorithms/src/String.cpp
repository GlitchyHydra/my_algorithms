#include "hzpch.h"
#include "Strings.h"

bool stoi(const std::string& str, int& num) {
    if (str.empty()) {
        return false;
    }

    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i = 1;
    else if (str[0] < '0' || str[0] > '9')
        return false;

    num = 0;
    for (; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9')
            return false;

        int digit = str[i] - '0';
        //check whether it would overflow
        if (str[0] != '-' && num > (INT_MAX - digit) / 10 ||
            num < (INT_MIN + digit) / 10)
            return false;

        if (str[0] == '-')
            num = num * 10 - digit;
        else 
            num = num * 10 + digit;
    }
    return true;
}

int read_number (const std::string& str, int& i) {
    int num = 0;
    while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

int perform_mul_sum_operations (const std::string& str) {
    int num1 = 0;
    int res = 0;
    char oper = 'a';
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int num2 = read_number(str, i);
            if (oper == '*') {
                num1 *= num2;
            } else  {
                res += num1;
                num1 = num2;
            }
        }
        if (i < str.length() && (str[i] == '*' || str[i] == '+'))
            oper = str[i];
    }
    return res + num1;
}