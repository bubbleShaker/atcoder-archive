#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin>>q;
  set<int> st;
  while(q--){
    int type,x;
    cin>>type>>x;
    if(type==1){
      st.insert(x);
    }else if(type==2){
      st.erase(x);
    }else if(type==3){
      cout<<(st.size()!=0&&(st.lower_bound(x)!=st.end())?*st.lower_bound(x):-1)<<endl;
    }
  }
  return 0;
}