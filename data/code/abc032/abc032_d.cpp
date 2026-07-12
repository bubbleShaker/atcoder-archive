#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  const ll INF=1e18;
  int n;
  ll W;
  cin>>n>>W;
  vector<ll> v(n+1),w(n+1);
  for(int i=1;i<=n;i++){
    cin>>v[i]>>w[i];
  }
  
  int joken;
  if(n<=30)joken=1;
  bool is_ok=true;
  for(int i=1;i<=n;i++){
    if(w[i]>1000){
      is_ok=false;
    }
  }
  if(is_ok)joken=2;
  is_ok=true;
  for(int i=1;i<=n;i++){
    if(v[i]>1000){
      is_ok=false;
    }
  }
  if(is_ok)joken=3;
  
  if(joken==1){//半分全列挙
    vector<pair<ll,ll>> A,B;
    for(int i=1;i<=n/2;i++){
      A.push_back(make_pair(w[i],v[i]));
      // cout<<i<<endl;
      // cout<<w[i]<<" "<<v[i]<<endl;
    }
    for(int i=n/2+1;i<=n;i++){
      B.push_back(make_pair(w[i],v[i]));
    }
    int A_n=A.size();
    int B_n=B.size();
    // cout<<A_n<<endl;
    // cout<<A[0].first<<endl;
    vector<pair<ll,ll>> A_blu;
    for(int bit=0;bit<(1<<A_n);bit++){
      ll sum_w=0,sum_v=0;
      bitset<20> bitset_a(bit);
      for(int i=0;i<A_n;i++){
        if(bitset_a[i]){//i番目の要素を使う
          auto [a_w,a_v]=A[i];
          // cout<<i<<endl;
          // cout<<a_w<<endl;
          // cout<<a_v<<endl;
          sum_w+=a_w;
          sum_v+=a_v;
        }
      }
      A_blu.push_back(make_pair(sum_w,sum_v));
    }
    sort(A_blu.begin(),A_blu.end());
    vector<pair<ll,ll>> S_a;
    ll A_max_v=0;
    for(int i=0;i<A_blu.size();i++){
      // cout<<A_blu[i].first<<" "<<A_blu[i].second<<endl;
      if(A_max_v<A_blu[i].second&&A_blu[i].first<=W){
        S_a.push_back(A_blu[i]);
        A_max_v=A_blu[i].second;
      }
    }
    // cout<<A_blu.size()<<endl;
    vector<pair<ll,ll>> S_b;
    for(int bit=0;bit<(1<<B_n);bit++){
      ll sum_w=0,sum_v=0;
      bitset<20> bitset_b(bit);
      for(int i=0;i<B_n;i++){
        if(bitset_b[i]){//i番目の要素を使う
          auto [b_w,b_v]=B[i];
          sum_w+=b_w;
          sum_v+=b_v;
        }
      }
      if(sum_w<=W){
        S_b.push_back(make_pair(sum_w,sum_v));
      }
    }
    ll ans=0;
    //二分探索を行う
    for(int i=0;i<S_b.size();i++){
      auto [b_w,b_v]=S_b[i];
      //S_aを分解
      vector<ll> S_a_w,S_a_v;
      for(int i=0;i<S_a.size();i++){
        auto [a_w,a_v]=S_a[i];
        S_a_w.push_back(a_w);
        S_a_v.push_back(a_v);
      }
      //二分探索
      int ind=lower_bound(S_a_w.begin(),S_a_w.end(),W-b_w)-S_a_w.begin();
      if(ind!=(int)S_a_w.size()&&S_a_w[ind]+b_w<=W){
        ans=max(ans,S_a_v[ind]+b_v);
      }else{
        if(ind==0){
          ans=max(ans,b_v);
        }else{
          ans=max(ans,S_a_v[ind-1]+b_v);
        }
      }
    }
    cout<<ans<<endl;
  }
  if(joken==2){//dp
    vector<vector<ll>> dp(n+1,vector<ll>(W+1,-INF));//dp[i][j]:i番目まで選んだ時、重さjのときの最大の価値
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
      dp[i]=dp[i-1];
      for(int j=0;j<=W;j++){
        if(j-w[i]>=0&&dp[i-1][j-w[i]]!=-INF){
          dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
      }
    }
    ll ans=0;
    for(int j=0;j<=W;j++){
      ans=max(ans,dp[n][j]);
    }
    cout<<ans<<endl;
  }
  if(joken==3){//dp
    const int MAX=200000;
    vector<vector<ll>> dp(n+1,vector<ll>(MAX+1,INF));//dp[i][j]:i番目まで選んだとき、価値jとなる最小の重さ
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
      dp[i]=dp[i-1];
      for(int j=0;j<=MAX;j++){
        if(j-v[i]>=0&&dp[i-1][j-v[i]]!=INF){
          dp[i][j]=min(dp[i][j],dp[i-1][j-v[i]]+w[i]);
        }
      }
    }
    ll ans=0;
    for(ll j=0;j<=MAX;j++){
      if(dp[n][j]<=W){
        ans=max(ans,j);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}