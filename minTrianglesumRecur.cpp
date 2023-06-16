#include<iostream>
#include<vector>
using namespace std;
int f(vector<vector<int>> a, int i, int j){
    int n = a.size();
    if(i==n-1) return a[n-1][j];
    int d = a[i][j] + f(a, i+1, j);
    int dg = a[i][j] + f(a, i+1, j+1);
    return min(d, dg);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            cin>>a[i][j];
    cout<<f(a, 0, 0);
}