#include<iostream>
#include<vector>
using namespace std;
int f(int n, int cap, int arr[]){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(cap+1, 0)));
    for(int ind=n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                int profit = 0;
                if(buy)
                    profit = max(-arr[ind]+dp[ind+1][0][cap], dp[ind+1][1][cap]);
                else
                    profit = max(arr[ind]+dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                dp[ind][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][cap];
}
int main(){
    int n, cap;
    cin>>n>>cap;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(n, cap, arr);
}