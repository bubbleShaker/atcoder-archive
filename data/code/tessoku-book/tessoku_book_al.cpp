#include <bits/stdc++.h>
using namespace std;
int main(){
  int d,n;
  cin>>d>>n;
  vector<int> v(d+1,24);
  for(int i=0;i<n;i++){
    int l,r,h;
    cin>>l>>r>>h;
    for(int j=l;j<=r;j++){
      v[j]=min(v[j],h);
    }
  }
  int ans=0;
  for(int i=1;i<=d;i++){
    ans+=v[i];
  }
  cout<<ans<<endl;
  return 0;
}