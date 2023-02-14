#include<iostream>
using namespace std;
int f(int n, int dp[]){
    if(n<=1) return n;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}
int main(){
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=0; i<n+1; i++)
        dp[i] = -1;
    dp[0] = 1, dp[1] = 1;
    cout<<f(n, dp);
}