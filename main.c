#include <stdio.h>
#include "array.h"
#include "vst.h"
#include "bubblesort.h"
#include "merge.h"
int main() {

	int size = 10000;

	int arr[size];

	fill_array(arr, size);

	int n = sizeof(arr) / sizeof(arr[0]);

	// Вызываем сортировку и сохраняем возвращенное время
	double time_taken = bs(arr, n);

	// Выводим время в main
	printf("Сортировка bble завершена!\n");
	printf("Время выполнения: %f секунд\n", time_taken);
	fill_array(arr, size);
	time_taken = vst(arr, n);

        // Выводим время в main
        printf("Сортировка vst завершена!\n");
        printf("Время выполнения: %f секунд\n", time_taken);
	fill_array(arr, size);
	time_taken = merge_sort_time(arr, n);

        // Выводим время в main
        printf("Сортировка merge завершена!\n");
        printf("Время выполнения: %f секунд\n", time_taken);


    return 0;
}
