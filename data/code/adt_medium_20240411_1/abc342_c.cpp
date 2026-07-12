#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    int q;
    cin>>q;
    string to,from;
    from=to="abcdefghijklmnopqrstuvwxyz";
    while(q--){
        char c,d;
        cin>>c>>d;
        for(int i=0;i<26;i++){
            if(to[i]==c){
                to[i]=d;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if(from[j]==s[i]){
                s[i]=to[j];
                break;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}