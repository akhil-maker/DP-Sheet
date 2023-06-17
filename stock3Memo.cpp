#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int cap, int buy, int arr[], int n, vector<vector<vector<int>>>& dp){
    if(ind==n) return 0;
    if(cap==0) return 0;
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
    int profit = 0;
    if(buy)
        profit = max(-arr[ind]+f(ind+1, cap, 0, arr, n, dp), f(ind+1, cap, 1, arr, n, dp));
    else
        profit = max(arr[ind]+f(ind+1, cap-1, 1, arr, n, dp), f(ind+1, cap, 0, arr, n, dp));
    return dp[ind][buy][cap] = profit;
}
int main(){
    int n, cap;
    cin>>n>>cap;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap+1, -1)));
    cout<<f(0, cap, 1, arr, n, dp);
}