#include<iostream>
using namespace std;
int f(string s, string t){
    int dp[s.length()+1][t.length()+1];
    for(int i=0; i<s.length()+1; i++)
        for(int j=0; j<t.length()+1; j++)
            dp[i][0] = i, dp[0][j] = j;
    for(int i=1; i<s.length()+1; i++){
        for(int j=1; j<t.length()+1; j++){
            if(s[i-1]==t[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[s.length()][t.length()];
}
int main(){
    string s, t;
    cin>>s>>t;
    cout<<f(s, t);
}