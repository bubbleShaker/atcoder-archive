#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int x=0;
    int maxX=0;
    for(int i=0;i<n;i++){
        if(s[i]=='I')x++;
        else if(s[i]=='D')x--;
        maxX=max(maxX,x);
    }
    cout<<maxX<<endl;
    return 0;
}