#include <bits/stdc++.h>
using namespace std;

int main(){
  set<int> st;
  map<int,int> mp;
  for(int i=0;i<4;i++){
    int a;
    cin>>a;
    st.insert(a);
    mp[a]++;
  }
  if(st.size()==2){
    int a=*st.begin();
    int b=*(st.rbegin());
    if(mp[a]==3&&mp[b]==1){
      cout<<"Yes"<<endl;
      return 0;
    }
    if(mp[a]==2&&mp[b]==2){
      cout<<"Yes"<<endl;
      return 0;
    }
    if(mp[b]==3&&mp[a]==1){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}