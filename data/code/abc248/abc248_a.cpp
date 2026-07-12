#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.size();
    set<int> st;
    for(int i=0;i<=9;i++){
        st.insert(i);
    }
    for(int i=0;i<n;i++){
        st.erase(s[i]-'0');
    }
    for(int val:st){
        cout<<val<<endl;
        return 0;
    }
    return 0;
}