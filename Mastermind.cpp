#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
# include <stdlib.h>
#include <dos.h>
using namespace std;

void intro(void);
void instructions(void);
void select(char def[],char sel_2[]);
void input(char answer[]);
int Test(char sel_2[],char answer[]);
void lose(char sel_2[]);


int main()
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	char col[9]={'b','g','r','p','c','o','y','w'};
	char sel[6],ans[6];
	
	
	SetConsoleTextAttribute(color,15);
	intro();
	getch();
	system("CLS");
	
	SetConsoleTextAttribute(color,7);
	cout<<"Rules:"<<endl<<"The computer has generated a random colour sequence. The player has six chances to get it right."<<flush;
	cout<<endl<<"-> 'o' means that the correct colour is in the correct position.\n-> '?' means that the colour is present in a different position.\n-> 'x' means that the colour is not present."<<endl<<"The player has to press the following keys for each colour:"<<endl<<flush;
	
	instructions();
		
	SetConsoleTextAttribute(color,7);
	cout<<endl<<endl;
	system("pause");
	system("CLS");
	
	select(col,sel);
	
	instructions();
	
	int correct;
	
	for(int c=0;c<5;c++)
	{
		input(ans);
		
		cout<<"         ";		
		
		correct=Test(sel,ans);
		
		cout<<endl;
	
		if(correct==5)
		{
			cout<<"You win!";
			break;
		}	
	}
	if(correct!=5)
	lose(sel);
	
	SetConsoleTextAttribute(color,7);	
	cout<<endl<<"Press any key to exit.";
	getch();
	
	
	return 0;
	
	
}
void intro(void)
{
	cout<<"\t\t";
	
	for(int c=0;c<40;c++)
	{
		Sleep(30);
		cout<<"\xcd";
	}
	
	cout<<"\n\t\t";
	for(int c=0;c<14;c++)
	{
		Sleep(30);
		cout<<"\xdb";
	}
	char title[11]="MasterMind";
	cout<<" ";
	for(int k=0;k<10;k++)
	{
		cout<<title[k];
		Sleep(100);
	}
	cout<<" ";
	for(int c=0;c<14;c++)
	{
		Sleep(30);
		cout<<"\xdb";
	}
	cout<<"\n\t\t"; 
	for(int c=0;c<40;c++)
	{
		Sleep(30);
		cout<<"\xcd";
	}
	Sleep(200);
	cout<<"\t\t\t\t\t\t\tMade by:"<<endl;
	Sleep(200);
	cout<<"\t\t     Muhammad Shibl Khan (17B-001-CE)";
	Sleep(200);
	cout<<endl<<"\t\t         Tuba Siddiqui (17B-042-CE)";
	cout<<endl<<"\t\t\t     Press any key!";
}

void select(char def[],char sel_2[])
{
	int val=8;
	
	srand(time(0));
	for(int c=0;c<5;c++)
	{
		int num=rand()%val;
		sel_2[c]=def[num];
		if(num==val-1)
		val--;
		else
		{
			for(int k=num+1;k<8-c;k++)
			def[k-1]=def[k];
			
			val--;
		}		
	}
}

void input(char answer[])
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	for(int k=0;k<5;k++)
	{			
		answer[k]=getch();
		
		switch(answer[k])		 
		{
		case 'b':
			SetConsoleTextAttribute(color,9);
			cout<<"* ";
			break;
		
	
		case 'g':
		
			SetConsoleTextAttribute(color,10);
			cout<<"* ";
			break;
		
		
		case 'r':
		
			SetConsoleTextAttribute(color,12);
			cout<<"* ";
			break;
		
	
		case 'p':
		
			SetConsoleTextAttribute(color,5);
			cout<<"* ";
			break;
		
	
		case 'c':
		
			SetConsoleTextAttribute(color,11);
			cout<<"* ";
			break;
		
	
		case 'o':
		
			SetConsoleTextAttribute(color,8);
			cout<<"* ";
			break;
		
	
		case 'y':
		
			SetConsoleTextAttribute(color,6);
			cout<<"* ";
			break;
		
	
		case 'w':
		
			SetConsoleTextAttribute(color,15);
			cout<<"* ";
			break;
		
		default:
			k--;
		}
	}		
}

int Test(char sel_2[],char answer[])
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color,7);
	
	int count=0;
	for(int k=0;k<5;k++)
		{
			if(answer[k]==sel_2[k])
			{
				cout<<"o";
				count++;
			}
			
			else
			{
				for(int l=0;l<=4;l++)
				{					
					if(sel_2[l]==answer[k])
					{
						cout<<"?";
						break;
					}				
					
					else if(l==4 && sel_2[l]!=answer[k])
					cout<<"x";
				}
			}
		
		
		}
	return count;
}

void lose(char sel_2[])
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	{
		cout<<"You lose...\n\nActual sequence is:\n";
		for(int c=0;c<5;c++)
		{
			Sleep(500);
			if(sel_2[c]=='b')
			{
				SetConsoleTextAttribute(color,9);
				cout<<"* ";
			}
			
			if(sel_2[c]=='g')
			{
				SetConsoleTextAttribute(color,10);
				cout<<"* ";
			}
		
			if(sel_2[c]=='r')
			{
				SetConsoleTextAttribute(color,12);
				cout<<"* ";
			}
		
			if(sel_2[c]=='p')
			{
				SetConsoleTextAttribute(color,5);
				cout<<"* ";
			}
			
			if(sel_2[c]=='c')
			{
				SetConsoleTextAttribute(color,11);
				cout<<"* ";
			}
		
			if(sel_2[c]=='o')
			{
				SetConsoleTextAttribute(color,8);
				cout<<"* ";
			}
		
			if(sel_2[c]=='y')
			{
				SetConsoleTextAttribute(color,6);
				cout<<"* ";
			}
		
			if(sel_2[c]=='w')
			{
				SetConsoleTextAttribute(color,15);
				cout<<"* ";
			}
		}
		Sleep(500);
	}
}
void instructions(void)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(color,9); //blue
	cout<<"B=Blue ";
	SetConsoleTextAttribute(color,10); //light green
	cout<<"G=Green ";
	SetConsoleTextAttribute(color,12); //Red
	cout<<"R=Red ";
	SetConsoleTextAttribute(color,5); //Purple
	cout<<"P=Purple ";
	SetConsoleTextAttribute(color,11); //Light blue
	cout<<"C=Cyan ";
	SetConsoleTextAttribute(color,8); //grey
	cout<<"O=Grey ";
	SetConsoleTextAttribute(color,6); //Yellow
	cout<<"Y=Yellow ";
	SetConsoleTextAttribute(color,15); //Bright white
	cout<<"W=White.";
	cout<<endl<<"---------------------------------------------------------------"<<endl<<endl;
	
}


