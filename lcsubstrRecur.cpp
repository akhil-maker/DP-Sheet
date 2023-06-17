#include<iostream>
#include<vector>
using namespace std;
int mx = 0;
int f(int ind1, int ind2, string s, string t, int res){
    if(ind1<0 || ind2<0)
        return res;
    if(s[ind1]==t[ind2])
        res = f(ind1-1, ind2-1, s, t, res+1);
    return max(res, max(f(ind1-1, ind2, s, t, 0), f(ind1, ind2-1, s, t, 0)));
}
int main(){
    string s, t;
    cin>>s>>t;
    cout<<f(s.length()-1, t.length()-1, s, t, 0);
}