#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knap(int weight[],int profit[],int n,int maxweight)
{
    int dp[n+1][maxweight+2];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=maxweight;j++)
        {
            if(i==0|| j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=maxweight;j++)
        {
            if(weight[i-1]<=j)
            {
                dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    cout<<"Tabular repesentation"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=maxweight;j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    return dp[n][maxweight];
    
}

int main()
{
    int n,capacity;
    cout<<"Enter the elements"<<endl;
    cin>>n;
    
    cout<<"Enter the capacity of bag"<<endl;
    cin>>capacity;
    
    int weight[n],profit[n];
    cout<<"Enter the weights"<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    
    cout<<"Enter the profits"<<endl;
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }
    
    int maxprofit=knap(weight,profit,n,capacity);
    cout<<"MAxprofit"<<maxprofit<<endl;
    return 0;
    
    
    
}

