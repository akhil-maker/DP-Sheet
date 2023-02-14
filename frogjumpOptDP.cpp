#include<iostream>
#include<vector>
using namespace std;
int f(int n, int a[]){
    if(n==0)
        return 0;
    int p = 0, c=0;
    for(int i=1; i<=n; i++){
        int left = c + abs(a[i]-a[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = p + abs(a[i]-a[i-2]);
        int t = min(left, right);
        p = c;
        c = t;
    }
    return c;
}
int main(){
    int a[] = {30, 10, 60, 10, 60, 50};
    cout<<f(5, a);
}