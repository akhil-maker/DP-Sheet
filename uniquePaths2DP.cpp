#include<iostream>
#include<vector>
using namespace std;
int f(int m, int n, vector<vector<int>>& grid){
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1)
                dp[i][j] = 0;
            else if(i==0 && j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = ((i>0)?dp[i-1][j]:0) + ((j>0)?dp[i][j-1]:0);
        }
    }
    return dp[m-1][n-1];
}
int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            grid[i][j] = x;
        }
    }
    cout<<f(m, n, grid);
}