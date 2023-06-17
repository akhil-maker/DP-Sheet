#include<iostream>
using namespace std;
int f(int a[], int n, int d){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];
    if(sum-d < 0 || (sum-d)%2 != 0) return 0;
    int t = (sum-d)/2;
    int dp[n][t+1];
    for(int i=0; i<n; i++)
        dp[i][0] = 1;
    for(int i=0; i<t+1; i++){
        if(i==0 && a[0]==0)
            dp[0][i] = 2;
        else if(i==0 || i==a[0])
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<t+1; j++){
            int take = (a[i]<=j)?dp[i-1][j-a[i]]:0;
            int nottake = dp[i-1][j];
            dp[i][j] = take + nottake;
        }
    }
    return dp[n-1][t];
}
int main(){
    int n, d;
    cin>>n>>d;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(a, n, d);
}