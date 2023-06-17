#include<iostream>
using namespace std;
int f(int ind, int tar, int a[]){
    if(tar==0) return 0;
    if(ind==0){
        if(tar%a[ind]==0) return tar/a[ind];
        return 1e9;
    }
    int take = 1e9;
    if(a[ind]<=tar)
        take = f(ind, tar-a[ind], a)+1;
    int nottake = f(ind-1, tar, a);
    return min(take, nottake);
}
int main(){
    int n, t;
    cin>>n>>t;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(n-1, t, a);
}