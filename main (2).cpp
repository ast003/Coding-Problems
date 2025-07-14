
#include <bits/stdc++.h>
using namespace std;
int f(vector<vector<int>>&cost,int i,int n,int mask,vector<vector<int>>&dp){
    if(i==n){
        return 0;
    }
    if(dp[i][mask]!=-1){
        return dp[i][mask];
    }
    int ans=INT_MAX;
    for(int j=0;j<n;j++){
        if(mask&(1<<j)){
            ans=min(ans,cost[i][j]+f(cost,i+1,n,mask^(1<<j),dp));
        }
    }
    return dp[i][mask]=ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>cost(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(1<<n,-1));
    cout<< f(cost,0,n,(1<<n)-1,dp);
    
}