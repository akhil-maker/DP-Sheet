#include<iostream>
using namespace std;
int f(int ind, int trans, int arr[], int n, int k){
    if(ind==n || trans==2*k) return 0;
    if(trans%2==0)
        return max(-arr[ind]+f(ind+1, trans+1, arr, n, k), f(ind+1, trans, arr, n, k));
    else
        return max(arr[ind]+f(ind+1, trans+1, arr, n, k), f(ind+1, trans, arr, n, k));
}
int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(0, 0, arr, n, k);
}