#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int f(int i, int j, vector<int>& a){
    if(i>j)
        return 0;
    int mn = 1e9;
    for(int ind=i; ind<=j; ind++){
        int cost = a[j+1]-a[i-1] + f(i, ind-1, a) + f(ind+1, j, a);
        mn = min(mn, cost);
    }
    return mn;
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
    cout<<f(1, c, a);
}