#include<iostream>
using namespace std;
int f(int ind, int t, int a[]){
    if(t==0) return 0;
    if(ind==0) return t*a[ind];
    int nottake = f(ind-1, t, a);
    int rodlen = ind+1, take = 0;
    if(rodlen<=t) take = a[ind] + f(ind, t-rodlen, a);
    return max(take, nottake);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(n-1, n, a);
}