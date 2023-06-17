#include<iostream>
using namespace std;
int solve(int a[], int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];
    bool dp[n][sum+1];
    for(int i=0; i<n; i++)
        dp[i][0] = true;
    for(int i=0; i<sum+1; i++)
        dp[0][i] = (a[0]==i);
    for(int i=1; i<n; i++){
        for(int j=1; j<sum+1; j++){
            bool nottake = dp[i-1][j];
            bool take = (a[i]<=j)?dp[i-1][j-a[i]]:false;
            dp[i][j] = take || nottake;
        }
    }
    int mn = 1e9;
    for(int i=0; i<=sum/2; i++)
        if(dp[n-1][i]==true)
            mn = min(mn, abs(sum-i-i));
    return mn;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<solve(a, n);
}