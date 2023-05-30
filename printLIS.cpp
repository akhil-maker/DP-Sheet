#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> printLIS(int arr[], int n){
    vector<int> hash(n), dp(n, 1);
    int lastInd = 0, mx = 1;
    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if(dp[i]>mx){
            mx = dp[i];
            lastInd = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastInd]);
    while(lastInd!=hash[lastInd]){
        lastInd = hash[lastInd];
        temp.push_back(arr[lastInd]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr[i] = x;
    }
    vector<int> ans = printLIS(arr, n);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}