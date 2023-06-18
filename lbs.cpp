#include<iostream>
using namespace std;
int lbs(int n, int arr[]){
    int lis[n], lds[n];
    for(int i=0; i<n; i++)
        lis[i] = 1, lds[i] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i] = lis[j] + 1;
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[i]>arr[j] && lds[i]<lds[j]+1)
                lds[i] = lds[j] + 1;
        }
    }
    int mx = 1;
    for(int i=0; i<n; i++)
        mx = max(mx, lis[i]+lds[i]-1);
    return mx;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<lbs(n, arr);
}