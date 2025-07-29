#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct joining_date{
  int day;
  int month;
  int year;
};

struct employee{
  int emp_id;
  char name[50];
  float salary;
  struct joining_date date;
};

void printByValue(struct employee e){
  printf("\n[Call-By-Value Function Output]\n");
  printf("Emp Id: %d\n", e.emp_id);
  printf("Employee Name: %s\n", e.name);
  printf("Salary: %.2f\n", e.salary);
  printf("Joining Date: %02d-%02d-%04d\n", e.date.day, e.date.month, e.date.month);
}

void printByAddress(struct employee *e){
  printf("\n[Call-By-Address Function Output]\n");
  printf("Emp Id: %d\n", e->emp_id);
  printf("Employee Name: %s\n", e->name);
  printf("Salary: %.2f\n", e->salary);
  printf("Joining Date: %02d-%02d-%04d\n", e->date.day, e->date.month, e->date.month);
}

int main(){
  struct employee employee;

  employee.emp_id = 1;
  strcpy(employee.name, "aarush");
  employee.salary = 100000;
  employee.date.day = 01;
  employee.date.month = 01;
  employee.date.year = 2000;

  printByValue(employee);
  printByAddress(&employee);

  return 0;
}