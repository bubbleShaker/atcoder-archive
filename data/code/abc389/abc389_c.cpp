#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int q;
  cin>>q;
  vector<ll> sna;
  sna.push_back(0);//最初のヘビの頭の座標
  ll x=0;//抜けたヘビの数
  ll rsw=0;//抜けたヘビの長さの累積和
  while(q--){
    int t;
    cin>>t;
    if(t==1){
      ll l;
      cin>>l;
      int n=sna.size();
      sna.push_back(sna[n-1]+l);//次のヘビの頭の座標
    }
    if(t==2){
      rsw+=sna[x+1]-sna[x];//抜けたヘビの長さを加算
      x++;
    }
    if(t==3){
      ll k;
      cin>>k;
      cout<<sna[x+k-1]-rsw<<endl;
    }
  }
  return 0;
}