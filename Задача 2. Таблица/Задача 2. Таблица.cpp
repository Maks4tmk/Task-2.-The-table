// Задача 2. Таблица.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template<class T>
class table
{
public:

	//конструктор
	table(int row, int col) : size_row{ row }, size_col{ col } {
		create_arr();
	};


	//Конструктор копирования
	table(const table& other) {
		size_row = other.size_row;
		size_col = other.size_col;

		create_arr();

		for (int i = 0; i < other.size_row; i++) {
			for (int j = 0; j < other.size_col; i++) {
				arr[i][j] = other.arr[i][j];
			}
		}
	}


	//Перегрузка оператора []
	class proxy
	{
	public:
		proxy(T* arr, int size_col) :arr_row{ arr }, size_col{ size_col } {};
		T& operator [](int index) { 
			if (index >= size_col || index < 0) { throw std::out_of_range("Индекс выходит за пределы массива"); }
			return arr_row[index]; 
		}
	private:
		T* arr_row;
		int size_col = 0;
	};
	proxy operator [] (const int index) const { 
		if (index >= size_row || index < 0) { throw std::out_of_range("Индекс выходит за пределы массива"); }
		return proxy(arr[index], size_col);
	}
	

	//Перегрузка оператора присваивания
	table &operator = (const table& other) {
		if (this != &other) {
			size_row = other.size_row;
			size_col = other.size_col;

			this ->~table();

			create_arr();

			for (int i = 0; i < other.size_row; i++) {
				for (int j = 0; j < other.size_col; i++) {
					arr[i][j] = other.arr[i][j];
				}
			}
			return *this;
		}
		return *this;

	}


	//Функции для вывода размера массива
	const int get_size_row() {
		return size_row;
	}
	const int get_size_col() {
		return size_col;
	}


	//диструктор
	~table() {
		for (int i = 0; i < size_row; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	};

private:
	T** arr;
	int size_row = 0;
	int size_col = 0;

	//создание массива
	void create_arr() {
		arr = new T * [size_row] {};
		for (int i = 0; i < size_row; i++) {
			arr[i] = new T[size_col]{};
		}
	}
};



int main()
{
	setlocale(LC_ALL, "ru");

	auto test = table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0];
}
