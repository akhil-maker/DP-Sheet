#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> f(int n, int arr[]){
    int dp[n], hash[n];
    for(int i=0; i<n; i++)
        dp[i] = 1;
    int mx = 1, lastInd = 0;
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int prev=0; prev<i; prev++){
            if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i]){
                dp[i] = 1+dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i]>mx){
            mx = dp[i];
            lastInd = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastInd]);
    while(hash[lastInd]!=lastInd){
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
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> v = f(n, arr);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
}