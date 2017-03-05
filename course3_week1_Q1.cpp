#include<bits/stdc++.h>
using namespace std;
bool sortjob(const pair<int,int> &a , const pair<int,int> &b)
{
    if((a.first-a.second)==(b.first-b.second))
    {
        if(a.first > b.first)
        {
            return (a.first>b.first);
        }
        else
        {
            return (b.first>a.first);
        }
    }
    else
        return ((a.first-a.second)>(b.first-b.second));
}
int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,time=0;
    cin>>n;
    vector<pair <int,int> >job;
    vector <int > ans;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        job.push_back(make_pair(a,b));
    }
    sort(job.begin(),job.end(),sortjob);
    for(int i=0;i<n;i++)
    {
        cout<<job[i].first<<" "<<job[i].second<<endl;
    }
    for(int i=0;i<job.size();i++)
    {
        if(time<=job[i].second)
        {
            time++;
            ans.push_back(job[i].first);
        }
    }
    int weight_ans=0;
    for(int i=0;i<ans.size();i++)
    {
        weight_ans+=ans[i];
    }
    cout<<weight_ans<<endl;
}
