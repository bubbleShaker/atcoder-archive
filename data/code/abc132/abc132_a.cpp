#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    set<char> st;
    map<char,int> mp;
    for(int i=0;i<4;i++){
        st.insert(s[i]);
        mp[s[i]]++;
    }
    for(auto [c,cnt]:mp){
        if(cnt!=2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}