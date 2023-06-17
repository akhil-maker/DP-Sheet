#include<iostream>
#include<vector>
using namespace std;
int f(int arr[], int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
    for(int i=0; i<n+1; i++)
        for(int j=0; j<=2*k; j++)
            dp[n][j] = 0, dp[i][2*k] = 0;
    for(int i=n-1; i>=0; i--){
        for(int j=2*k-1; j>=0; j--){
            if(j%2==0)
                dp[i][j] = max(-arr[i]+dp[i+1][j+1], dp[i+1][j]);
            else
                dp[i][j] = max(arr[i]+dp[i+1][j+1], dp[i+1][j]);
        }
    }
    return dp[0][0];
}
int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(arr, n, k);
}