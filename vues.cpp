#include "vues.h"

COORD coord = {0,0};

void gotoxy(int x,int y){
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void Student :: Show(){

    cout << "\n\n\n\t\t\tFull Name : " << Get_Full_Name() << endl;
    cout << "\n\t\t\tStudent ID: " << Get_ID() << endl;
    cout << "\n\t\t\tDepartment: " << Get_Department() << endl;
    cout << "\n\t\t\tCGPA      : " << Get_CGPA() << endl;
    cout << "\n\t\t\tSemester  : " << Get_Semester() << endl;
    cout << "\n\t\t\tMark      : " << Get_Mark() << endl;
    cout << "\n\n\n\t\t\t------------------------------\n" << endl;
}
string Info :: pass_gen() {
    char a[50],b;
    int i=0;

    while(1){
        b = getch();
        if(b == 13) break;
        printf("%c",260);
        a[i++] = b;

    }
    a[i] = '\0';
    return a;
}
