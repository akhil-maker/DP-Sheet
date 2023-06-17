#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int t, int a[], vector<vector<int>>& dp){
    if(t==0)
        return 1;
    if(ind==0)
        return (a[ind]==t);
    if(dp[ind][t]!=-1)
        return dp[ind][t];
    int take = (a[ind]<=t)?f(ind-1, t-a[ind], a, dp):0;
    int nottake = f(ind-1, t, a, dp);
    return take+nottake;
}
int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    cout<<f(n-1, k, a, dp);
}