#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,l,r;
  cin>>n>>l>>r;
  vector<int> ans;
  int val=r;
  for(int i=1;i<=n;i++){
    if(l<=i&&i<=r){
      ans.push_back(val);
      val--;
    }else{
      ans.push_back(i);
    }
  }
  for(auto num:ans){
    cout<<num<<' ';
  }
  return 0;
}