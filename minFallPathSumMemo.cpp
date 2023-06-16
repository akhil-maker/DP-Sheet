#include<iostream>
#include<vector>
using namespace std;
int f(vector<vector<int>>& a, int i, int j, vector<vector<int>>& dp){
    if(j<0 || j>=a[0].size()) return 1e9;
    if(i==0) return a[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int d = a[i][j] + f(a, i-1, j, dp);
    int dl = a[i][j] + f(a, i-1, j-1, dp);
    int dr = a[i][j] + f(a, i-1, j+1, dp);
    return dp[i][j] = min(d, min(dl, dr));
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int mn = 1e9;
    for(int i=0; i<m; i++)
        mn = min(mn, f(a, n-1, i, dp));
    cout<<mn;
}