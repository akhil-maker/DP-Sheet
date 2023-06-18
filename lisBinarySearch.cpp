#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int lis(int n, int arr[]){
    vector<int> t;
    t.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i]>t.back())
            t.push_back(arr[i]);
        else{
            int ind = lower_bound(t.begin(), t.end(), arr[i])-t.begin();
            t[ind] = arr[i];
        }
    }
    return t.size();
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<lis(n, arr);
}