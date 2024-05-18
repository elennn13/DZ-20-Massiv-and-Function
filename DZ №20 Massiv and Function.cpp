#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
// заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], int size, T left, T right) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (right - left) + left;// Генерация случайного числа от left до right
}

// вывод массива консоль
template <typename T>
void print_arr(T arr[], int size) {
	std::cout << "{ ";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

// Функция для поиска индекса первого вхождения элемента в массиве
template <typename T>
int search_index(T arr[], int size, T element, int begin = 0) {
	for (int i = begin; i < size; i++) {
		if (arr[i] == element) {
			return i;
		}

	}
	return -1; // Если элемент не найден, возвращаем -1
}

// Функция для поиска индекса последнего вхождения элемента в массиве
template <typename T>
int search_last_index(T arr[], int size, T element) {
	for (int i = size - 1; i >= 0; i--) {
		if (arr[i] == element) {
			return i;
		}
	}
	return -1; // Если элемент не найден, возвращаем -1
}

// Перегруженная функция для поиска индекса последнего вхождения элемента в массиве
template <typename T>
int search_last_index(T arr[], int size, T element, int begin) {
	for (int i = size - 1; i >= begin; i--) {
		if (arr[i] == element) {
			return i;
		}
	}
	return -1; // Если элемент не найден, возвращаем -1
}
// Функция возвращает значение минимального элемента
template <typename T>
T arr_min(T arr[], int size) {
	T min = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}


// Функция нахождения максимального элемента в массиве
template <typename T>
T arr_max(T* arr, int size) {
	T max_val = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max_val) {
			max_val = arr[i];
		}
	}
	return max_val;
}

// Функция для нахождения среднего арифметического элементов массива
template <typename T>
double mean_value(T* arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum / size;
}

// Функция выводит все элементы массива, которые входят в переданный в функцию диапазон
template <typename T>
void range(T* arr, int size, T left, T right) {
	std::cout << "Элементы массива в диапазоне от " << left << " до " << right << ": ";
	for (int i = 0; i < size; i++) {
		if (arr[i] >= left && arr[i] < right) {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << std::endl;
}

// Функция для подсчета количества вхождений переданного элемента в массиве
template <typename T>
int count(T* arr, int size, T element) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == element) {
			count++;
		}
	}
	return count;
}

//// Функция для сортировки массива методом пузырька
template <typename T>
void bubble_sort(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "ru");

	// Задание
	// Создайте пустой массив длиною в 20 элементов.Создайте
	// следующие шаблонные функции для работы с этим массивом и
	// продемонстрируйте их работу, поочерёдно вызывая их :
	// 1.fill_arr – заполняет массив случайными числами из
	// переданного в функцию диапазона чисел от left до right(само
	// число right не должно быть включено в диапазон).С помощью
	// данной функции заполните массив числами от - 50 до 50
	// включительно;

	std::cout << "Задача 1.\n";
	const int size = 20;
	int arr[size];
	fill_arr(arr, size, -50, 50);

	std::cout << "Изначальный массив:\n";
	print_arr(arr, size);// 2.print_arr – выводит массив в консоль;

	// 3.search_index – возвращает индекс первого вхождения
	// элемента в массив.Содержит параметр по умолчанию begin = 0
	// на случай, если будет необходимо начать поиск с определённой
	// позиции массива;
	
		int element = 15;
		int index = search_index(arr, size, element);
		if (index != -1) {
			std::cout << "Индекс первого вхождения числа " << element << ": " << index << std::endl;
		}
		else {
			std::cout << "Число " << element << " не найдено в массиве" << std::endl;
		}


	// 4.search_last_index – возвращает индекс последнего
	// вхождения элемента в массив.Функция должна быть
	// перегруженной на случай, если будет необходимо начать поиск
	// с определённой позиции массива;

		int element ;
		std::cout << "Введите число -> ";
		std::cin >> element;
	int index = search_last_index(arr, size, element);
	if (index != -1) {
		std::cout << "Индекс последнего вхождения числа " << element << ": " << index << std::endl;
	}
	else {
		std::cout << "Число " << element << " не найдено в массиве" << std::endl;
	}

	int begin = 10;
	index = search_last_index(arr, size, element, begin);
	if (index != -1) {
		std::cout << "Индекс последнего вхождения числа " << element << " начиная с позиции " << begin << ": " << index << std::endl;
	}
	else {
		std::cout << "Число " << element << " не найдено в массиве, начиная с позиции " << begin << std::endl;
	}
	return 0;
	}
	
	// 5.arr_min – возвращает значение минимального элемента массива;

	std::cout << "Min: " << arr_min(arr,0) << std::endl;
	return 0;

}



// 6.arr_max – возвращает значение максимального элемента массива;

int max_value = arr_max(arr, size); // Находим максимальный элемент массива
std::cout << "Максимальный элемент в массиве: " << max_value << std::endl;

return 0;
}


// 7.mean_value – возвращает среднее арифметическое всех элементов массива;
double average = mean_value(arr, size); // Находим среднее арифметическое элементов массива
std::cout << "Среднее арифметическое элементов массива: " << average << std::endl;

return 0;
}


// 8.range – выводит все элементы массива, которые входят в переданный в функцию диапазон;
	range(arr, size, -20, 10); // Выводим элементы массива, попадающие в диапазон от -20 до 10

	return 0;
}


// 9.count – возвращает количество вхождений переданного элемента в массив;
	int element = 10;
	int occurrences = count(arr, size, element);
	std::cout << "Количество вхождений элемента " << element << " в массиве: " << occurrences << std::endl;

	return 0;
}

// 10. bubble_sort – сортирует массив по возрастанию с
// помощью пузырькового метода сортировки.
	bubble_sort(arr, size); // Сортируем массив

	std::cout << "Массив после сортировки:\n";
	print_arr(arr, size);

	return 0;
}


