#include<iostream>
#include<vector>
using namespace std;
int f(int m, int n, vector<vector<int>>& grid){
    int dp[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                dp[i][j] = grid[i][j];
            else{
                int up = 1e9, left = 1e9;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = grid[i][j]+min(up, left);
            }
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