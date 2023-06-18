#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int f(vector<int> a, int c){
    int dp[c+2][c+2];
    for(int i=0; i<c+2; i++)
        for(int j=0; j<c+2; j++)
            dp[i][j] = 0;
    for(int i=c; i>=1; i--){
        for(int j=1; j<=c; j++){
            if(i>j) continue;
            int mn = 1e9;
            for(int ind=i; ind<=j; ind++){
                int cost = a[j+1] - a[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mn = min(mn, cost);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][c];
}
int main(){
    vector<int> a;
    int n, m, c;
    cin>>n>>m>>c;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    a.push_back(n);
    a.insert(a.begin(), 0);
    sort(a.begin(), a.end());
    vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
    cout<<f(a, c);
}