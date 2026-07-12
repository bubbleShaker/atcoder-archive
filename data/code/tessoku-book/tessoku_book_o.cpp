#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    set<int> st;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    int ind=1;
    for(int val:st){
        mp[val]=ind;
        ind++;
    }
    for(int i=0;i<n;i++){
        cout<<mp[a[i]]<<" \n"[i+1==n];
    }
    return 0;
}