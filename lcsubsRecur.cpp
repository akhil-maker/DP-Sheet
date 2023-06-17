#include<iostream>
using namespace std;
int f(int ind1, int ind2, string s, string t){
    if(ind1<0 || ind2<0)
        return 0;
    int take = 0;
    if(s[ind1]==t[ind2])
        take = 1 + f(ind1-1, ind2-1, s, t);
    int nottake = max(f(ind1-1, ind2, s, t), f(ind1, ind2-1, s, t));
    return max(take, nottake);
}
int main(){
    string s, t;
    cin>>s>>t;
    cout<<f(s.length()-1, t.length()-1, s, t);
}