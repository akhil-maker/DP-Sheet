#include<iostream>
#include<vector>
using namespace std;
int f(int n, vector<vector<int>>& grid){
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(grid[0][1], grid[0][2]);
    dp[0][1] = max(grid[0][0], grid[0][2]);
    dp[0][2] = max(grid[0][0], grid[0][1]);
    dp[0][3] = max(grid[0][0], max(grid[0][1], grid[0][2]));
    for(int day=1; day<n; day++){
        for(int last=0; last<=3; last++){
            int mx = 0;
            for(int i=0; i<3; i++)
                mx = max(mx, grid[day][i]+dp[day-1][i]);
            dp[day][last] = mx;
        }
    }
    return dp[n-1][3];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n, vector<int>(3, 0));
    for(int i=0; i<n; i++){
        int x, y, z;
        cin>>x>>y>>z;
        grid[i][0] = x, grid[i][1] = y, grid[i][2] = z;
    }
    int mx = f(n, grid);
    cout<<mx;
}