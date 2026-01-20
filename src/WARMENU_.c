#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "../include/WARMENU_.h"

char boardWar[4][20] = {"Quick Attack","Heavy Attack","Block","Heal"};

void warMenu()
{
	cursorControlWar();
}

void cursorControlWar()
{
	char selectedDirection = '\0';
	
	while((selectedDirection != 'F' && selectedDirection != 'f') && (selectedDirection != 'Q' && selectedDirection != 'q'))
	{
		system("cls");
		printf("\033[35m\033[3mWAR MENU\033[0m\n");
		printf("\033[31m\033[1mHealth:\033[0m %d\n",charHealth);
		printf("\033[36m\033[1mDurability:\033[0m %d\n",charDurability);
		printf("\033[33m\033[1mGold:\033[0m %d\n",charGold);
		PrintBoardWar();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Back to main menu");
		selectedDirection = getch();
		
        if(selectedDirection == 'A' || selectedDirection == 'a')
        {
            column--;
            if(column < 0) column = 3;
        }
        else if(selectedDirection == 'D' || selectedDirection == 'd')
        {
            column++;
            if(column > 3) column = 0;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(column==0)
        	{
        		system("cls");

			}
			else if(column==1)
			{
				system("cls");

			}
			else if(column==2)
			{
				system("cls");

			}
			else if(column==3)
			{
				system("cls");

			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q')
        {
        	FirstIntroductionMenu();
		}
		else
		{
			printf("\n\033[3m\033[31mERROR:\033[0m %c is not a valid value. Please enter valid input!", selectedDirection);
			Sleep(1000);
		}
        
	}
}

void PrintBoardWar()
{
	int i,j;
	
	for(i=0;i<1;i++)
	{
		printf(" \033[4m                                                            \033[0m\n");
		printf("|                  |                  |           |          |\n");
		for(j=0;j<4;j++)
		{
			printf("|");
			if(i==row && j== column)
			{
				printf("  [%s]  ",boardWar[j]);
			}
			else
			{
				printf("   %s   ",boardWar[j]);
			}
		}
		printf("|");
		printf("\n");
		printf("|\033[4m                  |                  |           |          \033[0m|\n");
	}
}