#include <stdio.h>   
#include <locale.h>
#include <windows.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[20];
    int marks;
    void (*print)(struct Student*);
};

void student_print(struct Student* student);
void student_sort(struct Student** students, int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (students[j]->marks > students[j + 1])
            {
                struct Student* temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }   
        }   
    }
}


int main() {
    struct Student student;
    student_init(&student, 1, "Ivan", 5);
    struct Student* studentP = malloc(sizeof(struct Student));
    student_init(studentP, 2, "Vasia", 4);

    strcpy(studentP->name, "Cira");

    student.print(&student);
    studentP->print(studentP);


    int const COUNT = 10;
    struct Student* students = malloc(COUNT * (sizeof(Student)));

    for (int i = 0; i < COUNT; i++)
    {
        
    }
     

}

void student_init(struct Student* student, int id, char* name, int marks) {
    student->id = id;
    strcpy(student->name, name);
    student->marks = marks;
    student->print=student_print;
}

void student_print(struct Student* student) {
    printf("%d %s %d\n", student->id, student->name, student->marks);
}



