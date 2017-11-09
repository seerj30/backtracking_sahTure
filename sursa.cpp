#include<iostream>
using namespace std;
int n,nr;
void init(int st[],int k)
{
	st[k]=0;
}

int succ(int st[],int k)
{
	if(st[k]<n)
	{
		st[k]++;
		return 1;
	}
	return 0;
}


int valid(int st[],int k)
{
	int i;
	for(i=1;i<k;i++)
		if(st[i]==st[k])
			return 0;
	return 1;
}

int sol(int st[],int k)
{
	return k==n;
}

void tipar(int st[],int k)
{
	int i,j;
	char a[25][25];
	for(i=1;i<=k;i++)
		for(j=1;j<=k;j++)
			a[i][j]='*';
	//completare matrice
	for(i=1;i<=k;i++)
		a[i][st[i]]='T';
	//afisare matrice
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=k;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	nr++;
}


void back(int st[],int k)
{
   int as,ev;
   init(st,k);
   while(k)
   {
		do
		{
			as=succ(st,k);
			if(as)
				ev=valid(st,k);
		}while(as && !ev);
		if(as)
			if(sol(st,k))
				tipar(st,k);
			else
			{
				k++;
				init(st,k);
			}
		else
			k--;
	}
}

int main()
{
	int st[50];
	cout<<"n=";
	cin>>n;
	back(st,1);
	cout<<"Numarul de solutii este: "<<nr;
	return 0;
}
