#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;cin>>a>>b;
    int s=a*b;
    s-=a;
    s-=b;
    s+=1;
    cout<<s<<endl;
    return 0;
}