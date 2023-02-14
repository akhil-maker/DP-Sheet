#include<iostream>
using namespace std;
int f(int n, int a[]){
    if(n==0)
        return 0;
    int left = f(n-1, a) + abs(a[n]-a[n-1]);
    int right = INT_MAX;
    if(n>1)
        right = f(n-2, a) + abs(a[n]-a[n-2]);
    return min(left, right);
}
int main(){
    int a[] = {30, 10, 60, 10, 60, 50};
    cout<<f(5, a);
}