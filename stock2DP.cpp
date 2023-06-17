#include<iostream>
#include<vector>
using namespace std;
int f(int arr[], int n){
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[n][0] = 0, dp[n][1] = 0;
    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            int profit = 0;
            if(buy)
                profit = max(-arr[i]+dp[i+1][0],dp[i+1][1]);
            else
                profit = max(arr[i]+dp[i+1][1], dp[i+1][0]);
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(arr, n);
}