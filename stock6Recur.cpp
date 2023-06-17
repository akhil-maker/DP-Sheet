#include<iostream>
using namespace std;
int f(int ind, int buy, int arr[], int n, int fee){
    if(ind==n)
        return 0;
    if(buy)
        return max(-arr[ind]+f(ind+1, 0, arr, n, fee), f(ind+1, buy, arr, n, fee));
    else
        return max(arr[ind]+f(ind+1, 1, arr, n, fee)-fee, f(ind+1, 0, arr, n, fee));
}
int main(){
    int n, fee;
    cin>>n>>fee;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(0, 1, arr, n, fee);
}