#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  while(q--){
    int x;
    cin>>x;
    int idx=lower_bound(a.begin(),a.end(),x)-a.begin();
    cout<<n-idx<<endl;
  }
  return 0;
}