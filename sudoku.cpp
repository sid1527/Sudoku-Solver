#include<bits/stdc++.h>
using namespace std;

int board[10][10]={0},flag=0;
/*3 6 0 0 0 8 4 0 0
0 8 0 0 1 0 7 2 0
2 0 0 0 4 0 0 0 9
5 0 7 0 0 9 0 1 0
0 0 0 0 3 0 0 9 0
0 3 0 0 5 0 2 0 7
1 0 8 0 0 4 0 0 0
0 0 0 0 0 0 0 4 8
9 2 0 1 0 7 3 0 0
*/
/*
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0
*/

void printSudoku()
{
	cout<<"\nTHE SUDOKU BOARD IS : \n\n";
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<10;j++)
		{
			cout<<board[i][j]<<" ";
			if(j%3==0 && j<9)
			cout<<"|| ";
		}
		cout<<endl;
		if(i%3==0 && i<9)
		cout<<"-------------------------\n-------------------------\n";
	}
}

bool isFull()
{
	for(int i=1;i<10;i++)
		for(int j=1;j<10;j++)
			if(board[i][j]==0)
				return false;
	
	return true;
}

vector<int> possibleEntries(int i,int j)
{
	std::vector<int> v;
	for(int i=0;i<10;i++)
		v.push_back(i);

	for(int y=1;y<10;y++)
		if(board[i][y]!=0)
			v[board[i][y]]=0;

	for(int x=1;x<10;x++)
		if(board[x][j]!=0)
			v[board[x][j]]=0;

	int k=0,l=0;
	if(i>=1 && i<=3)
		k=1;
	else if(i>=4 && i<=6)
		k=4;
	else
		k=7;

	if(j>=1 && j<=3)
		l=1;
	else if(j>=4 && j<=6)
		l=4;
	else
		l=7;

	for(int x=0;x<3;x++)
		for(int y=0;y<3;y++)
			if(board[k+x][l+y]!=0)
				v[board[k+x][l+y]]=0;
	return v;
}

void sudokuSolver()
{
	int i=0,j=0;
	std::vector<int> v;
	if(isFull())
	{
		cout<<"BOARD SOLVED SUCCESSFULLY \n";
		printSudoku();
		flag=1;
		return;
	}
	for(int x=1;x<10;x++)
		for(int y=1;y<10;y++)
		{	
			if(board[x][y]==0)
			{
				i=x;
				j=y;
				goto l1;
			}
		}
	l1:	v=possibleEntries(i,j);
	for(int x=1;x<10;x++)
	{
		if(v[x]!=0)
		{
			board[i][j]=v[x];
			sudokuSolver();
		}
	}
	//return;
	board[i][j]=0;
}

int main()
{
	printSudoku();
	cout<<"\nEnter the elements of the board\n";
	for(int i=1;i<10;i++)
	for(int j=1;j<10;j++)
	cin>>board[i][j];
	printSudoku();	
	/*
	if(flag==0)
		cout<<"\nSORRY can't solve the given SUDOKU BOARD \n";*/
	sudokuSolver();
	return 0;
}