#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> a(n+m);
  for(int i=0;i<n;i++){
    cin>>a[i].first;
    a[i].second=0;
  }
  for(int i=n;i<n+m;i++){
    cin>>a[i].first;
    a[i].second=1;
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n+m-1;i++){
    if(a[i].second==a[i+1].second&&a[i].second==0){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}