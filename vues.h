#include <iostream>
#include <conio.h>
#include <cstdio>
#include <string>
#include <cctype>
#include <locale>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <map>

using namespace std;

class Student;
typedef string Student_Teacher_ID;
typedef map <Student_Teacher_ID,Student> MM;
typedef map <Student_Teacher_ID,Student>::iterator MIT;


class Info{
protected:
    string First_Name;
    string Last_Name;
    string Surname;
    string Faculty;
    string Department;
    string ID;
    int Age;
public:
    Info() { Age = 0;}
    ~Info() { }

    void Set_First_Name(string name) { First_Name = name ;}
    void Set_Last_Name(string name) { Last_Name = name ;}
    void Set_Surname(string name) { Surname = name ;}
    void Set_Department(string dept) { Department = dept;}
    void Set_Faculty(string faculty) { Faculty = faculty ;}
    void Set_ID(string id) { ID = id;}
    void Set_Age ( int a) { Age = a;}

    string Get_First_Name () { return First_Name ;}
    string Get_Last_Name () { return Last_Name ;}
    string Get_Surname () { return Surname ;}
    string Get_Full_Name () { return First_Name + " " + Last_Name + " " + Surname; }
    string Get_Department() { return Department;}
    string Get_Facuty () { return Faculty;}
    string Get_ID() { return ID;}
    int Get_Age() { return Age;}
    string pass_gen();
};

class Student : public Info{
protected:
    int Credit_Completed;
    double CGPA;
    double Mark;
    string Semester;///continuing semester
    ///string Courses_Results;
public:
    Student ()  { Mark = 0; CGPA = 0;}
    ~Student () { }
    void Set_Credit_Completed(int a) { Credit_Completed = a;}
    void Set_CGPA(double a) { CGPA = a;}
    void Set_Semester(string a) { Semester = a;}
    void Set_Mark(double a) { Mark = a;}

    int Get_Credit_Completed () {return Credit_Completed;}
    double Get_CGPA () {return CGPA;}
    double Get_Mark () {return Mark;}
    string Get_Semester () {return Semester;}

    void Show();
};


void gotoxy(int x,int y);
