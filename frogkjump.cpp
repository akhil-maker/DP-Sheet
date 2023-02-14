#include <bits/stdc++.h>
using namespace std;
int f(int n, int k, vector<int>& heights){
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int ans = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j >= 0)
                ans = min(dp[i-j]+abs(heights[i]-heights[i-j]), ans);
        }
        dp[i] = ans;
    }
    return dp[n];
}
int frogJump(int n, int k, vector<int>& heights){
    return f(n-1, k, heights);
}
int main() {
    // Write C++ code here
    vector<int> heights = {30,10,60 , 10 , 60 , 50};
    int n=heights.size();
    int k=2;
    cout<<frogJump(n, k, heights);

    return 0;
}