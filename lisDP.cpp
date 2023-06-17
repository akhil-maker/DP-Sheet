#include<iostream>
#include<vector>
using namespace std;
int f(int arr[], int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>=-1; j--){
            int nottake = dp[i+1][j+1];
            int take = 0;
            if(j==-1 || arr[i]>arr[j])
                take = 1+dp[i+1][j+1];
            dp[i][j+1] = max(take, nottake);
        }
    }
    return dp[0][0];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(arr, n);
}