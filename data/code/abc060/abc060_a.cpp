#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b,c;cin>>a>>b>>c;
    int aN=a.size(),bN=b.size(),cN=c.size();
    if(a[aN-1]==b[0]&&b[bN-1]==c[0])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}