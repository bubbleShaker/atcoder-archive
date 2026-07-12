#include <bits/stdc++.h>
using namespace std;
int main(){
  const int INF=2e9;
  int q;
  cin>>q;
  set<int> st;
  st.insert(-INF);
  st.insert(INF);
  while(q--){
    int type,x;
    cin>>type>>x;
    if(type==1){
      st.insert(x);
    }else if(type==2){
      auto itr=st.lower_bound(x);
      if(st.size()>2){
        cout<<min({abs(*(--itr)-x),abs(*(++itr)-x),abs(*(--itr)-x)})<<endl;
      }else{
        cout<<-1<<endl;
      }
    }
  }
  return 0;
}