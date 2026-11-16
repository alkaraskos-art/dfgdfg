#include <time.h>

double vst(int *arr, int n) {
    int i, j, key;

    // 1. Засекаем время СТАРТА
    clock_t start = clock();

    // Алгоритм сортировки вставками
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Сдвигаем элементы, которые больше чем key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    // 2. Засекаем время ОКОНЧАНИЯ
    clock_t end = clock();

    // Возвращаем разницу в секундах
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}
