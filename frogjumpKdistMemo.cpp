#include<iostream>
using namespace std;
int f(int ind, int k, int a[], int dp[]){
    if(ind==0)
        return dp[0] = 0;
    if(dp[ind]!=-1)
        return dp[ind];

    int msteps = INT_MAX;
    for(int j=1; j<=k; j++){
        int jump = INT_MAX;
        if(ind-j>=0)
            jump = f(ind-j, k, a, dp) + abs(a[ind]-a[ind-j]);
        msteps = min(msteps, jump);
    }
    return dp[ind] = msteps;
}
int main(){
    int a[] = {30, 10, 60, 10, 60, 50};
    int dp[6];
    for(int i=0; i<6; i++)
        dp[i] = -1;
    cout<<f(5, 3, a, dp);
}