#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin>>a>>b;
  set<int> st;
  st.insert(a);
  st.insert(b);
  if(a!=b){
    for(int i=1;i<=3;i++){
      if(!st.count(i)){
        cout<<i<<endl;
        return 0;
      }
    }
  }else{
    cout<<-1<<endl;
  }
  return 0;
}