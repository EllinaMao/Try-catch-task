#pragma once
#ifndef MYSTACK
#define MYSTACK
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
private:
	//// Нижняя и верхняя границы стека
	//enum { EMPTY = -1, FULL = 20 }; 
	//// Массив для хранения данных
	//T stack[FULL + 1]; 
	//// Указатель на вершину стека
	//int top; 

	static const int EMPTY = -1; // Константа для обозначения пустого стека
	T* stack;	// Указатель на массив данных
	size_t capacity;	// Текущая емкость стека
	int top;	// Указатель на вершину стека
	size_t stackExpand = 20;


public:
	// Конструктор
	Stack();
	~Stack();
	void Resize();
	void Push(T c);	// Добавление элемента
	T Pop();	// Извлечение элемента
	void Clear();	// Очистка стека
	void SecureClear(); // Полностью очищает стек, сбрасывая все элементы массива, на случай если там сложные елементы
	bool IsEmpty() const;	// Проверка существования элементов в стеке
	bool IsFull() const;	// Проверка на переполнение стека
	int GetCount() const;	// Количество элементов в стеке
	void Output() const
	{
		for (int i = 0; i < top + 1; i++)
		{
			cout << stack[i] << " ";
		}
		cout << endl;
	}
};

template <typename T>
Stack<T>::Stack() : capacity(20), top(-1){
try {
	stack = new T[capacity];
}
catch (const bad_alloc&) {
	throw; // Генерируем исключение, если не удалось выделить память
}
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] stack;
}

template<typename T>
inline void Stack<T>::Resize()
{
	size_t newCapacity = capacity + stackExpand;
	T* newStack = nullptr;
	try {
		newStack = new T[newCapacity];
	}
	catch (const std::bad_alloc&) {
		throw; 
	}
	for (int i = 0; i <= top; i++)
	{
		newStack[i] = stack[i];
	}
	delete[] stack;
	stack = newStack;
	capacity = newCapacity;
}

template <typename T>
void Stack<T>::Clear()
{
	// Эффективная "очистка" стека 
	// (данные в массиве все еще существуют, 
	// но функции класса, ориентированные на работу с вершиной стека,
	// будут их игнорировать)

	// Данные в массиве остаются нетронутыми.
	// Для полной очистки данных используйте SecureClear().
	top = EMPTY;
}

template<typename T>
inline void Stack<T>::SecureClear()
{
	// Полностью очищает стек, сбрасывая все элементы массива
	// и вызывая их деструкторы.
	for (int i = 0; i <= top; i++)
	{
		stack[i] = T(); // Сбрасываем элементы массива
	}
	top = EMPTY; // Сбрасываем указатель на вершину
}


template <typename T>
bool Stack<T>::IsEmpty() const
{
	// Пуст?
	return top == EMPTY;
}

template <typename T>
bool Stack<T>::IsFull() const
{
	// Полон?
	return top == capacity - 1;
}

template <typename T>
int Stack<T>::GetCount() const
{
	// Количество присутствующих в стеке элементов
	return top + 1;
}

template <typename T>
void Stack<T>::Push(T c)
{
	if (IsFull())
	{
		try {
			Resize();
		}
		catch (const bad_alloc&) {
			throw overflow_error("Stack overflow: cannot allocate more memory.");
		}
	}
	stack[++top] = c;
}

template <typename T>
T Stack<T>::Pop()
{
	// Если в стеке есть элементы, то возвращаем верхний и
	// уменьшаем указатель на вершину стека
	if (IsEmpty()) {

		throw std::underflow_error("Stack underflow: cannot pop from empty stack.");
	}
	else
	{
		return stack[top--];
	}

}
#endif // MYSTACK