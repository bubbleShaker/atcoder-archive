#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;

int main(){
  const int MAX=5*(int)1e5;
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  fenwick_tree<int> fw(MAX+1);
  //何個足されるか
  for(int i=0;i<n;i++){
    a[i]+=ll(fw.sum(i,MAX+1));
    ll add=min(a[i]+i,5*(int)1e5);
    fw.add(add,1);
  }
  for(int i=0;i<n;i++){
    a[i]-=n-(i+1);
    if(a[i]<0)a[i]=0;
    cout<<a[i]<<" ";
  }cout<<endl;
  return 0;
}