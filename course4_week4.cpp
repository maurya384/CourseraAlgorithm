#include<bits/stdc++.h>
using namespace std;
int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[6];
    for(int i=0;i<6;i++)
    {
    int a,b,n;
    cin>>n;
    cin>>a>>b;
    int c;
    if(a<0)
    {
        if(b<0)
        {
            c=~a|~b;
        }
        else
        {
            c=~a|b;
        }
    }
    else
    {
        if(b<0)
        {
            c=a|~b;
        }
        else
        {
            c=a|b;
        }
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        if(a<0)
        {
             if(b<0)
             {
                 c=c&(~a|~b);
             }
             else
             {
                 c=c&(~a|b);
             }
        }
        else
        {
            if(b<0)
            {
                c=c&(a|~b);
            }
            else
            {
                c=c&(a|b);
            }
        }
    }
    if(c > 0)
    {
        s[i]='1';
    }
    else
    {
        s[i]='0';
    }
    }
}
