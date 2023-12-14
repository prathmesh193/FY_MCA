#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    char name[50];
    float percentage;
};

// Function to perform Bubble Sort on the student array based on Percentage
void bubbleSort(struct Student students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].percentage < students[j + 1].percentage) {
                // Swap the students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for the student array
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    // Input details of each student
    for (int i = 0; i < n; ++i) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    // Perform Bubble Sort to arrange students in descending order of Percentage
    bubbleSort(students, n);

    // Display the sorted student list
    printf("\nTop Ten Toppers:\n");
    printf("Rank\tName\t\tPercentage\n");
    for (int i = 0; i < (n < 10 ? n : 10); ++i) {
        printf("%d\t%s\t\t%.2f\n", i + 1, students[i].name, students[i].percentage);
    }

    // Free allocated memory
    free(students);

    return 0;
}
