#include <bits/stdc++.h>
using namespace std;
using P=pair<int,string>;

int main(){
  int n;
  cin>>n;
  vector<P> vec_s;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    vec_s.push_back(make_pair((int)s.size(),s));
  }
  sort(vec_s.begin(),vec_s.end());
  string ans;
  for(int i=0;i<n;i++){
    ans+=vec_s[i].second;
  }
  cout<<ans<<endl;
  return 0;
}