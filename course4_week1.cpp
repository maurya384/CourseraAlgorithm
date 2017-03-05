#include<bits/stdc++.h>
using namespace std;
int TSP[15][15];
int dp[(1<<12)+5][12];

int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j,n,ans,k,p;
    while(1) {
        scanf("%d",&n);
        if (n==0) break;
        n++;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin>>TSP[i][j];
            }
        }
        //floyd algorithm, get any two points's minimum distance
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (i!=j && i!=k && j!=k) TSP[i][j]=min(TSP[i][k]+TSP[k][j],TSP[i][j]);
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        dp[1][0]=0;
        // TSP solution here,bitmask and DP
        for (int i=1; i<(1<<n); i++) {// the current state
            for (int j=0; j<n; j++) {// during the current state,the last station is j
                if (dp[i][j]==-1) continue;
                for (int k=1; k<n; k++) {//the next state is k
                    if ((i & (1<<k))!=0) continue;
                    p=(i | (1<<k));// the new state(join k)
                    if (dp[p][k]==-1) dp[p][k]=dp[i][j]+TSP[j][k];
                    dp[p][k]=min(dp[p][k],dp[i][j]+TSP[j][k]);
                }
            }
        }
        int ans=INT_MAX;
        // get answer
        for (int i=1; i<n; i++) {
            if (dp[(1<<n)-1][i]>0) ans=min(ans,dp[(1<<n)-1][i]+TSP[i][0]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
