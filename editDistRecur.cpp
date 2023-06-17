#include<iostream>
using namespace std;
int f(int i, int j, string s, string t){
    if(j<0) return i+1;
    if(i<0) return j+1;
    if(s[i]==t[j])
        return 1 + f(i-1, j-1, s, t);
    return min(f(i-1, j-1, s, t), min(f(i-1, j, s, t), f(i, j-1, s, t)));
}
int main(){
    string s, t;
    cin>>s>>t;
    cout<<f(s.length()-1, t.length()-1, s, t);
}