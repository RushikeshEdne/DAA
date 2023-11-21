#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

//****************************1.********************************
vector<int>bellman(int V,vector<vector<int>> &edges,int S)
{
    vector<int>dist(V,1e8);
    dist[S]=0;

    //*******************2.******************************
    //Itterate all the edges n-1 times i.e number of vertex
    
    for(int i=0;i<V-1;i++)
    {
        for(auto it :edges)
        {
            
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
    }
    //***********************3.**************************
    //One more itterationn to check the negative cycle
    for(auto it : edges)
    {
        
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v])
        {
            cout<<"Negative cycle present"<<endl;
        }
    }
    return dist;
}

int main()
{
    //**********************4.*****************************
    int V,ne;
    cout<<"Enter the number of vertices"<<endl;
    cin>>V;
    
    cout<<"Enter number of edges"<<endl;
    cin>>ne;
    vector<vector<int>> edges(ne,vector<int>(3));
    

    //*****************************5.*******************************
    cout<<"Enter the info about edge (Source  Dist  distnce)"<<endl;
    for(int i=0;i<ne;i++)
    {
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
        
    for(int i=0;i<ne;i++)
    {
        cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<endl;
    }
    //************************6.*************************
    int S;
    cout<<"Enter the source vertex"<<endl;
    cin>>S;
    
    //*************************7.*********************
    vector<int> dist=bellman(V,edges,S);
     cout << "Shortest distances from source vertex " << S << " are:" << endl;
    for(auto d : dist)
    {
        cout<<d<<" ";
    }
    cout<<endl;
        
    
    
    
    return 0;
}