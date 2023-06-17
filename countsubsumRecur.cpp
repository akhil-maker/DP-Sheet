#include<iostream>
using namespace std;
int f(int ind, int t, int a[]){
    if(t==0)
        return 1;
    if(ind==0)
        return (a[ind]==t);
    int take = (a[ind]<=t)?f(ind-1, t-a[ind], a):0;
    int nottake = f(ind-1, t, a);
    return take+nottake;
}
int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    cout<<n<<" "<<k<<" ok";
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<f(n-1, k, a);
}