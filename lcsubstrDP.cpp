#include<iostream>
using namespace std;
int f(string s, string t){
    int dp[s.length()+1][t.length()+1];
    for(int i=0; i<s.length()+1; i++)
        for(int j=0; j<t.length()+1; j++)
            dp[i][0] = 0, dp[0][j] = 0;
    int ans = 0;
    for(int i=1; i<s.length()+1; i++){
        for(int j=1; j<t.length()+1; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}
int main(){
    string s, t;
    cin>>s>>t;
    cout<<f(s, t);
}