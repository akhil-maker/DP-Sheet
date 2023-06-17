#include<iostream>
#include<vector>
using namespace std;
int f(int ind1, int ind2, string s, string t, vector<vector<int>>& dp){
    if(ind1<0 || ind2<0)
        return 0;
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    int take = 0;
    if(s[ind1]==t[ind2])
        take = 1 + f(ind1-1, ind2-1, s, t, dp);
    int nottake = max(f(ind1-1, ind2, s, t, dp), f(ind1, ind2-1, s, t, dp));
    return dp[ind1][ind2] = max(take, nottake);
}
int main(){
    string s, t;
    cin>>s>>t;
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    cout<<f(s.length()-1, t.length()-1, s, t, dp);
}