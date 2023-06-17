#include<iostream>
#include<vector>
using namespace std;
int f(int i, int j, string s, string t, vector<vector<int>>& dp){
    if(j<0) return i+1;
    if(i<0) return j+1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==t[j])
        return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
    return dp[i][j] = 1+min(f(i-1, j-1, s, t, dp), min(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp)));
}
int main(){
    string s, t;
    cin>>s>>t;
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    cout<<f(s.length()-1, t.length()-1, s, t, dp);
}