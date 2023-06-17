#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int buy, int n, int arr[], vector<vector<int>>& dp){
    if(ind>=n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy)
        return dp[ind][buy] = max(-arr[ind]+f(ind+1, 0, n, arr, dp), f(ind+1, 1, n, arr, dp));
    else
        return dp[ind][buy] = max(arr[ind]+f(ind+2, 1, n, arr, dp), f(ind+1, 0, n, arr, dp));
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout<<f(0, 1, n, arr, dp);
}