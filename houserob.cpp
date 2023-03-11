#include<iostream>
#include<vector>
using namespace std;
int f(vector<int> a){
    int n = a.size();
    int p = 0, c = a[0];
    for(int i=1; i<n; i++){
        int take = a[i];
        if(i>1)
            take += p;
        int nottake = c;
        int t = max(take, nottake);
        c = t;
        p = c;
    }
    return c;
}
int main(){
    vector<int> a = {2, 3, 4};
    vector<int> t1, t2;
    for(int i=0; i<a.size(); i++){
        if(i!=0)
            t2.push_back(a[i]);
        else if(i!=a.size()-1)
            t1.push_back(a[i]);
    }
    int x = f(t1), y = f(t2);
    cout<<max(x, y);
}