#include <bits/stdc++.h>
using namespace std;
int main(){
    double h,w,n;cin>>h>>w>>n;
    double ma=max(h,w);
    cout<<(int)ceil(n/ma)<<endl;
    return 0;
}