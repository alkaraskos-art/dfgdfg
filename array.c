#include <stdlib.h>
#include <time.h>
#include "array.h"

void fill_array(int arr[], int size) {

	static int initialized = 0;
	if (!initialized) {
		srand(time(NULL));
		initialized = 1;
	}

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
	}

	return;
}
