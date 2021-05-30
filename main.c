//***************************************************
//*       ███████╗██████╗ ███╗   ███╗███████╗       *
//*       ██╔════╝██╔══██╗████╗ ████║██╔════╝       *
//*       ███████╗██████╔╝██╔████╔██║███████╗       *
//*       ╚════██║██╔══██╗██║╚██╔╝██║╚════██║       *
//*	      ███████║██║  ██║██║ ╚═╝ ██║███████║       *
//*       ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝       *
//*        ================================         *
//*        Student Record Management System         *
//*        ================================         *
//***************************************************
//*                     Author                      *
//*                     ------                      *
//*                Prashant Bhandari                *
//***************************************************
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
void clrscr();
//function to clear console screen.
void gotoxy(short x, short y);
//This function places cursor at a desired location on screen i.e., we can change cursor position using gotoxy function.
/*
                      5
                      |   [120]Columns
              *-------|-----------------------> (X-axis)     Example:-
              | *-----|-------------------*                          gotoxy(5,5);
              | |     |                   |                          printf("hello");
          5 --|-|-----*hello              |
         [30] | |     (5,5)               |                  Syntax:-
         Rows | |                         |                          gotoxy(x,y);
              | |     [output screen]     |
              | |                         |                  where,
              | |                         |                        x=x-coordinate
              | |                         |                        y=y-coordinate
              | |                         |
              | *-------------------------*
              |
              V 
    
          (Y-axis)
*/
void box_single_line(int x,int y,int l,int w);
//This function is used to print single line box in output screen.
/*
                   [120]Columns
                       x(5)  
                        |   
              *---------|---------------------> (X-axis)       Example:-    
              | *-------|-----------------*                             box_single_line(5,5,5,5);
              | |       | l(5)            |
              | |       |<----->          |
       y(5)---|-|-------┌──────┐          |                    Syntax:- 
              | |     ^ │      │          |                             box_single_line(x,y,l,w);
              | |     | │ box  │          |          
              | | w(5)| │      │          |
    [30]      | |     | │      │          |                    where,
    Rows      | |     V └──────┘          |                          x=x-coordinate
              | |    [output screen]      |                          y=y-coordinate
              | |                         |                          l=length
              | *-------------------------*                          w=width
              |
              V
           (Y-axis)
*/
void box_double_line(int x,int y,int l,int w);
//This function is same as above function but used to print double line box in output screen.
/*
                        [120]Columns
						    
              *-------------------------------> (X-axis)       Example:-    
              | *-------------------------*                             box_double_line(5,5,5,5);
              | |                         |
              | |                         |
              | |       ╔══════╗          |                    Syntax:- 
              | |       ║      ║          |                            box_double_line(x,y,l,w);
              | |       ║ box  ║          |
              | |       ║      ║          |                    where,
    [30]      | |       ║      ║          |                         x=x-coordinate
    Rows      | |       ╚══════╝          |                         y=y-coordinate
              | |     [output screen]     |                         l=length
              | |                         |                         w=width
              | *-------------------------*
              |
              V
           (Y-axis)
*/
void print_menu();
//This function prints Main Menu.
void print_delmenu();
//This function prints Delete Menu.
void loading();
//This function makes loading animation
void rcreate();
//This function creates records.
void rdisplay();
//This function displays records.
void rsearch();
//This function searches records.
void rmodify();
//This function modify records.
void rdelete();
//This function deletes records.
void ralldelete();
//This function deletes all records.
void invalid_opt();
struct student
{
    int roll;
    char name[30];
    struct dateofbirth
    {
        int yy;
        int mm;
        int dd;
    }dob;
    char add[15];
    char phone[11];
    char course[8];
    int year;
    int sem;
}s;
int main()
{
    int c;
	system("color 0c");
	getch();
    a:
	print_menu();
    scanf("%d",&c);
    switch(c)
    {
        case(1):
        {
            rcreate();
            break;
        }
        case(2):
        {
            rdisplay();
            break;
        }
        case(3):
        {
            rsearch();
            break;
        }
        case(4):
        {
            rmodify();
            break;
        }
        case(5):
        {
            b:
            print_delmenu();
            scanf("%d",&c);
            switch(c)
            {
                case(1):
                {
                    rdelete();
                    break;
                }
                case(2):
                {
                    ralldelete();
					goto b;
                    break;
                }
                case(3):
                {
                    goto a;
                    break;
                }
                case(4):
                {
                    exit(0);
                }
                default:
                {
                    invalid_opt();
                    goto b;
                }
            }
            break;
        }
        case(6):
        {
            exit(0);
        }
        default:
        {
            invalid_opt();
            goto a;
        }
    }
    getch();
	return (0);
}
void clrscr()
{
    system("cls");	
}
void gotoxy(short x, short y)                                      
{
    COORD pos ={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void box_single_line(int x,int y,int l,int w)
{
	int h,i,j,k;
	gotoxy(x,y);printf("\xDA");
	gotoxy(l+x,y);printf("\xBF");
	gotoxy(l+x,w+y);printf("\xD9");
	gotoxy(x,y+w);printf("\xC0");
	for(h=x+1;h<l+x;h++)
	{
		gotoxy(h,y);printf("\xC4");
	}
	for(i=y+1;i<w+y;i++)
	{
		gotoxy(l+x,i);printf("\xB3");
	}
	for(j=x+1;j<l+x;j++)
	{
		gotoxy(j,y+w);printf("\xC4");
	}
	for(k=y+1;k<w+y;k++)
	{
		gotoxy(x,k);printf("\xB3");
	}	
}
void box_double_line(int x,int y,int l,int w)
{
	int h,i,j,k;
	gotoxy(x,y);printf("\xC9");
	gotoxy(l+x,y);printf("\xBB");
	gotoxy(l+x,w+y);printf("\xBC");
	gotoxy(x,y+w);printf("\xC8");
	for(h=x+1;h<l+x;h++)
	{
		gotoxy(h,y);printf("\xCD");
	}
	for(i=y+1;i<w+y;i++)
	{
		gotoxy(l+x,i);printf("\xBA");
	}
	for(j=x+1;j<l+x;j++)
	{
		gotoxy(j,y+w);printf("\xCD");
	}
	for(k=y+1;k<w+y;k++)
	{
		gotoxy(x,k);printf("\xBA");
	}	
}
void print_menu()
{
    clrscr();
    box_single_line(53,2,12,2);
    gotoxy(55,3);printf("MAIN MENU");
    box_double_line(20,5,80,20);
    gotoxy(45,7);printf("1) Create Student Record");
    gotoxy(45,9);printf("2) Display All Student Records");
    gotoxy(45,11);printf("3) Search Student Records");
    gotoxy(45,13);printf("4) Modify Student Records");
    gotoxy(45,15);printf("5) Delete Student Records");
    gotoxy(45,17);printf("6) Exit");
    gotoxy(50,22);printf("Your Choice:");
}
void print_delmenu()
{
    clrscr();
    box_single_line(53,2,14,2);
    gotoxy(55,3);printf("DELETE MENU");
    box_double_line(20,5,80,20);
    gotoxy(45,7);printf("1) Delete Individual Record ");
    gotoxy(45,9);printf("2) Delete All Records");
    gotoxy(45,11);printf("3) Go to Main Menu");
    gotoxy(45,13);printf("4) Exit");
    gotoxy(50,22);printf("Your Choice:");
}
void loading()
{
	clrscr();
	gotoxy(55,14);printf("LOADING...");
	gotoxy(40,15);printf("\xB1\xB1\xB1\xB1 [10%%]");
	Sleep(120);
	clrscr();
	gotoxy(55,14);printf("LOADING...");
	gotoxy(40,15);printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 [20%%]");
	Sleep(180);
	clrscr();
	gotoxy(55,14);printf("PLEASE WAIT...");
	gotoxy(40,15);printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 [35%%]");
	Sleep(300);
	clrscr();
	gotoxy(55,14);printf("PLEASE WAIT...");
	gotoxy(40,15);printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 [50%%]");
	Sleep(140);
	clrscr();
	gotoxy(55,14);printf("OPENING...");
	gotoxy(40,15);printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 [90%%]");
	Sleep(140);
	clrscr();
	gotoxy(55,14);printf("OPENING...");
	gotoxy(40,15);printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 [100%%]");
	Sleep(100);
	clrscr();
}
void rcreate()
{
    clrscr();
	FILE *fpt;
	char another = 'y';
    box_single_line(53,2,16,2);
    gotoxy(55,3);printf("CREATE RECORD");
    fpt = fopen("record.txt", "ab+");
    if(fpt==NULL)
    {
        gotoxy(10, 5);
        printf("Error opening file");
        exit(0);
    }
    fflush(stdin);
    while(another =='y')
    {
        box_double_line(20,5,80,20);
        gotoxy(10, 3);
        gotoxy(45,6);printf("Please Enter The New Details of student \n");
        gotoxy(25,9);printf("Roll Number:");
        scanf("%d",&s.roll);
        fflush(stdin);
        gotoxy(25,10);printf("Name:");
        gets(s.name);
        gotoxy(25,11);printf("Address:");
        gets(s.add);
        gotoxy(25,12);printf("Phone No:");
        gets(s.phone);
        fflush(stdin);
		gotoxy(25,13);printf("Enter Date of Birth:");
		gotoxy(25,14);printf("Year:");
        scanf("%d",&s.dob.yy);
		gotoxy(35,14);printf("Month:");
        scanf("%d",&s.dob.mm);
		gotoxy(45,14);printf("Day:");
        scanf("%d",&s.dob.dd);
		fflush(stdin);
        gotoxy(25,15);printf("Course Name:");
        gets(s.course);
        fflush(stdin);
        gotoxy(25,16);printf("Year:");
        scanf("%d",&s.year);
        gotoxy(25,17);printf("Semester:");
        scanf("%d",&s.sem);
        fwrite(&s, sizeof(s), 1, fpt);
        gotoxy(29, 22);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        clrscr();
        fflush(stdin);
    }
    fclose(fpt);
    gotoxy(10, 18);
    printf("Press any key to continue.");
    getch();
    main();
}
void rdisplay()
{
    clrscr();
	loading();
    FILE *fpt;
    int i = 1, j;
    box_single_line(53,1,15,2);
    gotoxy(55,2);printf("VIEW RECORD");
    fpt = fopen("record.txt", "rb+");
    if(fpt==NULL)
    {
        gotoxy(50,10);
        printf("Error opening file.");
        getch();
        main();
    }
    else
    {
        box_double_line(1,4,117,2);
        gotoxy(2, 5); 
        printf("S.No   Roll No    Student Name                  Address        Phone No     Date of Birth   Course   Year   Semester");
    }
    j = 8;
    while(fread(&s,sizeof(s),1,fpt)==1)
    {
        gotoxy(2, j);
        printf("%-7d%-11d%-30s%-15s%-14s%-4d/%-2d/%-7d%-10s%-10d%d",i,s.roll,s.name,s.add,s.phone,s.dob.yy,s.dob.mm,s.dob.dd,s.course,s.year,s.sem);
        i++;
        j++;
    }
	box_double_line(1,7,117,i);
    fclose(fpt);
    gotoxy(40, j + 3);
    printf("Press any key to continue.");
    getch();
    main();
}
void rsearch()
{
    clrscr();
    FILE *fpt;
    char stname[30];
    box_single_line(53,1,16,2);
    gotoxy(55,2);printf("SEAECH RECORD");
    gotoxy(10, 5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fpt = fopen("record.txt", "rb+");
    if (fpt == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(0);
    }
    while (fread(&s, sizeof(s), 1, fpt) == 1)
    {
        if (strcmp(stname,s.name) == 0)
        {
            gotoxy(10, 8);
            //printf("%-10d%-14s%-15s%-12s%-12s%-9s%-4d%-3d",s.roll,s.fname,s.lname,s.add,s.phone,s.course,s.year,s.sem);
            printf("Roll No:%d",s.roll);
            gotoxy(10, 9);
            printf("Name:%s",s.name);
            gotoxy(10, 11);
            printf("Address:%s",s.add);
            gotoxy(10, 12);
            printf("Phone Number:%s",s.phone);
			gotoxy(10, 13);
            printf("Date of Birth:%d/%d/%d",s.dob.yy,s.dob.mm,s.dob.dd);
            gotoxy(10, 14);
            printf("Course:%s",s.course);
            gotoxy(10, 15);
            printf("Year:%d",s.year);
            gotoxy(10, 16);
            printf("Semester:%d",s.sem);
        }
    }
    fclose(fpt);
    gotoxy(10, 16);
    printf("Press any key to continue.");
    getch();
    main();
}
void rmodify()
{
	clrscr();
	FILE *fpt;
    char stname[30];
    gotoxy(10, 3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10, 5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fpt = fopen("record.txt", "rb+");
    if (fpt == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fpt);
    fflush(stdin);
    while (fread(&s, sizeof(s), 1, fpt) == 1)
    {
        if (strcmp(stname,s.name) == 0)
        {
            gotoxy(25,8);printf("Roll Number:");
			scanf("%d",&s.roll);
			fflush(stdin);
			gotoxy(25,9);printf("First Name:");
			gets(s.name);
			gotoxy(25,11);printf("Address:");
			gets(s.add);
			gotoxy(25,12);printf("Phone No:");
			gets(s.phone);
			fflush(stdin);
			gotoxy(25,13);printf("Enter Date of Birth:");
			gotoxy(25,14);printf("Year:");
			scanf("%d",&s.dob.yy);
			gotoxy(35,14);printf("Month:");
			scanf("%d",&s.dob.mm);
			gotoxy(45,14);printf("Day:");
			scanf("%d",&s.dob.dd);
			fflush(stdin);
			gotoxy(25,15);printf("Course Name:");
			gets(s.course);
			fflush(stdin);
			gotoxy(25,16);printf("Year:");
			scanf("%d",&s.year);
			gotoxy(25,17);printf("Semester:");
			scanf("%d",&s.sem);
            fseek(fpt, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fpt);
            break;
        }
    }
    fclose(fpt);
    gotoxy(10, 16);
    printf("Press any key to continue.");
    getch();
    main();
}
void rdelete()
{
    
}
void ralldelete()
{
    system("del record.txt");
	clrscr();
	box_single_line(49,9,15,2);
	gotoxy(50,10);
	printf("Record Deleted");
	getch();
}
void invalid_opt()
{
	clrscr();
	box_single_line(49,9,15,2);
	gotoxy(50,10);
	printf("Invalid Option");
	getch();
	fflush(stdin);
}