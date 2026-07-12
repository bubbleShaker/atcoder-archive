#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.size();
    int val=n-2;
    cout<<s[0]+to_string(val)+s[n-1]<<endl;
    return 0;
}