#include<iostream>
using namespace std;
int f(int ind, int cap, int buy, int arr[], int n){
    if(ind==n) return 0;
    if(cap==0) return 0;
    int profit = 0;
    if(buy)
        profit = max(-arr[ind]+f(ind+1, cap, 0, arr, n), f(ind+1, cap, 1, arr, n));
    else
        profit = max(arr[ind]+f(ind+1, cap-1, 1, arr, n), f(ind+1, cap, 0, arr, n));
    return profit;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(0, 2, 1, arr, n);
}