#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int buy, int arr[], int n, int fee, vector<vector<int>>& dp){
    if(ind==n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    if(buy)
        return dp[ind][buy] = max(-arr[ind]+f(ind+1, 0, arr, n, fee, dp), f(ind+1, buy, arr, n, fee, dp));
    else
        return dp[ind][buy] = max(arr[ind]+f(ind+1, 1, arr, n, fee, dp)-fee, f(ind+1, 0, arr, n, fee, dp));
}
int main(){
    int n, fee;
    cin>>n>>fee;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout<<f(0, 1, arr, n, fee, dp);
}