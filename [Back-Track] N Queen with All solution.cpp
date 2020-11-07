#include <bits/stdc++.h>
using namespace std;
int sol = 0;
void printme(int board[][10], int n)
{
    sol = 1;
    cout<<'[';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j])
            {
                cout<<j+1<<" ";
            }
        }
        
    }
    cout<<"] ";
    
}
bool issafetoput(int board[][10], int i ,int j, int n)
{
    // Check For column
    for(int row = i;row>=0;row--)
    {
        if(board[row][j] == 1) return false;
    }
    
    //Check For Left Above
    int x = i;
    int y = j;
    while(x>=0 && y>=0)
    {
        if(board[x][y] == 1) return false;
        x--;
        y--;
    }
    
    //Check For Right Above
    x = i, y =j;
    while(x>=0 && y<n)
    {
        if(board[x][y] ==1) return false;
        x--;
        y++;
    }
    //All Safe to put
    return true;
}
bool findqueen(int board[][10] , int i , int n)
{
     if(i == n)
     {
         //We have Succesfully Placed All the Queens
         //Printing the answer
         printme(board,n);
         return true;
     }
     bool res = false;
     for(int j=0;j<n;j++)
     {
         //Direct First place it;
         
         if(issafetoput(board,i,j,n) == true)
         {
             board[i][j] = 1;
             //Finding For Below Position (Rows)
             res = findqueen(board ,i+1,n) | res;
             
            // else return false;
            board[i][j] = 0;
         }
           
         
     }
     return false;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    sol=0;
	    int n;cin>>n;
	    int board[10][10] = {0};
	    
	    bool b = findqueen(board , 0 , n);
	    if(!sol) cout<<-1;
	    cout<<endl;
	}
}
