#include <bits/stdc++.h>
using namespace std;

bool f(pair<int,int> a,pair<int,int> b){
  if(a.first==b.first){
    return a.second<b.second;
  }else{
    return a.first>b.first;
  }
}

int main(){
  int n,x,y,z;
  cin>>n>>x>>y>>z;
  vector<pair<int,int>> a(n),b(n),ab(n);
  for(int i=0;i<n;i++){
    cin>>a[i].first;
    a[i].second=i;
  }
  for(int i=0;i<n;i++){
    cin>>b[i].first;
    b[i].second=i;
    ab[i].first=a[i].first+b[i].first;
    ab[i].second=i;
  }
  sort(a.begin(),a.end(),f);
  sort(b.begin(),b.end(),f);
  sort(ab.begin(),ab.end(),f);
  set<int> x_set,y_set,z_set;
  vector<bool> seen(n);
  for(int i=0;i<n;i++){
    if(x_set.size()==x){
      break;
    }
    x_set.insert(a[i].second);
    seen[a[i].second]=true;
  }
  for(int i=0;i<n;i++){
    if(y_set.size()==y){
      break;
    }
    if(!seen[b[i].second]){
      y_set.insert(b[i].second);
      seen[b[i].second]=true;
    }
  }
  for(int i=0;i<n;i++){
    if(z_set.size()==z){
      break;
    }
    if(!seen[ab[i].second]){
      z_set.insert(ab[i].second);
      seen[ab[i].second]=true;
    }
  }
  for(int i=0;i<n;i++){
    if(seen[i]){
      cout<<i+1<<endl;
    }
  }
  return 0;
}