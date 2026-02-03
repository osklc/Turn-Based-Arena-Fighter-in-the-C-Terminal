#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

typedef struct Player{
    int health;
    int activeHealth;
    int gold;
    int level;
	int attack;
	int defense;
    int xp;
}Player;
extern struct Player kheshig;

extern void FirstIntroductionMenu();
extern void gameSave();
extern void playerStats(char menuName[]);

void innMenu();