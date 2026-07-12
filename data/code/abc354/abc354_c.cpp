#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> ac(n);
  map<int,int> aMap;
  for(int i=0;i<n;i++){
    int a,c;
    cin>>a>>c;
    ac[i]={a,c};
    aMap[a]=i;
  }
  sort(ac.rbegin(),ac.rend());
  int maxC=ac[0].second;
  vector<int> ans;
  ans.push_back(aMap[ac[0].first]+1);
  for(int i=1;i<n;i++){
    if(ac[i].second<maxC){
      maxC=ac[i].second;
      ans.push_back(aMap[ac[i].first]+1);
    }
  }
  sort(ans.begin(),ans.end());
  int m=ans.size();
  cout<<m<<endl;
  for(int i=0;i<m;i++){
    cout<<ans[i]<<" \n"[i+1==m];
  }
  return 0;
}