#include<iostream>
#include<vector>
using namespace std;
int f(vector<vector<int>> a, int n, int m){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0; i<m; i++)
        dp[0][i] = a[0][i];
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int d = 1e9, dl = 1e9, dr = 1e9;
            d = a[i][j] + dp[i-1][j];
            if(j>=1) dl = a[i][j] + dp[i-1][j-1];
            if(j<m-1) dr = a[i][j] + dp[i-1][j+1];
            dp[i][j] = min(d, min(dl, dr));
        }
    }
    int mn = 1e9;
    for(int i=0; i<m; i++)
        mn = min(mn, dp[n-1][i]);
    return mn;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)  
            cin>>a[i][j];
    cout<<f(a, n, m);
}