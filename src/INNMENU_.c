#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "../include/INNMENU_.h"

char boardInn[2][40] = {"Rest - 50G", "Continue"};
char viewLineInn[] = "========================================================";
int innRow = 0;

void innMenu()
{
	cursorControlInn();
}

void cursorControlInn()
{
	char selectedDirection = '\0';
	
	while((selectedDirection != 'F' && selectedDirection != 'f') && (selectedDirection != 'Q' && selectedDirection != 'q'))
	{
		system("cls");
		playerStats("THE INN", 7, sizeof(viewLineInn), viewLineInn);
		printInnList();
		printf("[W-S] Move  |  [F] Select  |  [Q] Back to main menu");
		printf("\n%s\n", viewLineInn);
		selectedDirection = getch();
		
        if(selectedDirection == 'W' || selectedDirection == 'w' || selectedDirection == 72)
        {
            innRow--;
            if(innRow < 0) innRow = 1;
        }
        else if(selectedDirection == 'S' || selectedDirection == 's' || selectedDirection == 80)
        {
            innRow++;
            if(innRow > 1) innRow = 0;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(innRow==0)
        	{
				if(kheshig.gold<50)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLineInn);
					printf("Press any key to return to the main menu.");
					printf("\n%s\n", viewLineInn);
					getch();
					FirstIntroductionMenu();
				}
				kheshig.gold-=50;
				kheshig.activeHealth+=50;
				if(kheshig.activeHealth>kheshig.health)
				{
					kheshig.activeHealth=kheshig.health;
				}
				gameSave();
				system("cls");
				cursorControlInn();
			}
			else if(innRow==1)
			{
				FirstIntroductionMenu();
			}
        }
        else if(selectedDirection == 'Q' || selectedDirection == 'q')
        {
            FirstIntroductionMenu();
        }
	}
}

void printInnList()
{
	for(int i=0; i<2;i++)
	{
		if(i==innRow)
		{
			printf("\033[32m >>> %s <<<\033[0m\n", boardInn[i]);
		}
		else
		{
			printf("     %s\n", boardInn[i]);
		}
	}
}