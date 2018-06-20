#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
class snl
{
	public:
		int num;
		snl *next;
		char c1,c2;
		int dice()
		{
			int a[]={1,2,3,4,5,6};
			int p,i=0;
			bool exit = false;
			cout<<"\nroll dice:";
			while(exit==false)
			{
				i=(i+1)%6;
				//GetAsync doesnt let loop to enter into if block until control key is pressed
				if(GetAsyncKeyState(VK_CONTROL))
				{
					p=a[i];
					exit = true;
				}
			}
			cout<<p<<"\n";
			return p;
		}
}*p1,*p2,*s;
void disp()
{
	snl *a[10][10];
	int i,mo=1;
	snl *q=s;
	for(int j=0;j<10;j++)
	{
		for(int k=0;k<10;k++)
		{
			a[j][k]=q;
			if(j==9&&k==9)
				break;
			q=q->next;
		}
	}
	q=s;
	for(int j=9;j>=0;j--)
	{
		if(mo%2==0)
		for(int k=0;k<10;k++)
		{
			cout<<a[j][k]->c1<<(j*10)+(k+1)<<a[j][k]->c2<<"\t";
		}
		else
		for(int k=9;k>=0;k--)
		{
			cout<<a[j][k]->c1<<(j*10)+(k+1)<<a[j][k]->c2<<"\t";
		}
		cout<<"\n\n";
		mo++;
	}
}
int check(int n)
{
	if(n==25)
	{
		cout<<"\nLucky ladder!!!!!";
		return 54;
	}
	if(n==34)
	{
		cout<<"\nLucky ladder!!!!!";
		return 44;
	}
	if(n==67)
	{
			cout<<"\nLucky ladder!!!!!";
			return 76;
	}
	if(n==88)
	{
		cout<<"\nLucky ladder!!!!!";
		return 94;
	}
	if(n==34)
	{
		cout<<"\nOOPS!!!!!SNAKEEEEEE";
		return 5;
	}
	if(n==57)
	{
		cout<<"\nOOPS!!!!!SNAKEEEEEE";
		return 38;
	}
	if(n==75)
	{
		cout<<"\nOOPS!!!!!SNAKEEEEEE";
		return 43;
	}
	if(n==98)
	{
		cout<<"\nOOPS!!!!!SNAKEEEEEE";
		return 50;
}
return n;
}
int main()
{
	int ch=0,n,i=0,j,numb;
	char o,ch1,ch2;
	for(int k=0;k<100;k++)
	{
		snl *temp,*q;
		temp=new snl();
		temp->num=k;
		temp->next=0;
		temp->c1='_';
		temp->c2='_';
		if(k==0)
			s=temp;
		else
		{
			q=s;
			while(q->next!=0)
				q=q->next;
			q->next=temp;
		}
	}
	cout<<"\nHIDDEN SNAKE AND LADDER GAME !!!!";
	cout<<"\nRules and controls:\n1)Press control to roll dice\n2)Press 's' to proceed to next turn\n3)Press Esc key to exit\n4)One to reach 100 first wins\n5)Don't step over a snake !!!!";
	cout<<"\n\n\nPlayer 1->Choose your favourite letter:";
	cin>>ch1;
	cout<<"\nPlayer 2->Choose your favourite letter:";
	cin>>ch2;
	s->c1=ch1;
	s->c2=ch2;
	p1=s;
	p2=s;
	system("cls");
	snl *q;
	while(p1->num!=99&&p2->num!=99)
	{
		ch=ch%2+1;
		j=0;
		switch(ch)
		{
			case 1:
					q=s;
					cout<<"\nPlayer 1:\n";
					disp();
					n=s->dice();
					if(p1->num+n>=100)
						break;
					p1->c1='_';
					numb=check(p1->num+n);
					while(j!=numb)
					{
						q=q->next;
						j++;
					}
					p1=q;
					p1->c1=ch1;
					break;
			case 2:	
					q=s;
					cout<<"\nPlayer 2:\n";
					disp();
					n=s->dice();
					if(p2->num+n>=100)
						break;
					p2->c2='_';
					numb=check(p2->num+n);
					while(j!=numb)
					{
						q=q->next;
						j++;
					}
					p2=q;
					p2->c2=ch2;
					break;
		}
		cout<<"\nPress 's' to continue";
		if(getch()=='s')
		{
			system("cls");	
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			exit(0);
		}
	}
	if(p1->num==99)
	{
		cout<<"\nPlayer 1 won!!";
	}
	else
	{
		cout<<"\nPlayer 2 won!!";
	}
}
