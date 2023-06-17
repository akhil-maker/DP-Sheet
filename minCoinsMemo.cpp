#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int tar, int a[], vector<vector<int>>& dp){
    if(tar==0) return 0;
    if(ind==0){
        if(tar%a[ind]==0) return tar/a[ind];
        return 1e9;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int take = 1e9;
    if(a[ind]<=tar)
        take = f(ind, tar-a[ind], a, dp)+1;
    int nottake = f(ind-1, tar, a, dp);
    return dp[ind][tar] = min(take, nottake);
}
int main(){
    int n, t;
    cin>>n>>t;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<vector<int>> dp(n, vector<int>(t+1, -1));
    cout<<f(n-1, t, a, dp);
}