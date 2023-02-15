#include<iostream>
using namespace std;
int f(int n, int a[]){
    int dp[n+1];
    dp[0] = a[0];
    for(int i=1; i<n; i++){
        int take = a[i];
        if(i>1)
            take += dp[i-2];
        int nottake = dp[i-1];
        dp[i] = max(take, nottake);
    }
    return dp[n-1];
}
int main(){
    int a[] = {2, 3, 4};
    cout<<f(3, a);
}