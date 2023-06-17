#include<iostream>
using namespace std;
int f(int n, int tar, int a[]){
    int dp[n][tar+1];
    for(int i=0; i<n; i++)
        dp[i][0] = 0;
    for(int i=0; i<tar+1; i++){
        if(i%a[0]==0) dp[0][i] = i/a[0];
        else dp[0][i] = 1e9;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<tar+1; j++){
            int take = 1e9;
            if(a[i]<=j)
                take = dp[i][j-a[i]]+1;
            int nottake = dp[i-1][j];
            dp[i][j] = min(take, nottake);
        }
    }
    return dp[n-1][tar];
}
int main(){
    int n, t;
    cin>>n>>t;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(n, t, a);
}