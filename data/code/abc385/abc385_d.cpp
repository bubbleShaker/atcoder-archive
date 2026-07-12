#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,m;
  ll sx,sy;
  cin>>n>>m>>sx>>sy;
  vector<ll> x(n),y(n);
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  vector<char> d(m);
  vector<ll> c(m);
  for(int i=0;i<m;i++){
    cin>>d[i]>>c[i];
  }
  map<ll,set<ll>> x_sety_mp;//あるx座標にある家のy座標の集合
  map<ll,set<ll>> y_setx_mp;//あるy座標にある家のx座標の集合
  for(int i=0;i<n;i++){
    x_sety_mp[x[i]].insert(y[i]);
    y_setx_mp[y[i]].insert(x[i]);
  }
  ll now_x=sx;
  ll now_y=sy;
  ll ans=0;//通過した家の数
  
  for(int i=0;i<m;i++){
    // cout<<"i is "<<i<<endl;
    // cout<<"now_x is "<<now_x<<endl;
    // cout<<"now_y is "<<now_y<<endl;
    // cout<<"ans is "<<ans<<endl;
    if(d[i]=='U'){
      set<ll>& st=x_sety_mp[now_x];
      auto itr=st.lower_bound(now_y);//現在地点よりも大きい最小の家の座標
      vector<ll> era_vec;//消す家の情報
      while(itr!=st.end()&&*itr<=now_y+c[i]){//消せる家がある限り見ていく
        //消す家のx座標、y座標
        ll era_x=now_x;
        ll era_y=*itr;
        ans++;
        era_vec.push_back(*itr);
        //もう一方の軸についても情報を更新
        set<ll>& s_set=y_setx_mp[era_y];
        if(s_set.count(era_x)){//多分確定で存在するが…
          s_set.erase(era_x);
        }
        itr++;//次の家を見る
      }
      //家の削除
      for(auto era:era_vec){
        st.erase(era);
      }
      
      //座標の更新
      now_y+=c[i];
    }
    
    if(d[i]=='D'){
      set<ll>& st=x_sety_mp[now_x];
      auto itr=st.lower_bound(now_y);//現在地点よりも小さい最大の家の座標
      vector<ll> era_vec;//消す家の情報
      if(st.size()>=0&&itr!=st.begin()){//遷移できる家があるならする
        itr--;
      }
      while(itr!=st.end()&&*itr>=now_y-c[i]&&now_y>*itr){//消せる家がある限り見ていく
        //消す家のx座標、y座標
        ll era_x=now_x;
        ll era_y=*itr;
        ans++;
        bool is_begin=(itr==st.begin());
        era_vec.push_back(*itr);
        //もう一方の軸についても情報を更新
        set<ll>& s_set=y_setx_mp[era_y];
        if(s_set.count(era_x)){//多分確定で存在するが…
          s_set.erase(era_x);
        }
        if(is_begin){//今見ているのが最初の要素なら終了
          break;
        }else{
          itr--;//次の家を見る
        }
      }
      //家の削除
      for(auto era:era_vec){
        st.erase(era);
      }
      
      //座標の更新
      now_y-=c[i];
    }
    
    if(d[i]=='L'){
      set<ll>& st=y_setx_mp[now_y];
      auto itr=st.lower_bound(now_x);//現在地点よりも小さい最大の家の座標
      vector<ll> era_vec;//消す家の情報
      if(st.size()>=0&&itr!=st.begin()){//遷移できる家があるならする
        itr--;
      }
      while(itr!=st.end()&&*itr>=now_x-c[i]&&now_x>*itr){//消せる家がある限り見ていく
        //消す家のx座標、y座標
        ll era_x=*itr;
        ll era_y=now_y;
        ans++;
        bool is_begin=(itr==st.begin());
        era_vec.push_back(*itr);
        //もう一方の軸についても情報を更新
        set<ll>& s_set=x_sety_mp[era_x];
        if(s_set.count(era_y)){//多分確定で存在するが…
          s_set.erase(era_y);
        }
        if(is_begin){//今見ているのが最初の要素なら終了
          break;
        }else{
          itr--;//次の家を見る
        }
      }
      //家の削除
      for(auto era:era_vec){
        st.erase(era);
      }
      
      //座標の更新
      now_x-=c[i];
    }
    
    if(d[i]=='R'){
      set<ll>& st=y_setx_mp[now_y];
      auto itr=st.lower_bound(now_x);//現在地点よりも大きい最小の家の座標
      vector<ll> era_vec;//消す家の情報
      while(itr!=st.end()&&*itr<=now_x+c[i]){//消せる家がある限り見ていく
        //消す家のx座標、y座標
        ll era_x=*itr;
        ll era_y=now_y;
        ans++;
        era_vec.push_back(*itr);
        //もう一方の軸についても情報を更新
        set<ll>& s_set=x_sety_mp[era_x];
        if(s_set.count(era_y)){//多分確定で存在するが…
          s_set.erase(era_y);
        }
        itr++;//次の家を見る
      }
      //家の削除
      for(auto era:era_vec){
        st.erase(era);
      }
      
      //座標の更新
      now_x+=c[i];
    }
  }
  cout<<now_x<<" "<<now_y<<" "<<ans<<endl;
  return 0;
}