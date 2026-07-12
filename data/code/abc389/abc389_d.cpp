#include <bits/stdc++.h>
using namespace std;
using ll=long long;

double inc(double n){
  return n+0.5;
}

double dec(double n){
  return n-0.5;
}

bool is_ok(ll x,ll y,ll r){
  double dx=x;
  double dy=y;
  double dr=r;
  if(inc(dx)*inc(dx)+inc(dy)*inc(dy)>dr*dr)return false;
  if(inc(dx)*inc(dx)+dec(dy)*dec(dy)>dr*dr)return false;
  if(dec(dx)*dec(dx)+inc(dy)*inc(dy)>dr*dr)return false;
  if(dec(dx)*dec(dx)+dec(dy)*dec(dy)>dr*dr)return false;
  return true;
}

int main(){
  ll r;
  cin>>r;
  ll ans=1;//真ん中
  ans+=(r-1)*4;//x,y軸の増加分
  for(ll x=1;x<=r-1;x++){
    ll ng=r;//rにはなりえないので
    ll ok=0;//最悪
    while(abs(ok-ng)>1){
      ll mid=(ok+ng)/2;
      if(is_ok(x,mid,r)){
        ok=mid;
      }else{
        ng=mid;
      }
    }
    ans+=ok*4;
  }
  cout<<ans<<endl;
  return 0;
}