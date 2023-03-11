#include<iostream>
#include<vector>
using namespace std;
int f(int n, vector<vector<int>>& grid){
    vector<int> prev(4, -1);
    prev[0] = max(grid[0][1], grid[0][2]);
    prev[1] = max(grid[0][0], grid[0][2]);
    prev[2] = max(grid[0][0], grid[0][1]);
    prev[3] = max(grid[0][0], max(grid[0][1], grid[0][2]));
    for(int day=1; day<n; day++){
        vector<int> cur(4, -1);
        for(int last=0; last<=3; last++){
            int mx = 0;
            for(int i=0; i<3; i++)
                mx = max(mx, grid[day][i]+prev[i]);
            cur[last] = mx;
        }
        prev = cur;
    }
    return prev[3];
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