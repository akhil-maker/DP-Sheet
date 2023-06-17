#include<iostream>
using namespace std;
int f(int arr[], int n){
    int profit = 0, mn = arr[0];
    for(int i=0; i<n; i++){
        int cost = arr[i]-mn;
        profit = max(profit, cost);
        mn = min(mn, arr[i]);
    }
    return profit;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(arr, n);
}