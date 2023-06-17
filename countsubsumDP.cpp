#include<iostream>
#include<vector>
using namespace std;
int f(int a[], int n, int t){
    vector<vector<int>> dp(n, vector<int>(t+1, 0));
    for(int i=0; i<n; i++)
        dp[i][0] = 1;
    for(int i=0; i<t+1; i++)
        dp[0][i] = (a[0]==i);
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
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    cout<<f(a, n, k);
}