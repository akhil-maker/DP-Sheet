#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int trans, int arr[], int n, int k, vector<vector<int>>& dp){
    if(ind==n || trans==2*k) return 0;
    if(dp[ind][trans]!=-1)  
        return dp[ind][trans];
    if(trans%2==0)
        return dp[ind][trans] = max(-arr[ind]+f(ind+1, trans+1, arr, n, k, dp), f(ind+1, trans, arr, n, k, dp));
    else
        return dp[ind][trans] = max(arr[ind]+f(ind+1, trans+1, arr, n, k, dp), f(ind+1, trans, arr, n, k, dp));
}
int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<vector<int>> dp(n, vector<int>(2*k, -1));
    cout<<f(0, 0, arr, n, k, dp);
}