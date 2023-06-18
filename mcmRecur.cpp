#include<iostream>
using namespace std;
int f(int i, int j, int a[]){
    if(i==j) return 0;
    int step = 0, mn = 1e9;
    for(int k=i; k<=j-1; k++){
        step += (a[i-1]*a[k]*a[j]) + f(i, k, a) + f(k+1, j, a);
        mn = min(mn, step);
    }
    return mn;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(1, n-1, a);
}