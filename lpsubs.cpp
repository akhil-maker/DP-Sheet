#include<iostream>
using namespace std;
int lps(string s){
    string t = "";
    for(int i=s.length()-1; i>=0; i--)
        t += s[i];
    int dp[s.length()+1][t.length()+1];
    for(int i=0; i<s.length()+1; i++)
        for(int j=0; j<t.length()+1; j++)
            dp[i][0] = 0, dp[0][j] = 0;
    for(int i=1; i<s.length()+1; i++){
        for(int j=1; j<t.length()+1; j++){
            if(s[i-1]==t[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[s.length()][s.length()];
}
int main(){
    string s;
    cin>>s;
    cout<<lps(s);
}
