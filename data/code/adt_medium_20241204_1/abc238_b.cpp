#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  vector<int> kir={0};//0~359で切れ込みを記録
  for(int i=0;i<n;i++){
    int las=kir[kir.size()-1];
    kir.push_back((las+a[i])%360);
  }
  vector<bool> fla(360);
  for(int i=0;i<kir.size();i++){
    fla[kir[i]]=true;
  }
  int ans=0;
  int now=0;
  for(int i=0;i<=360;i++){
    if(i==360){
      ans=max(ans,now+1);
      break;
    }
    if(fla[i]){
      ans=max(ans,now+1);
      now=0;
    }else{
      now++;
    }
  }
  cout<<ans<<endl;
  return 0;
}