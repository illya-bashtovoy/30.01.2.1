/*
Завдання 1.
 Написати такі функції для роботи з дина_мічним масивом :
    ■ Функція розподілу динамічної пам’яті;
    ■ Функція ініціалізації динамічного масиву;
    ■ Функція друку динамічного масиву;
    ■ Функція видалення динамічного масиву;
    ■ Функція додавання елемента в кінець масиву;
    ■ Функція вставки елемента за вказаним індексом;
    ■ Функція видалення елемента за вказаним індексом.
*/

#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void dynamicMemory(int size);
void dynamicArray(int* arr, int size);
void printArray(const int* arr, const int size);
void dellArray(const int* arr, const int size);
void addArray(int*& arr, int& size);
void addIndex(int*& arr, int& size);
void dellIndex(int*& arr, int& size);

int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    srand(time(NULL));

    int size = 1;
    cout << "Введіть розмір size елементів масиву" << endl;
    cin >> size;

    int* arr = new int[size]; 
    dynamicMemory(size);
    dynamicArray(arr, size);
    cout << "Елементи  масиву" << endl;

    printArray(arr, size); 
    addArray(arr, size);
    cout << "Елементи масиву з додавання елемента в кінець масиву" << endl;

    printArray(arr, size); 
    addIndex(arr, size);
    cout << "Елементи масиву із вставкою елемента за вказаним індексом" << endl;

    printArray(arr, size); 
    dellIndex(arr, size);
    cout << "Елементи масиву із видаленням елемента за вказаним індексом" << endl;

    printArray(arr, size - 1); 
    delete[]arr;
}


void dynamicMemory(int size) {
    int* arr = new int[size];
}


void dynamicArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}


void printArray(const int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << "arr [" << i << "] =" << " " << arr[i] << "\n";
    }
    cout << endl;
}


void dellArray(const int* arr, const int size) {
    delete[] arr;
}


void addArray(int*& arr, int& size) {
    int element;
    int* nArr = new int[size + 1];
    cout << "Введіть будь-яке число" << endl;
    cin >> element;

    for (int i = 0; i < size; i++) {
        nArr[i] = arr[i];
    }
    nArr[size++] = element;
    delete[]arr;
    arr = nArr;

}


void dellIndex(int*& arr, int& size) {
    int index; 
    int* nArr = new int[size - 1]; 
    cout << "Введіть індекс масиву" << endl;
    cin >> index;

    if (index >= 0 and index < size) {
        for (int i = 0; i < size; i++) {
            nArr[i] = arr[i]; 
        }
        nArr[index] = arr[index + 1];

        for (int i = index; i < size; i++) {
            nArr[i] = arr[i + 1];
        }
        arr = nArr; 
    }

    else {
        cout << " Невірний індекс" << endl;
    }
}


void addIndex(int*& arr, int& size) {
    int element; 
    int index; 
    int* nArr = new int[size]; 

    cout << "Введіть будь-яке число" << endl;
    cin >> element;
    cout << "Введіть індекс масиву" << endl;
    cin >> index;

    if (index >= 0 and index < size) {
        for (int i = 0; i < size; i++) {
            nArr[i] = arr[i]; 
        }

        nArr[index] = arr[index - 1]; 

        for (int i = size; i < index; i--) {
            nArr[i] = arr[i - 1]; 
        }
        nArr[index] = element; 
        arr = nArr; 
    }

    else {
        cout << "\t Невірний індекс :/" << endl;
    }
}