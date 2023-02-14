#include<iostream>
#include<vector>
using namespace std;
int f(int n, int a[], vector<int>& dp){
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int left = f(n-1, a, dp) + abs(a[n]-a[n-1]);
    int right = INT_MAX;
    if(n>1)
        right = f(n-2, a, dp) + abs(a[n]-a[n-2]);
    return dp[n] = min(left, right);
}
int main(){
    int a[] = {30, 10, 60, 10, 60, 50};
    vector<int> dp(6, -1);
    cout<<f(5, a, dp);
}