#include<iostream>
#include<vector>
using namespace std;
int f(int day, int last, vector<vector<int>>& grid){
    int n = grid.size();
    if(day==0){
        int mx = 0;
        for(int i=0; i<3; i++)
            if(i!=last)
                mx = max(mx, grid[day][i]);
        return mx;
    }
    int mx = 0;
    for(int i=0; i<3; i++)
        if(i!=last)
            mx = max(mx, grid[day][i] + f(day-1, i, grid));
    return mx;
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
    int mx = 0;
    for(int i=0; i<=3; i++)
        mx = max(mx, f(n-1, i, grid));
    cout<<mx;
}