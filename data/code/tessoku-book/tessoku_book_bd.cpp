#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint=modint998244353;
class StringHash{
private:
  string s;
  //基数100でハッシュ値計算しているのでオーバーフロー対策でmintを使う
  vector<mint> t,H,B;
  void init(){
    //文字列sを数列tに変換
    int n=s.size();
    t.resize(n+1);
    for(int i=0;i<n;i++){
      t[i]=s[i]-'a'+1;
    }
    //ハッシュ値の前計算のコンポーネント
    H.resize(n+1);
    for(int i=1;i<=n;i++){
      H[i]=100*H[i-1]+t[i-1];
    }
    //ハッシュ値の前計算のコンポーネント2
    B.resize(n+1);
    B[0]=1;
    for(int i=1;i<=n;i++){
      B[i]=B[i-1]*100;
    }
  }
public:
  StringHash(string str):s(str){
    init();
  }
  //s[l,r]のハッシュ値の計算
  mint hash(int l,int r){
    return H[r]-B[r-l+1]*H[l-1];
  }
};
int main(){
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  // vector<int> t(n);
  // for(int i=0;i<n;i++){
  //   t[i]=s[i]-'a'+1;
  // }
  // vector<mint> H(n+1);
  // for(int i=1;i<=n;i++){
  //   H[i]=100*H[i-1]+t[i-1];
  // }
  // vector<mint> B(n+1);
  // B[0]=1;
  // for(int i=1;i<=n;i++){
  //   B[i]=B[i-1]*100;
  // }
  // auto hash=[&](int l,int r){
  //   return H[r]-B[r-l+1]*H[l-1];
  // };
  StringHash sHash(s);
  while(q--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(sHash.hash(a,b)==sHash.hash(c,d)){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}