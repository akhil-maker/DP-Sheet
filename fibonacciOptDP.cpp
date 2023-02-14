#include<iostream>
using namespace std;
int f(int n){
    if(n<=1)
        return n;
    int p = 0, c = 1;
    for(int i=2; i<=n; i++){
        int t = p+c;
        p = c;
        c = t;
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
}