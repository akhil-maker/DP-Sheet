#include<iostream>
#include<vector>
using namespace std;
int f(int arr[], int n, int fee){
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    for(int i=n-1; i>=0; i--){
        for(int buy=1; buy>=0; buy--){
            if(buy)
                dp[i][buy] = max(-arr[i]+dp[i+1][0], dp[i+1][1]);
            else
                dp[i][buy] = max(arr[i]+dp[i+1][1]-fee, dp[i+1][0]);
        }
    }
    return dp[0][1];
}
int main(){
    int n, fee;
    cin>>n>>fee;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(arr, n, fee);
}