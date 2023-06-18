#include<iostream>
#include<vector>
using namespace std;
int f(int i, int j, vector<int> a){
    if(i>j) return 0;
    int mx = -1e9;
    for(int ind=i; ind<=j; ind++){
        int cost = a[i-1]*a[ind]*a[j+1] + f(i, ind-1, a) + f(ind+1, j, a);
        mx = max(mx, cost);
    }
    return mx;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n+2, 1);
    for(int i=1; i<=n; i++)
        cin>>a[i];
    cout<<f(1, n, a);
}