#include <bits/stdc++.h>

using namespace std;

const int M = 100+5;
const int C = 1000+5;

int dp[M][C];
int w[M];
int v[M];
int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j-w[i]>=0)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<dp[m][n];
    

    return 0;
}