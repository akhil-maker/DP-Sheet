#include<iostream>
using namespace std;
int f(int n, int a[]){
    if(n==0)
        return 0;
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int left = dp[i-1] + abs(a[i]-a[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = dp[i-2] + abs(a[i]-a[i-2]);
        dp[i] = min(left, right);
    }
    return dp[n];
}
int main(){
    int a[] = {30, 10, 60, 10, 60, 50};
    cout<<f(5, a);
}