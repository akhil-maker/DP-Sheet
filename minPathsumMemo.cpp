#include<iostream>
#include<vector>
using namespace std;
int f(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(x<0 || y<0 )
        return 1e9;
    if(x==0 && y==0)
        return grid[x][y];
    if(dp[x][y]!=-1)
        return dp[x][y];
    return dp[x][y] = grid[x][y] + min(f(x-1, y, grid, dp), f(x, y-1, grid, dp));
}
int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            grid[i][j] = x;
        }
    }
    cout<<f(m-1, n-1, grid, dp);
}