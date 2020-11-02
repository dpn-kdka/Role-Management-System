/*
	File        : MENU.c
	Description : Displays menu
	Author      : Dipin Khadka
	Created     : 17 april 2011
	---------------------------------------------------------------------
	Date          Version Author Description
	17 april 2011 1.01    Dipin  added logic to menu creation and display
*/


char mainMenu()

{
/*
	Description : Showing Admin, View and Exit section of the program
	Author      : Dipin Khadka
	Created     : 8 may 2011
*/
	char choice = NULL;
	char menu[3][15] = {
											"1. Admin",
											"2. View",
											"3. Exit"
											};
	int i = 0;

	gotoxy(6,1); cprintf("Main Menu");
	drawDoubleLine(20,2);

	for(i=0;i<3;i++)
	{
		gotoxy(2,4+i); cprintf("%s",menu[i]);
	}/* end of for loop*/
	choice = getch();
	return choice;

}/* end of mainMenu */


char adminMenu()

{
/*
	Description : Showing Admin's sub menu
	Author      : Dipin Khadka
	Created     : 29 may 2011
*/
	char choice = NULL;
	char menu[8][15] = {
											"1. Add       ",
											"2. Delete    ",
											"3. View      ",
											"4. Search    ",
											"5. Modify    ",
											"6. Delete All",
											"7. Return    "
										 };
	int i = 0;

	gotoxy(6,1); cprintf("Admin Menu");
	drawDoubleLine(20,2);

	for(i=0;i<8;i++)
	{
		gotoxy(2,3+i); cprintf("%s",menu[i]);
	}/* end of for loop*/
	choice = getch();
	return choice;

}/* end of adminMenu */