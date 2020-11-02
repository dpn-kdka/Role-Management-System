/*
	File        : UTIL.c
	Description : Password creating
	Author      : Dipin Khadka
	Created     : 17 april 2011
	------------------------------------------------------------------
	Date          Version Author Description
	17 april 2011 1.01    Dipin  Added logic to password creation
	1  june  2011 1.02    Dipin  Added logic to create working screen
*/

void getPassword(int x, int y, int max, char userPassword[30])
{
/*
	Description : Password creating
	Author      : Dipin Khadka
	Created     : 17 april 2011
*/

	char ch   = NULL;
	int  i    = 0;
	int count = 0;

	while(1)
	{
		ch = getch();
		if(ch == 13)  /* for enter key  */
		{
			break;
		}
		if(ch == 8)   /* for backspace  */
		{
			gotoxy(x+i,y); printf(" ");
			if(i>0)
			{
				i--;
				count--;
			}
		}
	 else	if(i<max) /*for accepting characters until maximum level is reached*/
		{
			userPassword[i] = ch;
			i++;
			gotoxy(x+i,y); printf("*");
			count++;
		}
	}/* end of while*/
	if(count < 6) /* for displaying warning if charecters not met minimum level */
	{
		gotoxy(1,y+2); cprintf("Sorry!!! Password should be at least 6 character..");
		sleep(2);
		gotoxy(1,y+2); cprintf("                                                  ");
	}/* end of if*/
	userPassword[i] = NULL;
}/* end of getPassword*/

void bigWindow()

{
/*
	Description : For making Big Windows
	Author      : Dipin Khadka
	Created     : 8 may 2011
*/
	textbackground(bigWindowBg);
	window(1,1,80,25);
	clrscr();
}/* end of bigWindow*/

void bigWindowScreen()

{
/*
	Description : For setting screen displaying style
	Author      : Dipin Khadka
	Created     : 8 may 2011
*/
	int i = 0;
	int j = 0;

	for(i=1;i<=25;i++)
	{
		for(j=1;j<=80;j++)
		{
			gotoxy(j,i); cprintf("%c",screenCode);
		}
	}/* end of for*/

	 gotoxy(27,3); cprintf("<<<ROLE MANAGEMENT SYSTEM>>>");

}/* end of bigWindowScreen*/

void menuWindow()

{
/*
	Description : For creating Menu Windows
	Author      : Dipin Khadka
	Created     : 8 may 2011
*/
	textbackground(menuWindowBg);
	window(60,15,79,24);
	clrscr();
}/*end of menuWindow*/

void projectMembers()

{
/*
	Description : Displaying project members name
	Author      : Dipin Khadka
	Created     : 8 may 2011
*/
	gotoxy(9,19); cprintf("Project Members");
	gotoxy(5,20); cprintf("-----------------------");
	gotoxy(10,22); cprintf("DIPIN KHADKA");
	gotoxy(7,23); cprintf("SHREEKANT CHAUDHARY");

}/*end of projectMembers*/

void userPasswordWindow()
{
/*
	Description : For creating userpassword Windows
	Author      : Dipin Khadka
	Created     : 29 may 2011
*/
	textbackground(menuWindowBg);
	window(5,10,55,15);
	clrscr();

}
void workingScreen()
{
/*
	Description : For creating working screen
	Author      : Dipin Khadka
	Created     : 1 june 2011
*/
	textbackground(workingScreenBg);
	window(5,5,75,23);
	clrscr();

}

void getString(int x, int y, int max, char str[30])
{
/*
	Description : string creating
	Author      : Dipin Khadka
	Created     : 3 june 2011
*/

	char ch   = NULL;
	int  i    = 0;
	int count = 0;

	while(1)
	{
		while(1)
		{
			ch = getch();
			if(ch == 13)  /* for enter key  */
			{
				break;
			}
			if(ch == 8)   /* for backspace  */
			{
				gotoxy(x+i,y); printf(" ");
				if(i>0)
				{
					i--;
					count--;
				}
			}
		 else	if(i<max) /*for accepting characters until maximum level is reached*/
			{
				str[i] = ch;
				i++;
				gotoxy(x+i,y); printf("%c",ch);
				count++;
			}
		}/* end of while*/
		str[i] = NULL;
		if(strlen(str)!= 0 )
			break;
	}
}/* end of getString*/

int getInt(int x, int y, int max)
{
/*
	Description : integer creating
	Author      : Dipin Khadka
	Created     : 3 june 2011
*/

	char str[30];
	int temp  = 0;
	char ch   = NULL;
	int  i    = 0;
	int count = 0;

	while(1)
	{
		while(1)
		{
			while(1)
			{
				ch = getch();
				if((ch >=48 && ch <= 57) || ch == 13 || ch == 8)
					break;
			}/* end of 1 while*/
			if(ch == 13)  /* for enter key  */
			{
				break;
			}
			if(ch == 8)   /* for backspace  */
			{
				gotoxy(x+i,y); printf(" ");
				if(i>0)
				{
					i--;
					count--;
				}
			}
			else if(i<max) /*for accepting characters until maximum level is reached*/
			{
				str[i] = ch;
				i++;
				gotoxy(x+i,y); printf("%c",ch);
				count++;
			}
		}/* end of 2nd while*/

		str[i] = NULL;
		temp   = atoi(str); /* converts the string into integer and returns it*/

		if(temp != 0 )
			break;
	}/*end of 3rd while*/

	return temp;

}/* end of getInt*/

void startingScreen()
{
/*
	Description : For getting started
	Author      : Dipin Khadka
	Created     : 3 june 2011
*/

	int count = 0;

	gotoxy(65,21); printf("loading");
	for (count=1; count<=5; count++)
	{
		delay(300);/* delays for 300 milliseconds to display
										the statemens in screen */
		gotoxy(72,21); printf(".....");
		sleep(1);
		gotoxy(72,21); printf("     ");
	}

	gotoxy(65,21); printf("               ");
	gotoxy(60,21); printf("Loading completed!!!");
	delay(400);
	gotoxy(50,23); printf("Now, enter any key to start...");
	getch();
}
void drawDoubleLine(int max, int y)
{
/*
	Description : For drawing double line
	Author      : Dipin Khadka
	Created     : 3 june 2011
*/
	int i = 0;
	for(i=1;i<=max;i++)
	{
		gotoxy(i,y); cprintf("%c",205);/* 205 for double line*/
	}
}
void terminateScreen()
{
/*
	Description : For setting terimating screen
	Author      : Dipin Khadka
	Created     : 3 june 2011
*/
	_setcursortype(_NOCURSOR);
	bigWindow();
	bigWindowScreen();
	gotoxy(25,10); cprintf("Thank's for using this program!!!");
	gotoxy(34,12); cprintf("Vist Again.....");
	sleep(2);
	exit(0);
}
