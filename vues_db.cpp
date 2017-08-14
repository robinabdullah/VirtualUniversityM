#include "vues_db.h"

//void ventry(char t[50],int code)
//{
//  int i=0;
//	if(code==0)
//	{
//		while((t[i]=getch())!='\r' && i<30)
//		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
//		{
//			cout << t[i];
//			i++;
//		}
//		else if(t[i]==8 && i>0)
//		{
//			cout << t[i] << ' ' << t[i];
//			i--;              //Length counter is decremented.
//
//		}
//	}
//	else if(code==1)
//	{
//		while((t[i]=getch())!='\r' && i<10 )
//		if((t[i]>=48 && t[i]<=57) )
//		{
//			cout << t[i];
//			i++;
//		}
//		else if(t[i]==8 && i>0)
//		{
//			cout << t[i] << ' ' << t[i];
//			i--;              //Length counter is decremented.
//
//		}
//	}
//	else if(code==2)
//	{
//		while((t[i]=getch())!='\r' && i<30 )
//		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
//		{
//			cout << t[i];
//			i++;
//		}
//		else if(t[i]==8 && i>0)
//		{
//			cout << t[i] << ' ' << t[i];
//			i--;              //Length counter is decremented.
//
//		}
//	}
//
//	t[i]='\0';
//}
string Convert(string& str)/// function to convert the letter to uppercase
{
	locale settings;
	string converted;

	for(unsigned int i = 0; i < str.size(); ++i)
		converted += (toupper(str[i], settings));

	return converted;
}
void Introduction(){
    gotoxy(30,10);
    cout << "Developed by ROBIN" << endl;
    gotoxy(17,13);
    cout << "American International University-Bangladesh" ;
    Sleep(2000);
    //getch();
}



MIT Teacher :: Search(MM& MY_Map,int press){
    system("cls");
    string Inputed_Surname,Stored_Surname,To_Search;

    switch(press){
    case 49:

        gotoxy(28,7);
        cout << "Enter Surname: ";
        cin >> Inputed_Surname;

        Loading("Searching Name","Searching completed");

        for(MIT p = MY_Map.begin(); p != MY_Map.end();p++) {
            Stored_Surname = (p->second).Get_Surname();///storing the name to a variable from the vector

            Stored_Surname = Convert( Stored_Surname );///converting the letter to uppercase
            Inputed_Surname = Convert(Inputed_Surname);///converting the letter to uppercase

            if( Stored_Surname == Inputed_Surname)
                return p;
        }
        break;
    case 50:
        gotoxy(28,7);
        cout << "Enter ID: ";
        cin >> To_Search;

        Loading("Searching ID","Searching completed");
        for(MIT p = MY_Map.begin(); p != MY_Map.end();p++) {
            if( (p->second).Get_ID() == To_Search)
                return p;
        }

        break;

    default:
        gotoxy(35,16);
        cout << "Wrong Choice" << endl;
        break;
    }
    MIT p = MY_Map.end();
    return p; ///It's basically a failsafe, if none of the if conditions are met.

}
void Teacher :: filewriting_func() {
    ofstream filewrite("Student_Data.txt");
    if( filewrite.is_open() ){
        for(MIT p = MY_Map.begin(); p != MY_Map.end(); p++) {
            filewrite << p->first     << "\t"<< (p->second).Get_First_Name() << ' '
                    << (p->second).Get_Last_Name() << ' ' << (p->second).Get_Surname() << "\t"
                    << (p->second).Get_Department()<< "\t" << (p->second).Get_CGPA() << "\t"
                    << (p->second).Get_Mark()      << "\t" << (p->second).Get_Semester() << "\t"
                    << (p->second).Get_Credit_Completed() << endl;
        }
    }
    else {
        cerr << "File does't Exist" << endl;
        exit(1);
    }
    filewrite.close();
}

void Teacher :: filereading_func() {
    string First_Name;
    string Last_Name;
    string Surname;
    string ID;
    string Department;
    int Credit_Completed;
    double CGPA;
    double Mark;
    string Semester;

    ifstream fileread("Student_Data.txt");

    if(fileread.is_open()){
        while(fileread >> ID >> First_Name >> Last_Name >> Surname >> Department >> CGPA >> Mark >> Semester >> Credit_Completed)
        {
            Student_Array.Set_ID(ID);
            Student_Array.Set_First_Name(First_Name);
            Student_Array.Set_Last_Name(Last_Name);
            Student_Array.Set_Surname(Surname);
            Student_Array.Set_Department(Department);
            Student_Array.Set_CGPA(CGPA);
            Student_Array.Set_Mark(Mark);
            Student_Array.Set_Semester(Semester);
            Student_Array.Set_Credit_Completed(Credit_Completed);

            MY_Map.insert( make_pair(ID,Student_Array) ) ;
            //top++;
        }
    }
    else {
        cerr << "File does't Exist" << endl;
        exit(1);
    }
    fileread.close();
}
void  Show_Details(string ID ,string First_Name, string Last_Name, string Surname, string Department , double CGPA, double Mark, string Semester, int Credit_Completed){

    cout << "\n\n\n\t\t\tFull Name : " << First_Name + ' ' + Last_Name + ' ' + Surname  << endl;
    cout << "\n\t\t\tStudent ID: " << ID << endl;
    cout << "\n\t\t\tDepartment: " << Department << endl;
    cout << "\n\t\t\tCGPA      : " << CGPA << endl;
    cout << "\n\t\t\tSemester  : " << Semester << endl;
    cout << "\n\t\t\tCom_Credit: " << Credit_Completed << endl;
    cout << "\n\t\t\tMark      : " << Mark << endl;
    cout << "\n\n\n\t\t\t------------------------------\n" << endl;
}
void Loading(string x,string y){
    system("cls");

    gotoxy(31,11);
    cout << x;
    Sleep(500);
    cout << "." ;
    Sleep(500);
    cout << "." ;
    Sleep(500);
    cout << "." ;
    Sleep(500);

    system("cls");
    gotoxy(33,11);
    cout << y ;

    gotoxy(33,15);
    Sleep(1000);
}

void Teacher :: Add_Students() {

    filereading_func();
}

void Teacher :: Upload_Notes() {
    system("cls");
    gotoxy(23,11);
    cout << "Please Enter Section Name E or C: ";

    getch();

    gotoxy(32,7);
    cout << "Fall Notes" << endl;

    gotoxy(20,9);
    cout << "Press 1 : Introduction to OOP.pptx" << endl;

    gotoxy(20,11);
    cout << "Press 2 : A Closer Look at Classes.pptx" << endl;

    gotoxy(20,13);
    cout << "Press 3 : Arrays, Pointers, and References.pptx" << endl;

    gotoxy(20,15);
    cout << "Press 4 : Inheritance.pptx"<< endl;

    gotoxy(32,17);
    getch();

    Loading("Uploading Notes", "Notes Uploaded");
    //system("cls");

    cout << "\n\n\n\t\t\t\t" ; ///to take the "Press n to quit" in center position


}

void Teacher :: Upload_Notices() {
    system("cls");
    gotoxy(23,11);
    cout << "Please Enter Section Name E or C: " ;

    getch();

    system("cls");
    gotoxy(16,7);
    cout << "Write down the notice and Press Enter button >>\n";
    string notice;
    gotoxy(16,9);
    getline(cin,notice);

    Loading("Uploading Notices", "Notices Uploaded");
    //system("cls");

    cout << "\n\n\n\t\t\t\t" ; ///to take the "Press n to quit" in center position


}

void Teacher :: Upload_Marks() {
    system("cls");
    gotoxy(23,11);
    cout << "Please Enter Section Name E or C: " ;

    getch();
    system("cls");

    ofstream filewrite("Student_Data.txt");

    double Mark;
    cout << "\n\n" ;

    for(MIT p = MY_Map.begin(); p != MY_Map.end();p++) {
        start:
        cout << "\n\t" << p->first << "\t" << (p->second).Get_First_Name()
            << ' ' << (p->second).Get_Last_Name()
            << ' ' << (p->second).Get_Surname() << "\t";

        cout << "Enter Marks: ";
        cin >> Mark;
        if (Mark <= 100 ){
            (p->second).Set_Mark(Mark);
        }
        else{
            system("cls");
            gotoxy(25,11);
            cout << "Mark Can't be grater than 100" << endl;
            Sleep(1000);
            system("cls");
            goto start;
        }
    }


    filewriting_func();

    system("cls");
    gotoxy(25,11);
    cout << "Marks uploaded successfully" ;
    //Sleep(2000);

    cout << "\n\n\n\t\t\t     " ; ///to take the "Press n to quit" in center position

}

void Teacher :: Edit_Marks() {
    system("cls");
    gotoxy(23,11);
    cout << "Please Enter Section Name E or C: " ;

    getch();
    system("cls");


    double Mark; string ID;

    //string To_Search;

    gotoxy(27,7);
    cout << "Press 1: Search by Surname" << endl;
    gotoxy(27,9);
    cout << "Press 2: Search by ID" << endl;
    int press;
    gotoxy(35,13);
    press = getch();


    MIT it = Search(MY_Map,press);

    if( it != MY_Map.end() ){
        system("cls");
        gotoxy(25,11);
        cout << "\n\t" << it->first << "\t" << ( it->second ).Get_First_Name()
            << ' ' << ( it->second ).Get_Last_Name()
            << ' ' << ( it->second ).Get_Surname() << "\t";
        cout << "Enter Mark : ";
        cin >> Mark;
        ( it->second ).Set_Mark(Mark);
        filewriting_func();

        system("cls");
        gotoxy(27,11);
        cout << "Mark uploaded Successfully" << endl;
        cout << "\n\n\t\t\t\t" ; ///to take the "Press n to quit" in center position
    }
    else {
        system("cls");
        gotoxy(33,9);
        cout << "Not found" << endl;
        cout << "\n\n\t\t\t   " ; ///to take the "Press n to quit" in center position
    }



}


void Teacher :: Show_Details_Of_One_Student() {
    system("cls");
    gotoxy(23,11);
    cout << "Please Enter Section Name E or C: " ;

    getch();
    system("cls");

    string To_Search;

    gotoxy(27,7);
    cout << "Press 1: Search by Surname" << endl;
    gotoxy(27,9);
    cout << "Press 2: Search by ID" << endl;
    int press;
    gotoxy(35,13);
    press = getch();


    MIT it = Search(MY_Map,press);

    if( it != MY_Map.end() ){
        system("cls");
        (it->second).Show();
    }
    else{
        system("cls");
        gotoxy(33,11);
        cout << "Not found" << endl;
    }

    cout << "\n\n\n\t\t\t     " ; ///to take the "Press n to quit" in center position
}

void Teacher :: Print_All_Student_Details() {
    system("cls");
    gotoxy(23,11);
    cout << "Please Enter Section Name E or C: " ;

    getch();
    system("cls");


    gotoxy(60,1);
    cout << "DATE: 09/12/2014" ;

    gotoxy(12,5);
    cout << "Roll.    ID.             STUDENT NAME.           SIGN." << endl;

    gotoxy(12,7);
    cout << "------------------------------------------------------" << endl;

    int m = 12, n = 8, x= 1;
    for(MIT p = MY_Map.begin(); p != MY_Map.end();p++) {
        gotoxy(m,n++);
        cout << x++ << "\t    ";

        cout << p->first << "\t    "
            << ( p->second ).Get_First_Name() + ' ' + ( p->second ).Get_Last_Name() + ' '
            + ( p->second ).Get_Surname() << endl ;
    }


    cout << "\n\n\n\t\t\t\t" ; ///to take the "Press n to quit" in center position
}


void Teacher :: Controler(){
    char choice = '*' ;
    int press;

    do{
        system("cls");
        //Logging_box();
        gotoxy(27,2);
        cout << "Press 1 : Upload Notes" << endl;
        gotoxy(27,4);
        cout << "Press 2 : Upload Notices" << endl;
        gotoxy(27,6);
        cout << "Press 3 : Upload Marks" << endl;
        gotoxy(27,8);
        cout << "Press 4 : Edit Mark" << endl;
        gotoxy(27,10);
        cout << "Press 5 : Show A Student Detail" << endl;
        gotoxy(27,12);
        cout << "Press 6 : Print All Student Name & ID" << endl;
        gotoxy(27,14);
        cout << "Press 7 : Logout" << endl;


        gotoxy(37,15);

        start:

        press = getch();

        switch(press){
            case 49:
                Upload_Notes();
                break;
            case 50:
                Upload_Notices();
                break;
            case 51:
                Upload_Marks();
                break;
            case 52:
                Edit_Marks();
                break;
            case 53:
                Show_Details_Of_One_Student();
                break;
            case 54:
                Print_All_Student_Details();
                break;
            case 55:{
                gotoxy(30,11);
                Loading("Logging out","Logout successful");
                exit(0);
            }
            default:
                gotoxy(35,16);
                cout << "Press again: ";
                goto start;
        }

        cout << "Press R to Return" ;

        choice = getch();
        system("cls");
    }while(choice != '\0');

}
