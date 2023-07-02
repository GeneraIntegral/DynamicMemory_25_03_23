/*
1. В Solution Pointers добавить проект Split, и в этом проекте, массив, заполненный случайными числами разделить
   на 2 массива, минимально-возможного размера, even[] и odd[]. В массив even[] нужно скопировать все четные
   значения из исходного массива, а в массив odd[] - все нечетные значения;
2. В проекте DynamicMemory добавить значение в конец массива 'arr'. Для того чтобы добавить значение в конец
   динамического массива нужно переопределить память, т.е., выделить дополнительную область памяти нужного размера, скопировать
   туда все значения из исходного массива, удалить исходный массив, и подменить адрес исходного массива, адресом нового массива;
*/

#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()

{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

    // Вычисляем размеры массивов:
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even_count++;
		else odd_count++;
	}

    // Выделяем память для четных и нечетных элементов:
	int* even_arr = new int[even_count]; 
	int* odd_arr = new int[odd_count]; 

    // Копируем четные и нечетные элементы в соответствующие массивы:
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		/* if (arr[i] % 2 == 0) even_arr[j++] = arr[i];
		else odd_arr[k++] = arr[i]; */
        (arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}

    // Выводим результаты на экран:
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);

    // Удаляем динамические массивы:
	delete[] odd_arr;
	delete[] even_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";

	}
	cout << endl;
}