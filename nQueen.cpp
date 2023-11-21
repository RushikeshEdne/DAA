#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public :
void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n)
{
    if (col == n) {
        ans.push_back(board);
        return;
      }
    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col]='Q';
        }
        //Recurssion
        solve(col+1,ans,board,n);
        //Backtracking
        board[row][col]='*';
        
    }
}
public :
bool isSafe(int row,int col,vector<string> &board,int n)
{
    int x=row;
    int y=col;
    //a.For same row
    while(y>=0)
    {
        if(board[x][y]=='Q')
        {
            return false;
        }
        y--;
    }
    
    //b.For upper diagonal
    x=row;
    y=col;
    while(x>=0 && y>=0)
    {
        if(board[x][y]=='Q')
        {
            return false;
        }
        x--;
        y--;
    }
    
    //c.For lower diagonal
    x=row;
    y=col;
    while(x<n && y>=0)
    {
        if(board[x][y]=='Q')
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
    
}

public :
vector<vector<string>>NQueen(int n)
{
    vector<vector<string>>ans;
    vector<string> board(n);
    string s(n,'*');
    for(int i=0;i<n;i++)
    {
        board[i]=s;
    }
    solve(0,ans,board,n);
    return ans;
}
};

int main()
{
   int n;
   cout<<"Enter the number"<<endl;
   cin>>n;
   Solution obj;
   
   vector<vector<string>> ans=obj.NQueen(n);
   for(int i=0;i<ans.size();i++)
   {
       cout<<"Arranggement "<<i+1<<endl;
       for(int j=0;j<ans[0].size();j++)
       {
           cout<<ans[i][j];
           cout<<endl;
       }
       cout<<endl;
   }
   return 0;
}

//  for (int i = 0; i < ans.size(); i++) {
//     cout << "Arrangement " << i + 1 << "\n";
//     for (int j = 0; j < ans[0].size(); j++) {
//       cout << ans[i][j];
//       cout << endl;
//     }
//     cout << endl;
//   }