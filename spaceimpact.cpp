#include<iostream>
#include"windows.h"
#include"time.h"
#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER 13
using namespace std;
void menu();
void user_exit();
void HELP()
{
    system("color 0a");
    cout << "     1)  Press LEFT and RIGHT ARROW KEYS to NAVIGATE\n\n";
    cout << "     2)  Press SPACE key to FIRE\n\n";
    system("pause");
}
char Map[20][40]=
{

    "---------------------------------------",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                   M                 |",
    "---------------------------------------",
};
bool endgame=false;
int gamespeed =100;
int randomNum,randomNum1;
int MaxHealth=200;
int YourHealth=MaxHealth;
int cnt=0;

void play()
{
    system("color 0b");
    while (endgame==false)
    {
        srand(time(0));
        system("cls");
        for(int y=0; y<20; y++)
        {
            cout << Map[y] << endl;
        }
        cout << "Health:" << YourHealth << "/" << MaxHealth;
        cout << "Your Score:" << cnt << endl;
        for(int y=0; y<20; y++)
        {
            for(int x=0; x<40; x++)
            {
                switch(Map[y][x])
                {
                case 'M':
                    if (GetAsyncKeyState(VK_LEFT)!=0)
                    {
                        int newX= x-1;

                        switch(Map[y][newX])
                        {
                        case ' ':
                            Map[y][x]=' ';
                            x--;
                            Map[y][newX]='M';
                            break;
                        }

                    }
                    if (GetAsyncKeyState(VK_RIGHT)!=0)
                    {
                        int newX= x+1;

                        switch(Map[y][newX])
                        {
                        case ' ':
                            Map[y][x]=' ';
                            x++;
                            Map[y][newX]='M';
                            break;
                        }

                    }
                    if(GetAsyncKeyState(VK_SPACE)!=0)
                    {
                        y--;
                        Map[y][x]='"';
                    }
                    break;

                case '"':

                    Map[y][x]=' ';
                    y--;
                    if(Map[y][x]!='-'&& Map[y][x]!='O')
                    {
                        Map[y][x]='"';
                    }
                    else if(Map[y][x]== 'O')
                    {
                        Map[y][x]=' ';
                        cnt=cnt+10;
                    }
                    break;
                case ' ':
                    randomNum= rand() %100+1;
                    if(randomNum == 1)
                    {
                        if(y<3)
                        {
                            y++;
                        Map[y][x]='O';
                        }

                    }
                    break;
                case 'O':
                    Map[y][x]= ' ';
                    y++;
                    if(Map[y][x]!='-'&& Map[y][x]!='M')
                    {
                        Map[y][x]= 'O';
                    }
                    else if(Map[y][x]=='M')
                    {
                        YourHealth-=20;
                    }
                    break;
                }
            }
        }
        if(YourHealth<=0)
        {
            endgame= true;
            system("cls");

                cout << "GameOver" << endl;

            system("pause");
            exit(1);
        }
        Sleep(gamespeed);
    }
}
int main()
{
    menu();

}
void menu()
{
    system("color 0c");
    char key;
    char arrow[] = "==>>";
    char menu_option_lower[3][100];
    char menu_option_upper[3][100];
    strcpy(menu_option_lower[0],"Play");
    strcpy(menu_option_lower[1],"Instructions");
    strcpy(menu_option_lower[2],"Exit");

    strcpy(menu_option_upper[0],"PLAY");
    strcpy(menu_option_upper[1],"INSTRUCTIONS");
    strcpy(menu_option_upper[2],"EXIT");

    cout << "////***** MENU *****///// \n\n";
    printf("%s\t%s\n\n",arrow,menu_option_upper[0]);
    printf("\t%s\n\n",menu_option_lower[1]);
    printf("\t%s\n\n",menu_option_lower[2]);
    printf("press UP and DOWN key to navigate the menu");
    int i = 0;
    int j;
    while(1)
    {
        key = getche();
        if(key == DOWN_ARROW)
        {
            if(i == 2) i = 0;
            else ++i;
        }
        else if(key == UP_ARROW)
        {
            if(i == 0) i = 2;
            else --i;
        }
        if(key == ENTER)
        {
            if(i == 0)
            {
                system("cls");
                play();
            }
            else if(i == 1)
            {
                system("cls");
                HELP();
            }


            else if(i == 2)
                user_exit();
        }
        system("cls");
        cout << "////***** MENU *****///// \n\n";

        for(j = 0; j < 3; j++)
        {
            if(j == i)
                printf("%s%s\n\n",arrow,menu_option_upper[j]);
            else
                printf("\t%s\n\n",menu_option_lower[j]);
        }
        printf("press UP and DOWN key to navigate the menu");
    }
}
void user_exit()
{
    exit (1);
}




