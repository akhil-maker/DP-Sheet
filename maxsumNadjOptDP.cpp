#include<iostream>
using namespace std;
int f(int n, int a[]){
    int p = 0, c = a[0];
    for(int i=1; i<n; i++){
        int take = a[i];
        if(i>1)
            take += p;
        int nottake = c;
        int t = max(take, nottake);
        p = c;
        c = t;
    }
    return c;
}
int main(){
    int a[] = {2, 3, 4};
    cout<<f(3, a);
}