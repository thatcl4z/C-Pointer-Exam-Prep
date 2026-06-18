/**
 * @file gradebook.c
 * @brief Dynamic structure arrays and data management in C.
 */

#include <stdio.h>
#include <stdlib.h>

/* Define a custom structure to group student metrics */
struct Student {
    int id;
    float grade;
};

int main(void) {
    int count = 0;
    struct Student *classroom = NULL;
    float totalSum = 0.0f;

    /* Configure output buffering for real-time console communication on Windows */
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("===========================================\n");
    printf("     Dynamic Student Gradebook System      \n");
    printf("===========================================\n\n");

    printf("Enter total number of students: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        fprintf(stderr, "Error: Invalid count.\n");
        return EXIT_FAILURE;
    }

    /* MALLOC: Allocating space for an array of STRUCTURES */
    classroom = (struct Student *) malloc((size_t)count * sizeof(struct Student));

    if (classroom == NULL) {
        fprintf(stderr, "Error: Classroom allocation failed.\n");
        return EXIT_FAILURE;
    }

    /* 1. DATA ENTRY LOOP */
    printf("\n--- Enter Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nStudent #%d ID (Integer): ", i + 1);
        scanf("%d", &(classroom + i)->id); // Using arrow operator for pointers

        printf("Student #%d Grade (0.0 - 100.0): ", i + 1);
        scanf("%f", &(classroom + i)->grade);

        totalSum += (classroom + i)->grade;
    }

    /* 2. TRAVERSAL AND REPORT LOOP */
    printf("\n===========================================\n");
    printf("              CLASSROOM REPORT             \n");
    printf("===========================================\n");
    for (int i = 0; i < count; i++) {
        /* (classroom + i)->id is identical to classroom[i].id */
        printf("ID: %d | Grade: %.2f | Struct Address: %p\n",
               (classroom + i)->id,
               (classroom + i)->grade,
               (void*)(classroom + i));
    }

    /* 3. CALCULATE METRICS */
    printf("-------------------------------------------\n");
    printf("Class Average: %.2f\n", totalSum / (float)count);
    printf("===========================================\n");

    /* 4. CLEAN UP SYSTEM MEMORY */
    free(classroom);
    classroom = NULL;

    printf("\nDatabase memory released successfully.\n");
    system("pause");
    return EXIT_SUCCESS;
}

