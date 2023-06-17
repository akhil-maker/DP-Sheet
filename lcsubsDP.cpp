#include<iostream>
#include<vector>
using namespace std;
int f(string s, string t){
    vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, 0));
    for(int i=1; i<s.length()+1; i++){
        for(int j=1; j<t.length()+1; j++){
            int take = 0;
            if(s[i-1]==t[j-1])
                take = 1 + dp[i-1][j-1];
            int nottake = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[s.length()][t.length()];
}
int main(){
    string s, t;
    cin>>s>>t;
    cout<<f(s, t);
}