#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> H(n+1);
  for(int i=1;i<=n;i++)cin>>H[i];
  vector<vector<int>> h_idx(3010);
  for(int i=1;i<=n;i++){
    h_idx[H[i]].push_back(i);//高さごとのidxを記録する
  }
  int ans=1;
  for(int h=1;h<=3000;h++){
    int siz=h_idx[h].size();
    if(siz==0)continue;
    for(int si=0;si<siz;si++){
      int ti=si;
      int cnt=1;
      int dif=1;
      while(dif<=3000){
        auto itr=lower_bound(h_idx[h].begin(),h_idx[h].end(),h_idx[h][si]+dif);
        if(itr!=h_idx[h].end()&&*itr==h_idx[h][si]+dif){//条件を満たす要素がh_idx[h]に存在するなら調べ続ける
          int idx=itr-h_idx[h].begin();
          si=idx;
          cnt++;
          ans=max(ans,cnt);//答えの更新
        }else{
          dif++;
          si=ti;
          cnt=1;
        }
      }
      si=ti;
    }
  }
  cout<<ans<<endl;
  return 0;
}