#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,m;
  cin>>n>>k>>m;
  vector<pair<long long,int>> v_c(n);
  for(int i=0;i<n;i++){
    cin>>v_c[i].second>>v_c[i].first;
  }
  sort(v_c.begin(), v_c.end(),[](pair<long long,int> a, pair<long long, int> b){
    return a.first > b.first;
  });
  set<int> checked_c;
  set<int> checked_c_index;
  long long ans=0;
  int added_color_count=0;
  for(int i=0;i<n;i++){
    if(!checked_c.count(v_c[i].second)){
      checked_c.insert(v_c[i].second);
      checked_c_index.insert(i);
      added_color_count++;
    }
    if(added_color_count==m){
      break;
    }
  }
  cerr<<checked_c_index.size()<<endl;
  for(int index : checked_c_index){
    ans+=v_c[index].first;
  }
  cerr<<ans<<endl;
  long long remain=k-m;
  cerr<<remain<<endl;
  for(int i=0;remain>0 && i<n;i++){
    if(checked_c_index.count(i)){
      continue;
    }
    ans+=v_c[i].first;
    remain--;
  }
  cout<<ans<<endl;
}
