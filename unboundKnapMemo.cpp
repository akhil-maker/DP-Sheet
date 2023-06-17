#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int W, int wt[], int val[], vector<vector<int>>& dp){
    if(W==0)
        return 0;
    if(ind==0)
        return val[ind]*(W/wt[ind]);
    if(dp[ind][W]!=-1)
        return dp[ind][W];
    int nottake = f(ind-1, W, wt, val, dp);
    int take  = 0;
    if(wt[ind]<=W)
        take = f(ind, W-wt[ind], wt, val, dp) + val[ind];
    return dp[ind][W] = max(take, nottake);
}
int main(){
    int n, W;
    cin>>n>>W;
    int wt[n], val[n];
    for(int i=0; i<n; i++)
        cin>>wt[i];
    for(int i=0; i<n; i++)
        cin>>val[i];
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    cout<<f(n-1, W, wt, val, dp);
}