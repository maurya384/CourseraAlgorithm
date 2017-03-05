#include<bits/stdc++.h>
using namespace std;
list<int > a[100000];
list<int > b[100000];
vector<int > vct;
void graphrev(int v)
{
    for(int i=0;i<v;i++)
    {
        list<int>::iterator it;
        for(it=b[i].begin();it!=b[i].end();it++)
        {
            b[*it].push_back(i);
        }
    }
}
void dfsstack(int  v,int visit[],stack<int>&st)
{
    visit[v]=1;
    list<int >::iterator it;
    for(it=a[v].begin();it!=a[v].end();it++)
    {
        if(!visit[*it])
            dfsstack(*it,visit,st);
    }
    st.push(v);
}
void dfsprint(int v,int visit[],int *p)
{
    (*p)++;
    visit[v]=1;
    //cout<<v<<" ";
    list<int>::iterator i;
    for (i = b[v].begin(); i != b[v].end(); ++i)
        if (!visit[*i])
            dfsprint(*i, visit,p);
}
void printscc(int v)
{
    stack<int> st;
    int visit[v];
    for(int i=0;i<v;i++)
        visit[i]=0;
    for(int i=0;i<v;i++)
    {
        if(!visit[i])
            dfsstack(i,visit,st);
    }
    graphrev(v);
    for(int i=0;i<v;i++)
        visit[i]=0;

        int x;

    while(st.size()>0)
    {
        int vr=st.top();
        st.pop();
        if(visit[vr]==0)
        {
            x=0;
            dfsprint(vr,visit,&x);
            vct.push_back(x);
            cout<<endl;
        }
    }
    sort(vct.begin(),vct.end());
}
int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int v,e,s,d;
    cout<<"enter the no of vertices and edges"<<endl;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"enter the edges -->"<<endl;
        cin>>s>>d;
        a[s].push_back(d);
    }
    printscc(v);
}

