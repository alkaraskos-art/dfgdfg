#include "bubblesort.h"
#include <time.h> // Обязательно для clock()

double bs(int *arr, int n) {
    int i, j, temp;
    
    // 1. Засекаем время СТАРТА
    clock_t start = clock();
    
    // Ваш текущий код сортировки
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // 2. Засекаем время ОКОНЧАНИЯ
    clock_t end = clock();
    
    // 3. Считаем секунды и возвращаем результат
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

