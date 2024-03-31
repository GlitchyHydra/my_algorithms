#pragma once

/*
* convert string to integer
* ensures overflow within -2147483647 - 1 to 2147483647 range 
*/
bool stoi (const std::string& str, int& num);

/*
* Peform operations like * and + with numbers in a string.
* We assume that string is in valid format (starts with number, has only digits and *+
* and a number follows by an operation)
* example: "12+1*1*5+2*3+13" -> 36
*/
int perform_mul_sum_operations (const std::string& str);