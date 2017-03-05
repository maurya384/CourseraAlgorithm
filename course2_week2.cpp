#include<bits/stdc++.h>
using namespace std;
struct node_distance
{
        int source;
        int dis;
};
bool operator <(const node_distance& b,const node_distance& c){
    return(b.dis>c.dis);
}
priority_queue<node_distance,vector<node_distance> >q;
struct graph
{
    int v;
    int e;
    int **a;
};
struct graph *g=(struct graph *)malloc(sizeof(struct graph));
void dijkstra(int);
int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j,as,b,s,w;
   if(!g)
   {
       cout<<"memory error"<<endl;
   }
   cout<<"enter the no.of vertices and edges"<<endl;
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
          g->a[i][j]=0;
      }
   }
   for(i=1;i<=g->e;i++)
   {
       cout<<"enter the vertices having an edge in -> manner and associated weight"<<endl;
       cin>>as>>b>>w;
       g->a[as][b]=w;
   }
   for(i=0;i<g->v;i++)
   {
      for(j=0;j<g->v;j++)
      {
          cout<<g->a[i][j];
      }
      cout<<endl;
   }
   cout<<"enter the source  vertex"<<endl;
   cin>>s;
   dijkstra(s);
}
void dijkstra(int s)
{
    int ve,d,distance[g->v],path[g->v];
    for(int i=0;i<g->v;i++)
    {
        distance[i]=-1;
    }
    distance[s]=0;
    node_distance b={s,0};
    q.push(b);
    for(int i=0;i<g->v;i++)
    {
        path[i]=0;
    }
    while(q.size()>0)
    {
        node_distance temp=q.top();
        ve=temp.source;
        cout<<temp.source<<endl;
        q.pop();
        for(int w=0;w<g->v;w++)
        {
            if(g->a[ve][w])
            {
                 d=distance[ve]+g->a[ve][w];
                if(distance[w]==-1)
                {
                        node_distance c={w,d};
                q.push(c);
                path[w]=ve;
                }
                if(distance[w]>d)
                {
                    node_distance n;
                    n.source=w;
                    n.dis=d;
                    q.push(n);
                    path[w]=ve;
                }
            }
        }
    }

}

