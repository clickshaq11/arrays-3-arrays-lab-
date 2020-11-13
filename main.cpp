#include <fstream>
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <sstream>

const int SIZE = 5;
int getArraySize();
void countEqualElements(int* array, int size);
void execArrayOne();
void execArrayTwo();
void execArrayThree();

int main() {
	setlocale(LC_ALL, "Rus");
	srand(static_cast<unsigned int>(time(NULL)));
	execArrayOne();
	execArrayTwo();
	execArrayThree();
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

void execArrayOne() {
	int array1[SIZE] = {};
	for (int i = 0; i < SIZE; i++) {
		array1[i] = rand() % 2;
	}
	countEqualElements(array1, SIZE);
}

void execArrayTwo() {
	int N;
	N = getArraySize();
	if (N == 0) {
		std::cout << "Невозможно подсчитать кол-во значение так как количество элементов равно 0.";
	}
	while (N < 0) {
		std::cout << "Неверное значение количества элементов";
		N = getArraySize();
	}
	int* array2 = new int[N];
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < N; i++) {
		array2[i] = rand() % 2;
		std::cout << array2[i] << " ";
	}
	countEqualElements(array2, N);
	delete[] array2;
}

void execArrayThree() {
	std::ifstream inFile;
	std::string path = "test.txt";
	inFile.open(path);
	if (inFile.is_open()) {
		std::cout << "success" << "\n";
	}
	else {
		std::cout << "failure" << "\n";
	}
	std::string curStr;
	std::string curStr2;
	//
	while (!(inFile.eof())) {
		std::getline(inFile, curStr);
		int a = atoi(curStr.c_str());
		if (a <= 0) {
			throw "Количество элементов массива на одном из этапов оказалось равным нулю.";
		}
		int* array3 = new int[a];
		std::getline(inFile, curStr2);
		std::istringstream iss(curStr2);
		for (int i = 0; i < a; i++) {
			iss >> array3[i];
			std::cout << array3[i] << " ";
		}
		countEqualElements(array3, a);
		delete[] array3;
	}
	inFile.close();
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
	std::cout << "\nМаксимальное количество равных подряд идущих элементов равно: " << count << std::endl;
}