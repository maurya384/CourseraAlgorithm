#include<bits/stdc++.h>
using namespace std;
struct graph
{
    int v;
    int e;
    int **a;
};
struct graph *g=(struct graph *)malloc(sizeof(struct graph));
void floyd_warshall()
{
    int dist[g->v][g->v];
    int path[g->v][g->v];
    for(int  i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
            dist[i][j]=g->a[i][j];
        }
    }
    for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
            if(i==j)
                path[i][j]=-1;
            else
                path[i][j]=i;
        }
    }
    for(int k=0;k<g->v;k++)
    {
        for(int i=0;i<g->v;i++)
        {
            for(int j=0;j<g->v;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
    int NEG_Cycle=0;
    for(int  i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
            cout<<dist[i][j]<<" ";
            if(dist[i][i]<0)
            {
                cout<<"Negative cycle exist"<<endl;
                NEG_Cycle=1;
            }
        }
        cout<<endl;
    }
    if(!NEG_Cycle)
    {
        int SHRT=INT_MAX;
        for(int i=0;i<g->v;i++)
        {
            for(int j=0;j<g->v;j++)
            {
                if(dist[i][j]<SHRT)
                {
                    SHRT=dist[i][j];
                }
            }
        }
        cout<<SHRT<<endl;
    }
    for(int  i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j,s,e,w;
   if(!g)
   {
       cout<<"memory error"<<endl;
   }
   cout<<"enter the vertex and edges "<<endl;
   cin>>g->v>>g->e;
   (g->a)=(int**)malloc(sizeof((g->v)*(sizeof(int *))));
   for(int i=0;i<g->v;i++)
   {
       g->a[i]=(int *)malloc((g->v)*(sizeof(int)));
   }
   for(i=0;i<g->v;i++)
   {
      for(j=0;j<g->v;j++)
      {
          if(i==j)
          g->a[i][j]=0;
          else
            g->a[i][j]=10000;
      }
   }
   for(i=1;i<=g->e;i++)
   {
       cout<<"enter the edge in --> manner and corresponding weight "<<endl;
       cin>>s>>e>>w;
       g->a[s][e]=w;
   }
   for(i=0;i<g->v;i++)
   {
      for(j=0;j<g->v;j++)
      {
          cout<<g->a[i][j]<<"  ";
      }
      cout<<endl;
   }
   floyd_warshall();
   free(g);
}

