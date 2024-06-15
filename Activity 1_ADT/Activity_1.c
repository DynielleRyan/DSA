#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
  char name[50];
  int age;
  struct Student* next;
} Student;

Student* head = NULL;  //global declaration para accesible sa tanan funcs


void insertFront(Student* new_student);
void insertRear(Student* new_student);
void insertByIndex(int index, Student* new_student);
void displayList();
void swap(Student* a, Student* b);
void sortByAge();

int main() {
  int choice, index;
  Student* new_student;

  while (1) {
    printf("\n1. Insert at Front\n");
    printf("2. Insert at Rear\n");
    printf("3. Insert by Index\n");
    printf("4. Display List\n");
    printf("5. Sort by Age\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        new_student = malloc(sizeof(Student));
        printf("Enter Name: ");
        scanf("%s", new_student->name);
        printf("Enter Age: ");
        scanf("%d", &new_student->age);
        insertFront(new_student);
        break;

      case 2:
        new_student = malloc(sizeof(Student));
        printf("Enter Name: ");
        scanf("%s", new_student->name);
        printf("Enter Age: ");
        scanf("%d", &new_student->age);
        insertRear(new_student);
        break;

      case 3:
        printf("Enter Index (0-based): ");
        scanf("%d", &index);
        if (index < 0) {
          printf("Invalid index\n");
          break;
        }
        new_student = malloc(sizeof(Student));
        printf("Enter Name: ");
        scanf("%s", new_student->name);
        printf("Enter Age: ");
        scanf("%d", &new_student->age);
        insertByIndex(index, new_student);
        break;

      case 4:
        displayList();
        break;

      case 5:
        sortByAge();
        printf("List sorted by age\n");
        break;

      case 6:
        exit(0);

      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

// Inserts a student at the front of the list
void insertFront(Student* new_student) {
  new_student->next = head;
  head = new_student;
}

// Inserts a student at the rear of the list
void insertRear(Student* new_student) {
  Student* temp = head;

  if (head == NULL) {
    head = new_student;
    return;
  }

  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_student;
  new_student->next = NULL;
}

// Inserts a student at a specific index in the list
void insertByIndex(int index, Student* new_student) {
  Student* temp = head;
  int count = 0;

  if (index == 0) {
    insertFront(new_student);
    return;
  }

  while (temp != NULL && count < index - 1) {
    temp = temp->next;
    count++;
  }

  if (temp == NULL || index < 0) {
    printf("Invalid index\n");
    return;
  }

  new_student->next = temp->next;
  temp->next = new_student;
}

// Displays the list of students
void displayList() {
    Student* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nStudent List:\n");
    while (temp != NULL) {
        printf("Name: %s, Age: %d\n", temp->name, temp->age);
        temp = temp->next;
    }
}



