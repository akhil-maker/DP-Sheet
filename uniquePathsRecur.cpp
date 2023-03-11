#include<iostream>
using namespace std;
int f(int x, int y){
    if(x<0 || y<0)
        return 0;
    if(x==0 && y==0)
        return 1;
    return f(x-1, y) + f(x, y-1);
}
int main(){
    int m, n;
    cin>>m>>n;
    cout<<f(m-1, n-1);
}