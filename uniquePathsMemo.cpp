#include<iostream>
#include<vector>
using namespace std;
int f(int x, int y, vector<vector<int>>& dp){
    if(x<0 || y<0)
        return 0;
    if(x==0 && y==0)
        return 1;
    if(dp[x][y]!=-1)
        return dp[x][y];
    int up = f(x-1, y, dp), left = f(x, y-1, dp);
    return dp[x][y] = up + left;
}
int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout<<f(m-1, n-1, dp);
}