#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
  int n;
  cin>>n;
  vector<int> p(n+1);
  for(int i=1;i<=n;i++){
    cin>>p[i];
  }
  fenwick_tree<int> fw(n+10);
  for(int i=1;i<=n;i++){
    fw.add(i,1);
  }
  vector<int> ans(n+1);
  for(int i=n;i>=1;i--){
    int ok=n;
    int ng=0;
    while(abs(ok-ng)>1){
      int mid=(ok+ng)/2;
      if(fw.sum(1,mid+1)>=p[i]){
        ok=mid;
      }else{
        ng=mid;
      }
    }
    fw.add(ok,-1);
    ans[ok]=i;
  }
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
  return 0;
}