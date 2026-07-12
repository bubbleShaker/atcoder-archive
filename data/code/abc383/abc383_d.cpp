#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//引用:https://algo-method.com/descriptions/64

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(ll N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (ll p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (ll q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main(){
  ll n;
  cin>>n;
  const ll MAX=2e6+10;
  vector<bool> isprime = Eratosthenes(MAX);
  vector<ll> p_vec;
  for(ll i=2;i<MAX;i++){
    if(isprime[i]){
      p_vec.push_back(i);
    }
  }
  int m=p_vec.size();
  ll ans=0;
  //step1
  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      ll p=p_vec[i];
      ll q=p_vec[j];
      if(p*q<=sqrt((double)n)){
        ans++;
      }else{
        break;
      }
    }
  }
  //step2
  for(int i=0;i<m;i++){
    ll p=p_vec[i];
    if(p*p*p*p*p*p*p*p<=n){
      ans++;
    }else{
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}