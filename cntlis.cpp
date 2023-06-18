#include<iostream>
#include<vector>
using namespace std;
int f(int n, int a[]){
    vector<int> dp(n, 1), cnt(n, 1);
    int mx = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i]>a[j] && dp[i]<dp[j]+1){
                dp[i] = dp[j] + 1;
                cnt[i] = cnt[j];
            }
            else if(a[i]>a[j] && dp[j]+1==dp[i])
                cnt[i] += cnt[j];
        }
        mx = max(mx, dp[i]);
    }
    int nos = 0;
    for(int i=0; i<n; i++)
        if(dp[i]==mx)
            nos += cnt[i];
    return nos;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n; i++)
        cin>>a[i];
    cout<<f(n, a);
}