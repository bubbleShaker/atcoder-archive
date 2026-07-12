#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    vector<long long> tokutenVec(n+1);
    map<long long,int> mp;
    set<long long> st;
    st.insert(0);
    mp[0]=n;
    for(int i=1;i<=t;i++){
        int a;
        long long b;
        cin>>a>>b;
        long long& tokuten=tokutenVec[a];
        if(mp[tokuten]==1){
            st.erase(tokuten);
            mp[tokuten]--;
        }else if(mp[tokuten]>=2){
            mp[tokuten]--;
        }
        tokuten+=b;
        mp[tokuten]++;
        if(mp[tokuten]==1){
            st.insert(tokuten);
        }
        cout<<st.size()<<endl;
    }
    return 0;
}