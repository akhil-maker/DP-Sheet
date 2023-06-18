#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int f(int i, int j, vector<int> a, vector<vector<int>>& dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn = 1e9;
    for(int ind=i; ind<=j; ind++){
        int cost = a[j+1]-a[i-1]+f(i, ind-1, a, dp)+f(ind+1, j, a, dp);
        mn = min(mn, cost);
    }
    return dp[i][j] = mn;
}
int main(){
    vector<int> a;
    int n, m, c;
    cin>>n>>m>>c;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    a.push_back(n);
    a.insert(a.begin(), 0);
    sort(a.begin(), a.end());
    vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
    cout<<f(1, c, a, dp);
}
