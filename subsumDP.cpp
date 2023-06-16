#include<iostream>
#include<vector>
using namespace std;
bool f(int a[], int n, int t){
    vector<vector<bool>> dp(n, vector<bool>(t+1, false));
    for(int i=0; i<n; i++)
        dp[i][0] = true;
    for(int j=0; j<t+1; j++)
        dp[0][j] = (a[0]==j);
    for(int i=1; i<n; i++){
        for(int j=1; j<t+1; j++){
            bool take = (a[i]<=j)?dp[i-1][j-a[i]]:false;
            bool nottake = dp[i-1][j];
            dp[i][j] = take || nottake;
        }
    }
    return dp[n-1][t];
}
int main(){
    int n, t;
    cin>>n>>t;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(a, n, t);
}