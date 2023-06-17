#include<iostream>
using namespace std;
int f(int ind, int buy, int n, int arr[]){
    if(ind>=n) return 0;
    if(buy)
        return max(-arr[ind]+f(ind+1, 0, n, arr), f(ind+1, 1, n, arr));
    else
        return max(arr[ind]+f(ind+2, 1, n, arr), f(ind+1, 0, n, arr));
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<f(0, 1, n, arr);
}