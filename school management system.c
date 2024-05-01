#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    int rollNumber;
    char firstName[50];
    char course[50];
    struct Student* next;
};

struct Student* head = NULL;

// Function prototypes
void addStudent();
void findStudentByRollNumber();
void findStudentByFirstName();
void findStudentsInCourse();
void countStudents();
void deleteStudent();
void updateStudent();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                findStudentByRollNumber();
                break;
            case 3:
                findStudentByFirstName();
                break;
            case 4:
                findStudentsInCourse();
                break;
            case 5:
                countStudents();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                updateStudent();
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    } while(choice != 8);

    return 0;
}

// Function to add student details
void addStudent() {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter roll number: ");
    scanf("%d", &newStudent->rollNumber);
    printf("Enter first name: ");
    scanf("%s", newStudent->firstName);
    printf("Enter course: ");
    scanf("%s", newStudent->course);
    newStudent->next = head;
    head = newStudent;
    printf("Student added successfully.\n");
}

// Function to find student by roll number
void findStudentByRollNumber() {
    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);
    struct Student* current = head;
    int found = 0;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            printf("Student found: Roll Number: %d, Name: %s, Course: %s\n", current->rollNumber, current->firstName, current->course);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found)
        printf("Student with Roll Number %d not found.\n", rollNumber);
}

// Function to find student by first name
void findStudentByFirstName() {
    char firstName[50];
    printf("Enter first name to search: ");
    scanf("%s", firstName);
    struct Student* current = head;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->firstName, firstName) == 0) {
            printf("Student found: Roll Number: %d, Name: %s, Course: %s\n", current->rollNumber, current->firstName, current->course);
            found = 1;
        }
        current = current->next;
    }
    if (!found)
        printf("Student with First Name %s not found.\n", firstName);
}

// Function to find students registered in a course
void findStudentsInCourse() {
    char course[50];
    printf("Enter course to search: ");
    scanf("%s", course);
    struct Student* current = head;
    printf("Students registered in course %s:\n", course);
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->course, course) == 0) {
            printf("Roll Number: %d, Name: %s\n", current->rollNumber, current->firstName);
            found = 1;
        }
        current = current->next;
    }
    if (!found)
        printf("No students found in course %s.\n", course);
}

// Function to count students
void countStudents() {
    int count = 0;
    struct Student* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("Total number of students: %d\n", count);
}

// Function to delete a student
void deleteStudent() {
    int rollNumber;
    printf("Enter roll number of student to delete: ");
    scanf("%d", &rollNumber);
    struct Student* current = head;
    struct Student* prev = NULL;
    int found = 0;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
    if (!found)
        printf("Student with Roll Number %d not found.\n", rollNumber);
}

// Function to update student details
void updateStudent() {
    int rollNumber;
    printf("Enter roll number of student to update: ");
    scanf("%d", &rollNumber);
    struct Student* current = head;
    int found = 0;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            printf("Enter new first name: ");
            scanf("%s", current->firstName);
            printf("Enter new course: ");
            scanf("%s", current->course);
            printf("Student details updated successfully.\n");
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found)
        printf("Student with Roll Number %d not found.\n", rollNumber);
}

// Function to display menu options
void displayMenu() {
    printf("\n** School Management System Menu **\n");
    printf("1. Add Student Details\n");
    printf("2. Find Student by Roll Number\n");
    printf("3. Find Student by First Name\n");
    printf("4. Find Students registered in a Course\n");
    printf("5. Count of Students\n");
    printf("6. Delete a Student\n");
    printf("7. Update Student\n");
    printf("8. Exit\n");
}