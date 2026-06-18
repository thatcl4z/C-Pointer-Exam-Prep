#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Demonstrates runtime memory allocation and pointer arithmetic.
 */
int main(void) {
    int capacity = 0;
    int *dataBuffer = NULL;

    /* Disable console buffering for Windows terminal execution */
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Enter buffer allocation capacity: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        fprintf(stderr, "Error: Invalid buffer capacity.\n");
        return EXIT_FAILURE;
    }

    /* Allocate runtime memory segment on the heap */
    dataBuffer = (int *) malloc((size_t)capacity * sizeof(int));
    if (dataBuffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    /* Populate the data buffer using pointer arithmetic */
    printf("\nInput %d integer values:\n", capacity);
    for (int i = 0; i < capacity; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", (dataBuffer + i));
    }

    /* Output values with corresponding physical memory locations */
    printf("\n--- Buffer Content Analysis ---\n");
    for (int i = 0; i < capacity; i++) {
        printf("Index %d | Value: %d | Address: %p\n",
               i, *(dataBuffer + i), (void*)(dataBuffer + i));
    }

    /* Deallocate heap resources */
    free(dataBuffer);
    dataBuffer = NULL;

    system("pause");
    return EXIT_SUCCESS;
}
