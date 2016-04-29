#include "Story2.h"

/********************* Access Methods **********************/

int admin_access(char username[USERNAME], char password[PASSWORD])
{
	
	//Valid credentials to bypass the system
	char username_admin [USERNAME] = "admin";
	char password_admin [PASSWORD] = "admin";
	
	
	system("cls");
	printf("/*************************************/\n");		
	printf("/*            ADMIN ACCESS           */\n");
	printf("/*************************************/\n");
	printf("\n\nWelcome to Admin secction!");
	printf("\nEnter your admin credentials to proceed\n");
	fflush(stdin);

	printf("\nUsername: ");
	gets(username);

	printf("\nPassword: ");
	gets(password);

	if(strcmp(username, username_admin) == 0 && strcmp(password, password_admin) == 0)
	{
		printf("\n\nAccess Granted!\n\n");
		system("pause");
		return 1;
	}
	else
	{
		printf("\n\nAccess Denied! Bad Username or Password\n\n");
		system("pause");
		return 0;
	}

	printf("\n");
}

