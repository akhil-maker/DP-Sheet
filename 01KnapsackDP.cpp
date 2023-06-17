#include<iostream>
#include<vector>
using namespace std;
int f(int n, int W, int wt[], int val[]){
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    for(int i=0; i<n; i++)
        dp[i][0] = 0;
    for(int i=0; i<W+1; i++){
        if(i>=wt[0])
            dp[0][i] = val[0];
        else dp[0][i] = 0;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=W; j++){
            int nottake = dp[i-1][j];
            int take = 0;
            if(j>=wt[i])
                take = dp[i-1][j-wt[i]]+val[i];
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
    cout<<f(n, W, wt, val);
}