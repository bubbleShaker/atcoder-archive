#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,n;cin>>h>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        h-=a;
    }
    if(h<=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}