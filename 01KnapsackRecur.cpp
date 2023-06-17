#include<iostream>
using namespace std;
int f(int ind, int W, int wt[], int val[]){
    if(W==0)
        return 0;
    if(ind==0){
        if(W>=wt[ind]) return val[ind];
        return 0;
    }
    int nottake = f(ind-1, W, wt, val);
    int take  = 0;
    if(wt[ind]<=W)
        take = f(ind-1, W-wt[ind], wt, val) + val[ind];
    return max(take, nottake);
}
int main(){
    int n, W;
    cin>>n>>W;
    int wt[n], val[n];
    for(int i=0; i<n; i++)
        cin>>wt[i];
    for(int i=0; i<n; i++)
        cin>>val[i];
    cout<<f(n-1, W, wt, val);
}