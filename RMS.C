/*
	File        : RMS.c
	Description : Main working plate from
	Author      : Dipin Khadka
	Created     : 17 april 2011
	-----------------------------------------------------------------------
	Date          Version Author Description
	17 april 2011 1.01    Dipin
	29 may   2011 1.02    Dipin  Added logic to display menu where 1 for
															 displaying admin, 2 for displaying view
															 and 3 for exit.
	1  june  2011 1.03	  Dipin  Added logic to display working screen and
															 to add role record.
*/
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#include "common.c"
#include "util.c"
#include "menu.c"
#include "db.c"

void main()

{
/*
	Description : For main function
	Author      : Dipin Khadka
	Created     : 17 april 2011
*/
	/* declaration section */
	char choice           = NULL;
	char adminChoice      = NULL;
	char userPassword[20];
	char filePassword[20] = "kistbit";
	int  attempt          = 3;

	_setcursortype(_NOCURSOR);
	bigWindow();
	bigWindowScreen();
	projectMembers();
	startingScreen();
	bigWindowScreen();
	projectMembers();

	/*Ver 1.02,Displayed menu detail  */
	while(1)
	{
		menuWindow();
		choice = mainMenu();

		switch(choice)
		{
			case '1':
				{
					starting:

					userPasswordWindow();
					gotoxy(18,1); cprintf("Enter Password:");
					_setcursortype(_NORMALCURSOR);
					getPassword(20, 2, 10, userPassword);
					if(strcmp(userPassword,filePassword)==0) /* checks the
																									 valid password*/
					{
						attempt = 3;
						_setcursortype(_NOCURSOR);
						bigWindow();
						bigWindowScreen();
						projectMembers();
						menuWindow();
						while(1)
						{
							adminChoice = adminMenu();
							_setcursortype(_NORMALCURSOR);
							switch(adminChoice)
							{
								case '1':
								{
									workingScreen();
									addRoleRecord();
									_setcursortype(_NOCURSOR);
								}
								break;

								case '2':
								{
									workingScreen();
									deleteRoleRecord();
									_setcursortype(_NOCURSOR);
								}
								break;

								case '3':
								{
									workingScreen();
									_setcursortype(_NOCURSOR);
									displayRoleRecord();
								}

								break;

								case '4':
								{
									workingScreen();
									searchRoleRecord();
									_setcursortype(_NOCURSOR);
								}
								break;

								case '5':
								{
									workingScreen();
									modifyRoleRecord();
									_setcursortype(_NOCURSOR);
								}
								break;

								case '6':
								{
									workingScreen();
									deleteAllRoleRecord();
									_setcursortype(_NOCURSOR);
								}

								case '7':
								_setcursortype(_NOCURSOR);
								break;

							}/* end of switch case*/
							if(adminChoice == '7')
								break;

							bigWindow();
							bigWindowScreen();
							projectMembers();
							menuWindow();
						}/* end of while loop*/
					} /* end ofif */
					else
					{
						if(attempt>1)
						{
							attempt--;
							gotoxy(15,4); cprintf("Please!!! Try again!!!                 ");
							gotoxy(18,6); cprintf("Attempt left: %d",attempt);
							getch();
							goto starting;

						}
						else
						{
							gotoxy(10,5); cprintf("Maximum Number of Attempts Exceeded !!!");
							gotoxy(13,6); cprintf("System is going to shutdown....");
							sleep(3);
							gotoxy(13,6); cprintf("                               ");
							clrscr();
							terminateScreen();
						}
					}  /*end of main else*/
				}/* end of case 1*/
			break;

			case '2':
			{
				workingScreen();
				displayRoleRecord();
				bigWindow();
				bigWindowScreen();
				projectMembers();
				menuWindow();
			}

			break;

			case '3':
			{
				terminateScreen();
			}
		}/* end of switch case*/
	}/* end of 1st while*/
}/* end of main*/