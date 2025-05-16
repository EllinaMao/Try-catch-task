#include <iostream>
#include <string>
#include <stdexcept>
//#include "task1.h"
#include "mystack.h"
using namespace std;


/*
Задание 1
Написать функцию вычисления значения по заданной строке символов, являющихся записью этого числа в десятичной системе исчисления.
Предусмотреть случай выхода за границы диапазона определяемого типом int.

Используйте механизм исключений.

Задание 2

Перепишите класс stack одного из предыдущих домашних заданий таким образом, чтобы генерировать исключения для такого количества условий, какое вы считаете приемлемым.

Например, невозможность выделить нужное количество памяти, переполнение стека и т.д.
*/
int main()
{
#ifdef TASK1
	string str("-12456");
	string errorStr("blaba123");

	try {
		cout << "String: " << str << " -> Integer: " << StringMetods::stringToInt(str) << endl;
		cout << "String: " << errorStr << " -> Integer: " << StringMetods::stringToInt(errorStr) << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Invalid argument: " << e.what() << endl;
	}
	catch (const overflow_error& e) {
		cout << "Overflow error: " << e.what() << endl;
	}
	catch (const exception& e) {
		cout << "Exception: " << e.what() << endl;
	}

#endif //TASK1
#ifdef MYSTACK
    try {
        Stack<int> s;

        // Push elements
        for (int i = 0; i < 5; ++i) {
            s.Push(i);
        }

        // Output stack contents
        cout << "Stack contents: ";
        s.Output();

        // Pop all elements
        while (!s.IsEmpty()) {
            cout << "Popped: " << s.Pop() << endl;
        }

        // Try popping from empty stack to trigger exception
        cout << "Attempting to pop from empty stack..." << endl;
        s.Pop();
    }
    catch (const overflow_error& e) {
        cerr << "Overflow error: " << e.what() << endl;
    }
    catch (const underflow_error& e) {
        cerr << "Underflow error: " << e.what() << endl;
    }
    catch (const bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Other exception: " << e.what() << endl;
    }

#endif // MYSTACK
    return 0;
}

