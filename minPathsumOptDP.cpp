#include<iostream>
#include<vector>
using namespace std;
int f(int m, int n, vector<vector<int>>& grid){
    int prev[n];
    for(int i=0; i<m; i++){
        int cur[n];
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                cur[j] = grid[i][j];
            else{
                int up = grid[i][j], left = grid[i][j];
                if(i>0) up += prev[j];
                else up = 1e9;
                if(j>0) left += cur[j-1];
                else left = 1e9;
                cur[j] = min(up, left);
            }
        }
        for(int k=0; k<n; k++)
            prev[k] = cur[k];
    }
    return prev[n-1];
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