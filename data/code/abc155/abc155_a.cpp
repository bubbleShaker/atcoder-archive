#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a(3);
    set<int> st;
    for(int i=0;i<3;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    if(st.size()==2){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}