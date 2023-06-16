#include<iostream>
#include<vector>
using namespace std;
int f(vector<vector<int>>& a, int i, int j1, int j2){
    if(j1<0 || j2<0 || j1>=a[0].size() || j2>=a[0].size())
        return  -1e9;
    if(i==a.size()-1){
        if(j1==j2) return a[i][j1];
        return a[i][j1] + a[i][j2];
    }
    int mx = 0;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            if(j1==j2)
                mx = max(mx, a[i][j1] + f(a, i+1, j1+dj1, j2+dj2));
            else
                mx = max(mx, a[i][j1]+a[i][j2] + f(a, i+1, j1+dj1, j2+dj2));
        }
    }
    return mx;
}
int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> a(m, vector<int>(n, 0));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    cout<<f(a, 0, 0, m-1);
}