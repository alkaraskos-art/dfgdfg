#include <time.h>
#include <stdlib.h>
#include "merge.h"
// Вспомогательная функция для слияния двух отсортированных половин
void merge(int *arr, int *temp, int left, int mid, int right) {
    int i = left;      // Индекс для левой половины
    int j = mid + 1;   // Индекс для правой половины
    int k = left;      // Индекс для временного массива

    // Сравниваем элементы из левой и правой половин и копируем меньший в temp
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Копируем оставшиеся элементы левой половины (если есть)
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Копируем оставшиеся элементы правой половины (если есть)
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Копируем обратно из временного массива в оригинальный
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// Рекурсивная функция разделения массива
void merge_sort_recursive(int *arr, int *temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Рекурсивно сортируем первую и вторую половины
        merge_sort_recursive(arr, temp, left, mid);
        merge_sort_recursive(arr, temp, mid + 1, right);

        // Сливаем отсортированные половины вместе
        merge(arr, temp, left, mid, right);
    }
}

// ГЛАВНАЯ ФУНКЦИЯ: выделяет память, запускает рекурсию и замеряет время
double merge_sort_time(int *arr, size_t n) { // Проверьте, чтобы тут было size_t // Проверьте, чтобы тут было int, а не size_t // <--- здесь size_t
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL) {
        return -1.0;
    }

    clock_t start = clock();

    // Приведение n-1 к int, так как merge_sort_recursive ожидает знаковые индексы left и right
    merge_sort_recursive(arr, temp, 0, (int)n - 1); 

    clock_t end = clock();
    free(temp);

    return ((double)(end - start)) / CLOCKS_PER_SEC;
}
