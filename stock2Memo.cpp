#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int buy, int arr[], int n, vector<vector<int>>& dp){
    if(ind==n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    int profit = 0;
    if(buy)
        profit = max(-arr[ind]+f(ind+1, 0, arr, n, dp), f(ind+1, 1, arr, n, dp));
    else
        profit = max(arr[ind]+f(ind+1, 1, arr, n, dp), f(ind+1, 0, arr, n, dp));
    return dp[ind][buy] = profit;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout<<f(0, 1, arr, n, dp);
}