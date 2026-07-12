#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;

int main(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  bool making=false;
  int l=-1,r=-1;
  vector<pair<int,int>> ps;
  for(int i=0;i<n;i++){
    if(s[i]=='1'){
      if(!making){
        l=i;
      }
      making=true;
    }
    if(s[i]=='0'){
      if(l==-1) continue;
      if(!making) continue;
      r=i-1;
      ps.push_back(make_pair(l,r));
      making=false;
    }
  }
  if(s[n-1]=='1'){
    ps.push_back(make_pair(l,n-1));
  }
  string ans=s;
  P p1=ps[k-1];
  for(int i=p1.first;i<=p1.second;i++){
    ans[i]='0';
  }
  int len=p1.second-p1.first+1;
  P p2=ps[k-2];
  int pr=p2.second;
  for(int i=p2.second+1;i<=p2.second+len;i++){
    ans[i]='1';
  }
  cout<<ans<<endl;
  return 0;
}