#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  vector<int> cnt(m+1);
  for(int i=0;i<n;i++){
    cin>>a[i];
    cnt[a[i]]++;
  }
  for(int i=1;i<=m;i++){
    if(cnt[i]==0){
      cout<<0<<endl;
      return 0;
    }
  }
  for(int i=n-1;i>=0;i--){
    cnt[a[i]]--;
    if(cnt[a[i]]==0){
      cout<<n-i<<endl;
      return 0;
    }
  }
  return 0;
}