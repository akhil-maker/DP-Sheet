#include<iostream>
using namespace std;
int f(int n, int W, int wt[], int val[]){
    int dp[n][W+1];
    for(int i=0; i<n; i++)
        dp[i][0] = 0;
    for(int i=0; i<W+1; i++)
        dp[0][i] = (i/wt[0])*val[0];
    for(int i=1; i<n; i++){
        for(int j=1; j<W+1; j++){
            int nottake = dp[i-1][j];
            int take = 0;
            if(wt[i]<=j)
                take = dp[i][j-wt[i]]+val[i];
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n-1][W];
}
int main(){
    int n, W;
    cin>>n>>W;
    int wt[n], val[n];
    for(int i=0; i<n; i++)
        cin>>wt[i];
    for(int i=0; i<n; i++)
        cin>>val[i];
    cout<<f(n-1, W, wt, val);
}