#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Making the structure for storing value of Profit,weight and tthie ratio.
struct Node
{
    int profit;
    int weight;
    double ratio;
    
};

//Sorting function
bool compare(Node p,Node q)
{
    return p.ratio>q.ratio;
}


int main()

{
    cout<<"Hello"<<endl;
    //****************************1*************************
    int n,bag_wt;
    cout<<"Enter the numbeer of elements"<<endl;
    cin>>n;
    cout<<"Enter the bag capacity"<<endl;
    cin>>bag_wt;
    //****************************2.**********************
    Node item[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the profit of item"<<i+1<<endl;
        cin>>item[i].profit;
         cout<<"Enter the weight of item"<<i+1<<endl;
        cin>>item[i].weight;
    }
    //*****************************3******************************
    //Claculating the ratio
    for(int i=0;i<n;i++)
    {
        item[i].ratio=(double(item[i].profit)/item[i].weight);
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Profit"<<"->"<<item[i].profit<<"  "<<"weight"<<"->"<<item[i].weight<<"  "<<"Ratio"<<"->"<<item[i].ratio<<endl;
        
    }
    //*******************************4*******************************
    
    sort(item,item+n,compare);
    
    //*******************************5************************************
    int i=0;
    double max_profit=0;
    while(i<n && bag_wt!=0)
    {
        
        if(item[i].weight<bag_wt)
        {
            max_profit=max_profit+item[i].profit;
            bag_wt=bag_wt-item[i].weight;
            
        }
        else
        {
            max_profit=max_profit+item[i].profit*(double(bag_wt)/item[i].weight);
            break;
        }
        i++;
    }
    cout<<"Max profit"<<max_profit<<endl;

    return 0;
    
    
}