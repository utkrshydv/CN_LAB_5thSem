#include <stdio.h>
#include <string.h>

struct dob{
  int day;
  int month;
  int year;
};

struct student_info{
  int roll_no;
  char name[50];
  float cgpa;
  struct dob age;
};

void printByValue(struct student_info s){
  printf("\n[Call-by-Value Function Output]\n");
  printf("Roll No: %d\n", s.roll_no);
  printf("Name: %s\n", s.name);
  printf("CGPA: %.2f\n", s.cgpa);
  printf("DOB: %02d-%02d-%04d\n", s.age.day, s.age.month, s.age.year);
}

void printByAddress(struct student_info *s){
  printf("\n[Call-by-Address Function Output]\n");
  printf("Roll No: %d\n", s->roll_no);
  printf("Name: %s\n", s->name);
  printf("CGPA: %.2f\n", s->cgpa);
  printf("DOB: %02d-%02d-%04d\n", s->age.day, s->age.month, s->age.year);
}

int main(){
  struct student_info student;

  student.roll_no = 23053172;
  strcpy(student.name, "utkarsh");
  student.cgpa = 5.00;
  student.age.day = 01;
  student.age.month = 01;
  student.age.year = 2004;

  printByAddress(&student);
  printByValue(student);

  return 0;
}