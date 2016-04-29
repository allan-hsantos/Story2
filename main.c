#include "Story2.h"

/*
Story 2 - As a system administrator (accountant). 
I want to be able to change the withhold
tax rates for IR, PIS, COFINS, CSLL. 
That way I don't need to change the code when the tax rate changes. 
*/


int main()
{
	struct invoice in;
	struct withhold_taxes wt;
    struct taxes t = rates();
	struct taxes *new_t = &t;
	char username[USERNAME], password[PASSWORD], answer;
	int choice, aux;
	time_t time_date;
	time(&time_date);

	do
	{
		system("color 1f");

		//If access  is granted, the admin is able to change the tax rates
		aux = admin_access(username,password);

		while(aux == 1)
		{
			system("cls");
			printf("/*************************************/\n");		
			printf("/*      NF-e Withheld Taxes - V2     */\n");
			printf("/*************************************/\n");				
			printf("\n1- Calculate Withheld Taxes (testing only)");
			printf("\n2- Update Tax Rates Manually");
			printf("\n3- Reset Tax Rates by default");
			printf("\n4- Exit");
			printf("\n\n-> ");
			scanf("%d", &choice);
			
			switch(choice)
			{
				case 1:
						system("cls");
						printf("Invoice Amount: ");
						scanf("%f", &in.invoice_amount);
						
						//Display the current date and time according to O.S
						printf("\n\n%sThe current tax rates are: ", ctime(&time_date));
						printf("\n\nIR: %.2f", t.ir);
						printf("\n\nPIS: %.4f", t.pis);
						printf("\n\nCOFINS: %.2f", t.cofins);
						printf("\n\nCSLL: %.2f", t.csll);
						wt = calculate(in, t);
						
						printf("\n\nGovern Amount: %.2f", wt.govern_amount);
						printf("\n\nAssumed Profit: %.2f", wt.assumed_profit);
						printf("\n\n");
						system("pause");
						break;
				
	
				case 2:	
						system("cls");
						printf("Please input the new current tax rates: ");
						
						printf("\n\nIR: ");
						scanf("%f", &new_t->ir);
						
						printf("PIS: ");
						scanf("%f", &new_t->pis);
	
						printf("COFINS: ");
						scanf("%f", &new_t->cofins);
	
						printf("CSLL: ");
						scanf("%f", &new_t->csll);
	
						printf("\nThe tax rates were successfuly updated!");
						printf("\n\n");
						system("pause");
						break;


				case 3:
						do
						{
							system("cls");
							printf("You are about to reset the tax rates\n");
							printf("\n\nAre you sure? Please Y or N to proceed ");	
							fflush(stdin);
							scanf("%c", &answer);
							
							//This variable reaceives the ENTER key
							if(answer == tolower('Y') || answer == 'y')
							{
								t = rates();
								printf("\n\nThe tax rates were successfuly reset!\n");
								system("pause");
							}
							
							else if(answer == tolower('n') || answer == 'n')
							{
								system("pause");
								//return 0;
							}
							else
							{
								printf("\n\nPlease press Y or N key to proceed\n\n");
								system("pause");
							}
						
						}while(answer != tolower('Y') && answer != 'y' && answer != tolower('n') && answer != 'n');
											
						break;
				
				
				case 4:
						printf("\nBye!\n\n");
						return 0;
						break;
						
				default: printf("\n\nInvalid option!\nPlease try Again!\n\n");
			             system("pause");
		                 break;				
			}
		}

	}while(choice != 4);

	printf("\n\n");
}

