#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m);
  for(int i=0;i<m;i++){
    cin>>a[i];
  }
  map<int,int> mp;
  map<int,set<int>> smp;
  int ma=0;
  for(int i=0;i<m;i++){
    mp[a[i]]++;
    if(mp[a[i]]>1){
      smp[mp[a[i]]-1].erase(a[i]);
    }
    smp[mp[a[i]]].insert(a[i]);
    if(mp[a[i]]>=ma){
      ma=mp[a[i]];
    }
    int ret=*begin(smp[ma]);
    cout<<ret<<endl;
  }
  return 0;
}