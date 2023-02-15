#include<iostream>
using namespace std;
int f(int ind, int a[]){
    if(ind<0)
        return 0;
    if(ind==0)
        return a[0];
    int take = f(ind-2, a) + a[ind];
    int nottake = f(ind-1, a);
    return max(take, nottake);
}
int main(){
    int a[] = {2, 3, 4};
    cout<<f(2, a);
}