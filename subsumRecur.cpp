#include<iostream>
using namespace std;
bool f(int a[], int n, int ind, int t){
    if(t==0) return true;
    if(ind==0) return (t==a[ind]);
    bool take = (t>=a[ind])?f(a, n, ind-1, t-a[ind]):false;
    bool nottake = f(a, n, ind-1, t);
    return take || nottake;
}
int main(){
    int n, t;
    cin>>n>>t;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(a, n, n-1, t);
}