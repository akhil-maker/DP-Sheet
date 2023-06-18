#include<iostream>
#include<vector>
using namespace std;
int f(int n, vector<int> a){
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n; j++){
            if(i>j) continue;
            int mx = -1e9;
            for(int ind=i; ind<=j; ind++){
                int cost = a[i-1]*a[ind]*a[j+1] + dp[i][ind-1] + dp[ind+1][j];
                mx = max(mx, cost);
            }
            dp[i][j] = mx;
        }
    }
    return dp[1][n];
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n+2, 1);
    for(int i=1; i<=n; i++)
        cin>>a[i];
    cout<<f(n, a);
}