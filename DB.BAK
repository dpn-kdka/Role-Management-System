
/*
	File        : DB.c
	Description : Database management
	Author      : Dipin Khadka
	Created     : 17 april 2011
	------------------------------------------------------------------
	Date          Version Author Description
	17 april 2011 1.01    Dipin  Creating database
	1  june  2011 1.02    Dipin  Added logic to manage database which
															 includes add, delete, view, search,
															 modify and delete all the record
	3  june  2011	1.03		Dipin	 Added logic to check unique id
*/

struct Role
{
	int  roleId;
	char roleName[30];
	char roleDesc[80];
};

struct Role getInfo();
int checkUniqueId(int id);

void addRoleRecord()
{
/*
	Description : For adding  role record
	Author      : Dipin Khadka
	Created     : 1 june 2011
*/
	struct Role role;
	FILE *ptr   = NULL;
	char answer = NULL;

	gotoxy(30,2); cprintf("Add Opiton");
	drawDoubleLine(71,3);

	role = getInfo();
	gotoxy(1,12); cprintf("Would you like to save(Y/N)? ");
	answer = getch();
	if(answer == 'y' || answer == 'Y')/* checks yes or no*/
	{
		ptr = fopen("role.dat","ab");
		if(ptr == NULL)
		{
			gotoxy(1,12); cprintf("Opening file error!!!         ");
			getch();
			return;
		}
		else
		{
			fwrite(&role, sizeof(struct Role), 1, ptr);
			fflush(stdin);

			gotoxy(1,12); cprintf("Record saved successfully!!!");
			fclose(ptr);

		}
	}/* end of if*/
	else
	{
		gotoxy(1,12); cprintf("Record has not been added!!!");
	}
	delay(400);
	gotoxy(1,14); cprintf("Would you like to add more records(Y/N)?");
	answer = getch();
	if(answer == 'y' || answer == 'Y')
	{
		clrscr();
		addRoleRecord();
	}
}

struct Role getInfo()
{
/*
	Description : For taking role record
	Author      : Dipin Khadka
	Created     : 1 june 2011
*/
	int    flag        = 0;
 //	char   tempStr[80];
	struct Role role;

	gotoxy(1,4);  cprintf("Role Id         : ");
	while(1)
	{
		role.roleId = getInt(18,4,4);
		//gotoxy(1,1); scanf("%d",&role.roleId);
		flag = checkUniqueId(role.roleId);
		if(flag == 1)
		{
			gotoxy(1,12); cprintf("Id must be unique.. Re-enter Id: ");
			sleep(2); /* statement will be displayed
								 at screen only for 2 seconds*/
			gotoxy(1,12); cprintf("                                 ");
			gotoxy(18,4); cprintf("     ");
			gotoxy(18,4);
		}
		else if(flag == 0 || flag == -1)
			break;
	} /* end of while*/
	fflush(stdin);

	gotoxy(1,6);  cprintf("Role Name       : ");
	getString(18,6,25,role.roleName);
	//	gotoxy(18,6); gets(role.roleName);
	fflush(stdin);
	gotoxy(1,8);  cprintf("Role Description: ");
	getString(18,8,50,role.roleDesc);
	fflush(stdin);

	return role;

}

void displayInfo(struct Role role)
{
/*
	Description : For displaying given record
	Author      : Dipin Khadka
	Created     : 1 june 2011
*/
	gotoxy(1,4); cprintf("Role Id         : %d", role.roleId);
	gotoxy(1,6); cprintf("Role Name       : %s", role.roleName);
	gotoxy(1,8); cprintf("Role Description: %s", role.roleDesc);

}

void displayRoleRecord()
{
/*
	Description : For displaying record
	Author      : Dipin Khadka
	Created     : 1 june 2011
*/
	struct Role role;
	FILE *ptr = NULL;
	int  flag = 0;

	gotoxy(30,2); cprintf("View Opiton");
	drawDoubleLine(71,3);

	ptr = fopen("role.dat","rb");

	if(ptr == NULL)
	{
		gotoxy(1,12); cprintf("Opening file error!!!         ");
		getch();
		return;
	}
	else
	{
		while((fread(&role, sizeof(struct Role), 1, ptr)) == 1)
		{
			flag = 1;
			displayInfo(role);
			getch();
		}
		if(flag == 0)
		{
			gotoxy(1,12);  cprintf("No any record found!!!");
			getch();
		}
		fclose(ptr);
	}
}

void deleteRoleRecord()
{
/*
	Description : For deleting record
	Author      : Dipin Khadka
	Created     : 1 june 2011
*/
	struct Role role;
	FILE *ptr1  = NULL;
	FILE *ptr2  = NULL;
	int  id     = 0;
	int  flag   = 0;
	char answer = NULL;

	gotoxy(29,2); cprintf("Delete Opiton");
	drawDoubleLine(71,3);

	gotoxy(1,12);  cprintf("Enter Role Id to be deleted: ");
	id = getInt(1,13,4);
	fflush(stdin);
	gotoxy(1,13); cprintf("      ");


	ptr1 = fopen("role.dat","rb");
	ptr2 = fopen("temp.dat","wb");

	if(ptr1 == NULL || ptr2 == NULL)
	{
		gotoxy(1,12);  cprintf("Opening file error!!!         ");
		getch();
		return;
	}
	else
	{
		while((fread(&role, sizeof(struct Role), 1, ptr1)) == 1)
		{
			if(id == role.roleId)
			{
				displayInfo(role);
				flag = 1;
				gotoxy(1,12); cprintf("Are you sure to delete this record(Y/N)? ");
				answer = getch();

				if(answer == 'y' || answer == 'Y')/* checks yes or no*/
				{
					flag = 2;
					continue;
				}
			}
			fwrite(&role, sizeof(struct Role), 1, ptr2);

		}
		remove("role.dat");
		rename("temp.dat","role.dat");
		fclose(ptr1);
		fclose(ptr2);

		if(flag == 1)
		{
			gotoxy(1,12); cprintf("Record has not been deleted!!!             ");
		}
		else if(flag == 2)
		{
			gotoxy(1,12); cprintf("Record delete successfully!!!              ");
		}
		else if(flag == 0)
		{
			gotoxy(1,12); cprintf("Sorry!!! No any record found!!!            ");
		}
	}/* end of else*/
	delay(400);
	gotoxy(1,15); cprintf("Would you like to delete more records(Y/N)?");
	answer = getch();
	if(answer == 'y' || answer == 'Y')
	{
		clrscr();
		deleteRoleRecord();
	}
}

void modifyRoleRecord()
{
/*
	Description : For modifying record
	Author      : Dipin Khadka
	Created     : 1 june 2011
*/
	struct Role role;
	FILE *ptr     = NULL;
	int  id       = 0;
	long int size = 0;
	int  flag     = 0;
	char answer   = NULL;

	gotoxy(29,2); cprintf("Modify Opiton");
	drawDoubleLine(71,3);

	gotoxy(1,12); cprintf("Enter Role Id to be modified: ");
	id = getInt(1,13,4);
	gotoxy(1,12); cprintf("                               ");
	gotoxy(1,13); cprintf("     ");
	fflush(stdin);

	ptr = fopen("role.dat","rb+");
	if(ptr == NULL)
	{
		gotoxy(1,12);  cprintf("Opening file error!!!          ");
		getch();
		return;
	}
	else
	{
		size = sizeof(struct Role);
		while((fread(&role, sizeof(struct Role), 1, ptr)) == 1)
		{
			if(id == role.roleId)
			{
				flag = 1;
				fseek(ptr, -size, SEEK_CUR);
				role = getInfo();
				gotoxy(1,12); cprintf("Do you want to save modified record(Y/N)?");
				answer = getch();
				if(answer == 'y' || answer == 'Y')
				{
					fwrite(&role, sizeof(struct Role), 1, ptr);
					gotoxy(1,12); cprintf("Record modified successfully!!!          ");
				}
				else
				{
					gotoxy(1,12); cprintf("Record has not been modified!!!          ");
				}
				fclose(ptr);
				break;
			}
		}/* end of while*/
		if(flag == 0)
		{
				gotoxy(1,12);  cprintf("Record was not found to modify!!!");
				fclose(ptr);
		}
	}/* end of else */
	delay(400);
	gotoxy(1,14); cprintf("Would you like to modify more record(Y/N)?");
	answer = getch();
	if(answer == 'y' || answer == 'Y')
	{
		clrscr();
		modifyRoleRecord();
	}
}

void searchRoleRecord()
{
/*
	Description : For searching record
	Author      : Dipin Khadka
	Created     : 1 june 2011
*/
	struct Role role;
	int flag  = 0;
	int id    = 0;
	FILE *ptr = NULL;

	gotoxy(29,2); cprintf("Search Opiton");
	drawDoubleLine(71,3);

	gotoxy(1,12); cprintf("Enter Role ID to be search: ");
	id = getInt(1,13,4);
	gotoxy(1,12); cprintf("                             ");
	gotoxy(1,13); cprintf("     ");
	fflush(stdin);

	ptr = fopen("role.dat","rb");
	if(ptr == NULL)
	{
		gotoxy(1,12);  cprintf("Opening file error!!!         	 ");
		getch();
		return;
	}
	else
	{
		while((fread(&role, sizeof(struct Role), 1, ptr)) == 1)
		{
			if(id == role.roleId)
			{
				flag = 1;
				displayInfo(role);
				getch();
				break;
			}
		}
		if(flag == 0)
		{
			gotoxy(1,12);  cprintf("Record was not found!!!          ");
		}
		fclose(ptr);
	} /* end of else */
	delay(300);
	gotoxy(1,14);  cprintf("Press any key to return to admin menu...");
	getch();
}

void deleteAllRoleRecord()
{
/*
	Description : For deleting all record
	Author      : Dipin Khadka
	Created     : 1 june 2011
*/

	char answer = NULL;

	gotoxy(27,2); cprintf("Delete All Opiton");
	drawDoubleLine(71,3);

	gotoxy(1,12);  cprintf("Are you sure deleting all records(Y/N)?");
	answer = getch();
	if(answer == 'y' || answer == 'Y')
	{
		remove("role.dat");
		gotoxy(1,12); cprintf("ALL record was deleted successfully!!! ");
		getch();
	}
}

int checkUniqueId(int id)
{
/*
	Description : For checking unique id
	Author      : Dipin Khadka
	Created     : 3 june 2011
*/
	struct Role role;
	FILE *ptr  = NULL;
	int  flag  = 0;

	ptr = fopen("role.dat","rb");
	if(ptr == NULL)
	{
		gotoxy(1,12); cprintf("This is the first record...");
		sleep(2);
		gotoxy(1,12); cprintf("                           ");
		return -1;
	}
	else
	{
		while((fread(&role, sizeof(struct Role), 1, ptr)) == 1)
		{
			if(role.roleId == id)
			{
				flag = 1;
				break;
			}
		}
		fclose(ptr);
	}/* end of else */
	return flag;
}