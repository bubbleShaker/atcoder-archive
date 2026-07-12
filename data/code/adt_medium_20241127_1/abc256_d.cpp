#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;

int main(){
  int n;
  cin>>n;
  vector<int> imos((int)2e5+10);
  for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    imos[l]++;
    imos[r]--;
  }
  for(int i=0;i<=(int)2e5;i++){
    imos[i+1]+=imos[i];
  }
  bool connect=false;
  vector<P> ans;
  int l,r;
  for(int i=0;i<=(int)2e5;i++){
    if(imos[i]>=1){
      if(!connect){
        l=i;
        r=i;
        connect=true;
      }else{
        r++;
      }
    }else{
      if(connect){
        ans.emplace_back(l,r+1);
        connect=false;
      }
    }
  }
  for(auto [le,ri]:ans){
    cout<<le<<" "<<ri<<endl;
  }
  return 0;
}