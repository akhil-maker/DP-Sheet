#include<iostream>
using namespace std;
int f(int ind, int k, int a[]){
    if(ind==0) return 0;
    int msteps = INT_MAX;
    for(int j=1; j<=k; j++){
        int jump = INT_MAX;
        if(ind-j >= 0)
            jump = f(ind-j, k, a) + abs(a[ind]-a[ind-j]);
        msteps = min(msteps, jump);
    }
    return msteps;
}
int main(){
    int a[] = {30, 10, 60, 10, 60, 50};
    cout<<f(5, 3, a);
}