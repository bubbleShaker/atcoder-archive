#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d,k;
  cin>>n>>d>>k;
  vector<int> l(d+1),r(d+1);
  for(int i=1;i<=d;i++){
    cin>>l[i]>>r[i];
  }
  vector<int> s(k+1),t(k+1);
  vector<bool> plus(k+1);
  vector<int> now(k+1);
  for(int i=1;i<=k;i++){
    cin>>s[i]>>t[i];
    if(t[i]-s[i]>0)plus[i]=true;
    else plus[i]=false;
    now[i]=s[i];
  }
  vector<int> ans(k+1);
  for(int i=1;i<=d;i++){
    for(int j=1;j<=k;j++){
      if(l[i]<=now[j]&&now[j]<=r[i]&&now[j]!=t[j]){
        if(plus[j]){
          if(t[j]<=r[i]){
            now[j]=t[j];
            ans[j]=i;
          }else{
            now[j]=r[i];
          }
        }else{
          if(t[j]>=l[i]){
            now[j]=t[j];
            ans[j]=i;
          }else{
            now[j]=l[i];
          }
        }
      }
    }
  }
  for(int i=1;i<=k;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}