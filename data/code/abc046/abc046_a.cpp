#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> st;
    for(int i=0;i<3;i++){
        int a;cin>>a;
        st.insert(a);
    }
    cout<<st.size()<<endl;
    return 0;
}