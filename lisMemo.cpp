#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int prev, int arr[], int n, vector<vector<int>>& dp){
    if(ind==n)
        return 0;
    if(prev!=-1 && dp[ind][prev]!=-1)
        return dp[ind][prev];
    int nottake = f(ind+1, prev, arr, n, dp);
    int take = 0;
    if(prev==-1 || arr[ind]>arr[prev])
        take = 1+f(ind+1, ind, arr, n, dp);
    return dp[ind][prev] = max(take, nottake);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout<<f(0, -1, arr, n, dp);
}