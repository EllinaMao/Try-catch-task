#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;

/*
Написать функцию вычисления значения по заданной строке символов, являющихся записью этого числа в десятичной системе исчисления.
Предусмотреть случай выхода за границы диапазона определяемого типом int.

Используйте механизм исключений.
*/
class StringMetods {
public:
	static int stringToInt(const string& str);
};