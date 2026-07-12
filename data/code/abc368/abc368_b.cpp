#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.rbegin(),a.rend());
  int cnt=0;
  for(int i=0;i<n;i++){
    if(a[i]>0){
      cnt++;
    }
  }
  int ans=0;
  while(cnt>1){
    a[0]--;
    a[1]--;
    ans++;
    sort(a.rbegin(),a.rend());
    cnt=0;
    for(int i=0;i<n;i++){
      if(a[i]>0){
        cnt++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}