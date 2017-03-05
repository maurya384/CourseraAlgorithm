#include<bits/stdc++.h>
using namespace std;
int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    struct city
    {
        int x;
        int y;
    };
    int n;
    cin>>n;
    city TSP[n];
    for(int i=0;i<n;i++)
    {
        cin>>TSP[i].x>>TSP[i].y;
    }
    float distance[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                distance[i][j]=0;
            }
            else
            {
                distance[i][j]=((TSP[i].x-TSP[j].x)*(TSP[i].x-TSP[j].x))+((TSP[i].y-TSP[j].y)*(TSP[i].y-TSP[j].y));
                distance[i][j]=sqrt(distance[i][j]);
            }
        }
    }
    int visit[n];
    for(int i=0;i<n;i++)
    {
        visit[i]=0;
    }
    int source=0;
    int destination=INT_MAX;
    float x,sum=0.0;
    for(int i=0;i<n-1;i++)
    {
        x=INT_MAX;
        visit[source]=1;
        for(int j=0;j<n;j++)
        {
            if((source!=j)&&(!visit[j]))
            {
                if(distance[source][j]<x)
                {
                    x=distance[source][j];
                    destination=j;
                }
                if(distance[source][j]==x)
                {
                    if(j<destination)
                    {
                        x=distance[source][j];
                        destination=j;
                    }
                }
            }
        }
        source =destination;
        sum+=x;
    }
    cout<<sum+distance[destination][0]<<endl;
}
