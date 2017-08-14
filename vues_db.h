#include "vues.h"

class Teacher : public Info{
protected:
    Student Student_Array;
    MM  MY_Map;
    string Notes;
    //int top ;
public:
    Teacher() { /*top = 0 ;*/}
    ~Teacher() { }
    //void Set_Students(string s) { }
    void Set_Notes ( string s ) { Notes = s ;}

    MIT Search(MM& MY_Map,int press);
    void Upload_Notes ( );
    void Upload_Notices ( );
    void Upload_Marks ( );
    void Edit_Marks ( );
    void Add_Students( ) ;
    void Show_Details_Of_One_Student( ) ;
    void Print_All_Student_Details();
    void Controler( ) ;

    void filewriting_func() ;
    void filereading_func() ;


};
void  Show_Details(string ID ,string First_Name, string Last_Name, string Surname, string Department , double CGPA, double Mark, string Semester, int Credit_Completed);
void Loading(string x,string y) ;
void Introduction();
string Convert(string& str);
void Logging_box();
