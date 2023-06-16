#include<iostream>
#include<vector>
using namespace std;
int f(vector<vector<int>> a, int m, int n){
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
    for(int j1=0; j1<n; j1++){
        for(int j2=0; j2<n; j2++){
            if(j1==j2) dp[m-1][j1][j2] = a[m-1][j1];
            else dp[m-1][j1][j2] = a[m-1][j1] + a[m-1][j2];
        }
    }
    for(int i=m-2; i>=0; i--){
        for(int j1=0; j1<n; j1++){
            for(int j2=n-1; j2>=0; j2--){
                int mx = 0;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        if(j1+dj1<0 || j2+dj2<0 || j1+dj1>=n || j2+dj2>=n)
                            continue;
                        else if(j1==j2) mx = max(mx, a[i][j1]+dp[i+1][j1+dj1][j2+dj2]);
                        else mx = max(mx, a[i][j1]+a[i][j2]+dp[i+1][j1+dj1][j2+dj2]);
                    }
                }
                dp[i][j1][j2] = mx;
            }
        }
    }
    return dp[0][0][n-1];
}
int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> a(m, vector<int>(n, 0));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    cout<<f(a, m, n);
}