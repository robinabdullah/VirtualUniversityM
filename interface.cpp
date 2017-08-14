#include "vues_db.h"
///***************************************************************
///                        Logging interface
///***************************************************************
void Logging_box(){
//***************************************************************
//                       Main Box
//***************************************************************
    int x=27,y=5;
    gotoxy(x++,y);
    printf("%c",201);

    for(int i = 1 ;i <= 24 ;i++){
        gotoxy(x++,y);
        printf("%c",205);
    }

    gotoxy(x,y++);
    printf("%c",187);

    for(int i = 1 ;i <= 11 ;i++){
        gotoxy(x,y++);
        printf("%c",186);
    }

    gotoxy(x--,y);
    printf("%c",188);

    for(int i = 1 ;i <= 24 ;i++){
        gotoxy(x--,y);
        printf("%c",205);
    }

    gotoxy(x,y--);
    printf("%c",200);

    for(int i = 1 ;i <= 11 ;i++){
        gotoxy(x,y--);
        printf("%c",186);
    }
//***************************************************************
//                        User Name Box
//***************************************************************
    x=29,y=7;
    gotoxy(x++,y);
    printf("%c",201);

    for(int i = 1 ;i <= 20 ;i++){
        gotoxy(x++,y);
        printf("%c",205);
    }

    gotoxy(x,y++);
    printf("%c",187);

    for(int i = 1 ;i <= 2 ;i++){
        gotoxy(x,y++);
        printf("%c",186);
    }

    gotoxy(x--,y);
    printf("%c",188);

    for(int i = 1 ;i <= 20 ;i++){
        gotoxy(x--,y);
        printf("%c",205);

    }

    gotoxy(x,y--);
    printf("%c",200);

    for(int i = 1 ;i <= 2 ;i++){
        gotoxy(x,y--);
        printf("%c",186);
    }
//***************************************************************
//                        Password Box
//***************************************************************
    x=29,y=12;
    gotoxy(x++,y);
    printf("%c",201);

    for(int i = 1 ;i <= 20 ;i++){
        gotoxy(x++,y);
        printf("%c",205);
    }

    gotoxy(x,y++);
    printf("%c",187);

    for(int i = 1 ;i <= 2 ;i++){
        gotoxy(x,y++);
        printf("%c",186);
    }

    gotoxy(x--,y);
    printf("%c",188);

    for(int i = 1 ;i <= 20 ;i++){
        gotoxy(x--,y);
        printf("%c",205);

    }

    gotoxy(x,y--);
    printf("%c",200);

    for(int i = 1 ;i <= 2 ;i++){
        gotoxy(x,y--);
        printf("%c",186);
    }
}
