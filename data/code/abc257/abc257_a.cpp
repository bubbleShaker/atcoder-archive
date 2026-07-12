#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin>>n>>x;
    vector<char> base;
    char c='A';
    for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            base.push_back(c+i);
        }
    }
    x--;
    cout<<base[x]<<endl;
    return 0;
}