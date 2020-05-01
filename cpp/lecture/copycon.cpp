#include <iostream>
#include <cstring>
using namespace std;

class Student
{
  int id;
  char* name;

  public :
    Student(int n, const char* s);
    ~Student(){cout << "delete " << (void*)name << endl;delete[] name;}
    Student(const Student& std);
    void setName(const char* sname);
    void print();
};

Student::Student(int n, const char* s) : id(n)
{
  name = new char[strlen(s) + 1];
  strcpy(name, s);
}
Student::Student(const Student& std)
{
  id = std.id;
  //cout << "copy " << &std.name << " / " << &name << endl;
  name = std.name;
  //cout << "copy " << (void*)std.name << " : " << std.name << " / " << (void*)name << " : " << name << endl;
}
void Student::setName(const char* sname)
{
  cout << "delete " << (void*)name << endl;
  delete[] name;
  name = new char[strlen(sname) + 1];
  name = new char[strlen(sname) + 1];
  cout << "make " << (void*)name << endl;
  strcpy(name, sname);
}
void Student::print()
{
  cout << (void*)name << " / " << name << endl;
}

int main(void)
{
  Student s1(10, "KIM");
  Student s2(s1);
  Student s3 = s2;
  //s1.print();
  //s2.print();
  s2.setName("TEST");
  s1.print();
  s2.print();
  s3.print();
}
