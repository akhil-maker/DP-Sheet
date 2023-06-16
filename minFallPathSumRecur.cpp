#include<iostream>
#include<vector>
using namespace std;
int f(vector<vector<int>> a, int i, int j){
    if(j<0 || j>=a[0].size()) return 1e9;
    if(i==0) return a[0][j];
    int b = a[i][j] + f(a, i-1, j);
    int dl = a[i][j] + f(a, i-1, j-1);
    int dr = a[i][j] + f(a, i-1, j+1);
    return min(b,min(dl, dr));
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    int mn = 1e9;
    for(int i=0; i<m; i++)
        mn = min(mn, f(a, n-1, i));
    cout<<mn;
}