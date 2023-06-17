#include<iostream>
using namespace std;
int f(int n, int a[]){
    int dp[n][n+1];
    for(int i=0; i<n; i++)
        dp[i][0] = 0;
    for(int i=0; i<n+1; i++)
        dp[0][i] = i*a[0];
    for(int i=1; i<n; i++){
        for(int j=1; j<n+1; j++){
            int nottake = dp[i-1][j];
            int take = 0, rodlen = i+1;
            if(rodlen<=j)
                take = dp[i][j-rodlen] + a[i];
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n-1][n];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(n, a);
}