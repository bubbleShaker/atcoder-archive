#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  ll k,x;
  cin>>n>>k>>x;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a.rbegin(),a.rend());
  //最初にx円より高い商品に全てクーポンを使えるだけ使う
  for(int i=0;i<n;i++){
    ll use=a[i]/x;
    if(use>0){
      if(use<=k){ //使いたいだけ使えるなら使う
        a[i]-=use*x;
        k-=use;
      }else{ //途中でクーポンが無くなってしまうならあるだけ使う
        a[i]-=k*x;
        k=0;
        break;
      }
    }
  }
  if(k==0){ //クーポン全て使い切ったならば
    cout<<accumulate(a.begin(),a.end(),0LL)<<endl;
  }else{
    sort(a.rbegin(),a.rend());//降順にソート
    ll ans=0;
    for(int i=0;i<n;i++){
      if(k>0){
        k--;
      }else{
        ans+=a[i];
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}