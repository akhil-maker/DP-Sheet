#include<iostream>
using namespace std;
int f(int ind, int a[], int dp[]){
    if(ind==0)
        return a[0];
    if(ind<0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int pick = a[ind] + f(ind-2, a, dp);
    int notpick = f(ind-1, a, dp);
    return dp[ind] = max(pick, notpick);
}
int main(){
    int a[] = {2, 3, 4};
    int dp[3];
    for(int i=0; i<3; i++)
        dp[i] = -1;
    cout<<f(2, a, dp);
}