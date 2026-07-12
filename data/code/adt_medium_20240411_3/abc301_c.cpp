#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    vector<int> sb(27),tb(27);
    for(int i=0;i<n;i++){
        if(s[i]=='@'){
            sb[26]++;
        }else{
            sb[s[i]-'a']++;
        }
        if(t[i]=='@'){
            tb[26]++;
        }else{
            tb[t[i]-'a']++;
        }
    }
    int cnts=0,cntt=0;
    set<int> st;
    st.insert('a'-'a');
    st.insert('t'-'a');
    st.insert('c'-'a');
    st.insert('o'-'a');
    st.insert('d'-'a');
    st.insert('e'-'a');
    st.insert('r'-'a');
    for(int i=0;i<26;i++){
        if(sb[i]!=tb[i]){
            if(st.count(i)==false){
                cout<<"No"<<endl;
                return 0;
            }
        }
        if(sb[i]>tb[i]){
            cntt+=(sb[i]-tb[i]);
        }else{
            cnts+=(tb[i]-sb[i]);
        }
    }
    if(cntt<=tb[26]&&cnts<=sb[26]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}