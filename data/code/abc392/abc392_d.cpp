#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> k(n);
  vector<vector<int>> a(n);
  vector<unordered_set<int>> st(n);
  vector<unordered_map<int,int>> mp(n);
  for(int i=0;i<n;i++){
    cin>>k[i];
    for(int j=0;j<k[i];j++){
      int ta;
      cin>>ta;
      a[i].push_back(ta);
      st[i].insert(ta);
      mp[i][ta]++;
    }
  }
  double ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      double pro=0;
      for(auto val:st[i]){
        pro+=((double)mp[i][val]*mp[j][val])/((double)k[i]*k[j]);
      }
      ans=max(ans,pro);
    }
  }
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
  return 0;
}