#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> h(n);
  for(int i=0;i<n;i++) cin>>h[i];
  int rem=m;
  int ans=0;
  for(int i=0;i<n;i++){
    if(rem>=h[i]){
      rem-=h[i];
      ans++;
    }else{
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}