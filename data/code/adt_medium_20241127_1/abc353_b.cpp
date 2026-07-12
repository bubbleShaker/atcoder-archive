#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  int now=k;
  int ans=0;
  for(int i=0;i<n;i++){
    if(now-a[i]<0){
      ans++;
      now=k-a[i];
    }else{
      now-=a[i];
    }
  }
  ans++;
  cout<<ans<<endl;
  return 0;
}