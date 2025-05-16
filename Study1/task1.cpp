#include "task1.h"

int StringMetods::stringToInt(const string& str)
{
	long long result = 0;
	bool isNegative = false;
	size_t startIndex = 0;
	if (str.empty()) {
		throw invalid_argument("Input string is empty");
	}
	// поиск знака числа
	if (str[0] == '-') {
		isNegative = true;
		startIndex = 1;
	}
	else if (str[0] == '+') {
		startIndex = 1;
	}
	//проверка на наличие лишних символов
	for (size_t i = startIndex; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			throw invalid_argument("Invalid character in input string");
		}
		result = result * 10 + (str[i] - '0');
		if (result > numeric_limits<int>::max()) {
			throw overflow_error("Integer overflow");
		}
	}
	//если число отрицательное, то результат будет отрицательным
	if (isNegative) {
		result = -result;
	}
	// проверка на переполнение
	if (result < numeric_limits<int>::min()) {
		throw overflow_error("Integer underflow");
	}
	// не обязательно, можно просто вернуть result, но ругался сонар
	return static_cast<int>(result);
}