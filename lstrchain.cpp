#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(string a, string b){
    return a.length()<b.length();
}
int compare(string a, string b){
    if(a.length()-b.length()!=1) return 0;
    int cnt = 0, i = 0, j = 0;
    while(i<a.length()){
        if(j<b.length() && a[i]==b[j]) i++, j++;
        else i++;
    }
    if(a.length()==i && j==b.length()) return 1;
    return 0;
}
int lsc(vector<string>& arr){
    sort(arr.begin(), arr.end(), comp);
    int n = arr.size();
    vector<int> dp(n, 1);
    int mx = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(compare(arr[i], arr[j])==1 && dp[i]<dp[j]+1)
                dp[i] = dp[j] + 1;
        }
        mx = max(mx, dp[i]);
    }
    return mx;
}
int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0; i<n; i++){
        string p;
        cin>>p;
        v.push_back(p);
    }
    cout<<lsc(v);
}