// change integer  value to long long int for large values
#include<bits/stdc++.h>
using namespace std;
int w[100];
int v[100];
int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,cap,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    cin>>cap;
    int m[n+1][cap+1];
    for (int i=0;i<= n;i++)
   {
       for (int j=0;j<= cap; j++)
       {
           if (i==0 || j==0)
               m[i][j] = 0;
           else if (w[i-1] <= j)
                 m[i][j] = max(v[i-1] + m[i-1][j-w[i-1]],  m[i-1][j]);
           else
                 m[i][j] = m[i-1][j];
       }
   }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"maximum value is "<<m[n][cap]<<endl;
}
