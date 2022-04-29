#include<iostream>
#include<limits.h>
using namespace std;

int Min_dist(int dis[], bool X[]) 
{
    int Min=INT_MAX,indexx;
              
    for(int m=0;m<5;m++) 
    {
        if(X[m]==false && dis[m]<=Min)      
        {
            Min=dis[m];
            indexx=m;
        }
    }
    return indexx;
}

void Dijk(int Grph[5][5],int S) 
{
    int dis[5];                             
    bool X[5];
    
     
    for(int m = 0; m<5; m++)
    {
        dis[m] = INT_MAX;
        X[m] = false;    
    }
    
    dis[S] = 0;                
    
    for(int m=0; m<5; m++)                           
    {
        int i=Min_dist(dis,X); 
        X[i]=true;
        for(int m=0; m<5; m++)                  
        {
            if(!X[m] && Grph[i][m] && dis[i]!=INT_MAX && dis[i]+Grph[i][m]<dis[m])
                dis[m]=dis[i]+Grph[i][m];
        }
    }
    cout<<"The Distance from source vertex"<<endl;
    for(int m=0; m<5; m++)                      
    { 
        char s = 65+m; 
        cout<<s<<"\t"<<dis[m]<<endl;
    }
}

int main()
{
    int Grph[5][5]={
        {0, 1, 0, 0, 2},
        {2, 0, 0, 5, 0},
        {0, 0, 1, 3, 0},
        {0, 5, 3, 0, 2},
        {0, 1, 2, 0, 5},
       };
    Dijk(Grph,0);
    return 0;                           
}
