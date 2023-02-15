#include<iostream>
using namespace std;
int f(int n, int k, int a[]){
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int msteps = INT_MAX;
        for(int j=1; j<=k; j++){
            int jump = INT_MAX;
            if(i-j >=0)
                jump = dp[i-j] + abs(a[i]-a[i-j]);
            msteps = min(msteps, jump);
        }
        dp[i] = msteps;
    }
    return dp[n-1];
}
int main(){
    int a[] = {30, 10, 60, 10, 60, 50};
    cout<<f(6, 3, a);
}