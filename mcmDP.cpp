#include<iostream>
using namespace std;
int f(int n, int a[]){
    int dp[n][n];
    for(int i=0; i<n; i++)
        dp[i][i] = 0;
    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<n; j++){
            int mn = 1e9;
            for(int k=i; k<j; k++){
                int step = a[i-1]*a[k]*a[j] + dp[i][k] + dp[k+1][j];
                mn = min(mn, step);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][n-1];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(n, a);
}