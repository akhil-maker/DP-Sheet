#include<iostream>
#include<vector>
using namespace std;
int f(int day, int last, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(day==0){
        int mx = 0;
        for(int i=0; i<3; i++)
            if(i!=last)
                mx = max(mx, grid[day][i]);
        return mx;
    }
    if(dp[day][last]!=-1)
        return dp[day][last];
    int mx = 0;
    for(int i=0; i<3; i++)
        mx = max(mx, grid[day][i]+f(day-1, i, grid, dp));

    return dp[day][last] = mx;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n, vector<int>(3, 0));
    vector<vector<int>> dp(n, vector<int>(4, -1));
    for(int i=0; i<n; i++){
        int x, y, z;
        cin>>x>>y>>z;
        grid[i][0] = x, grid[i][1] = y, grid[i][2] = z;
    }
    int mx = 0;
    for(int i=0; i<=3; i++)
        mx = max(mx, f(n-1, i, grid, dp));

    cout<<mx;
}