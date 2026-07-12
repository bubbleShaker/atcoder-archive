#include <bits/stdc++.h>
using namespace std;
int main(){
  //数字の大きい硬貨を優先的に使い続ける
  vector<int> cnt(6);
  for(int i=0;i<6;i++){
    cin>>cnt[i];
  }
  reverse(cnt.begin(),cnt.end());
  map<int,int> mp;//インデックスと硬貨の辞書
  mp[0]=500;
  mp[1]=100;
  mp[2]=50;
  mp[3]=10;
  mp[4]=5;
  mp[5]=1;
  int n;
  cin>>n;
  vector<int> x(n);
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<6;j++){//500円硬貨から見ていく
      if(cnt[j]<=0){
        continue;
      }
      int dec=x[i]/mp[j];//使う硬貨の数
      dec=min(dec,cnt[j]);//chmin(今残っている枚数,使いたい枚数)で硬貨を使いすぎないようにする
      x[i]-=dec*mp[j];
      cnt[j]-=dec;
    }
  }
  bool isOk=all_of(x.begin(),x.end(),[&](int val){ return val==0; });
  cout<<((isOk)?"Yes":"No")<<'\n';
  return 0;
}