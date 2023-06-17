#include<iostream>
using namespace std;
string f(string s, string t){
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
    string r = "";
    int i = s.length(), j = t.length();
    while(i>0 && j>0){
        if(s[i-1]==t[j-1])
            r += s[i-1], i--, j--;
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    while(i>0)
        r+=s[i-1], i--;
    while(j>0)
        r+=t[j-1], j--;
    string k = "";
    for(int i=r.length()-1; i>=0; i--)
        k += r[i];
    return k;
}
int main(){
    string s, t;
    cin>>s>>t;
    cout<<f(s, t);
}