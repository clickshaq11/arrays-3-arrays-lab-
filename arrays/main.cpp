#include <fstream>
#include <iostream>
#include <time.h>

const int SIZE = 5;
//123
int getArraySize();
void countEqualElements(int* array, int size);

int main() {
	setlocale(LC_ALL, "Rus");
	//
	int array1[SIZE] = { 1, 1, 1, 1, 1 };
	countEqualElements(array1, SIZE);
	//
	int N;
	N = getArraySize();
	int* array2 = new int[N];
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < N; i++) {
		array2[i] = rand() % 2;
		std::cout << array2[i] << " " ;
	}
	countEqualElements(array2, N);
	delete[] array2;
	//
	std::ifstream inFile;

	return 0;
}

int getArraySize() {
	int s;
	while (!(std::cin >> s)) {
		std::cin.clear();
		std::cin.get();
		std::cout << "Введено неверное значение размера массива." << std::endl;
	}
	return s;
}

void countEqualElements(int* array, int size) {
	int count = 1;
	int countBuffer = 1;
	for (int i = 1; i < size; i++) {
		if (array[i-1] == array[i]) {
			countBuffer += 1;
		}
		else {
			if (countBuffer > count) {
				count = countBuffer;
			}
			countBuffer = 1;
		}
	}
	if (countBuffer > count) {
		count = countBuffer;
	}
	std::cout << "\nМаксимальное количество подряд идущих элементов равно: " << count << std::endl;
}