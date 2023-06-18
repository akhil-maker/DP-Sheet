#include<iostream>
#include<vector>
using namespace std;
int f(int i, int j, int a[], vector<vector<int>>& dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int step = 0, mn = 1e9;
    for(int k=i; k<=j-1; k++){
        step += (a[i-1]*a[k]*a[j]) + f(i, k, a, dp) + f(k+1, j, a, dp);
        mn = min(mn, step);
    }
    return dp[i][j] = mn;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<f(1, n-1, a, dp);
}