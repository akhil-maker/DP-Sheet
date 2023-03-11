#include<iostream>
#include<vector>
using namespace std;
int f(int x, int y, vector<vector<int>>& grid){
    if(x<0 || y<0 || grid[x][y]==1)
        return 0;
    if(x==0 && y==0)
        return 1;
    return f(x-1, y, grid) + f(x, y-1, grid);
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
    cout<<f(m-1, n-1, grid);
}