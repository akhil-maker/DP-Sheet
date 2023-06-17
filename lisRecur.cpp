#include<iostream>
using namespace std;
int f(int ind, int prev, int arr[], int n){
    if(ind==n)
        return 0;
    int nottake = f(ind+1, prev, arr, n);
    int take = 0;
    if(prev==-1 || arr[ind]>arr[prev])
        take = 1+f(ind+1, ind, arr, n);
    return max(take, nottake);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(0, -1, arr, n);
}