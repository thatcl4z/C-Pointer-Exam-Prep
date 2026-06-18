#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int *arrayPtr = NULL;

    // Windows Buffer Fix: Forces the questions to show immediately
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("--- Welcome to Your C Pointer Exam Prep Tool ---\n\n");
    printf("Enter how many elements you want to store: ");

    // 1. CAPTURE INPUT: Read the integer size from the keyboard
    scanf("%d", &size);

    // 2. MALLOC: Allocate dynamic memory on the Heap
    arrayPtr = (int *) malloc(size * sizeof(int));

    // 3. EXAM CRITICAL CHECK: Always check if malloc returned NULL
    if (arrayPtr == NULL) {
        printf("Error: Out of memory! Allocation failed.\n");
        system("pause");
        return 1;
    }

    // 4. FILL THE ARRAY: Using pointer arithmetic
    printf("\nEnter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", (arrayPtr + i)); // No '&' needed here!
    }

    // 5. DISPLAY THE ARRAY: Dereferencing values
    printf("\n--- Displaying Your Data ---\n");
    for (int i = 0; i < size; i++) {
        printf("Index %d = %d (Memory Address: %p)\n", i, *(arrayPtr + i), (void*)(arrayPtr + i));
    }

    // 6. CLEAN UP: Free the rented Heap memory (Stops Memory Leaks)
    free(arrayPtr);
    arrayPtr = NULL; // Clear pointer tracker for safety

    printf("\nMemory successfully freed. Program exiting cleanly.\n");

    // WINDOWS FIX: Keeps the black command window open so you can read and type!
    system("pause");

    return 0;
}

/*
 * main.c
 *
 *  Created on: 18 Jun 2026
 *      Author: clazp
 */


