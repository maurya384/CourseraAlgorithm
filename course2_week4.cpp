#include<bits/stdc++.h>
using namespace std;
int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,sum=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((a[i]!=a[j])&&(((a[i]+a[j])>=-10000)&&((a[i]+a[j])<=10000)))
            {
                sum++;
            }
        }
    }
    cout<<sum<<endl;
}
