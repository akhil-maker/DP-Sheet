#include<iostream>
#include<vector>
using namespace std;
int f(int i, int j, vector<int> a, vector<vector<int>>& dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mx = -1e9;
    for(int ind=i; ind<=j; ind++){
        int cost = a[i-1]*a[ind]*a[j+1] + f(i, ind-1, a, dp) + f(ind+1, j, a, dp);
        mx = max(mx, cost);
    }
    return dp[i][j] = mx;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n+2, 1);
    for(int i=1; i<=n; i++)
        cin>>a[i];
    vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
    cout<<f(1, n, a, dp);
}