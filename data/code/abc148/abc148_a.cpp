#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> st;
    for(int i=1;i<=3;i++){
        st.insert(i);
    }
    int a,b;cin>>a>>b;
    st.erase(a);
    st.erase(b);
    for(int x:st){
        cout<<x<<endl;
    }
    return 0;
}