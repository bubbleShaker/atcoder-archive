#include <bits/stdc++.h>
using namespace std;
template<typename T>
class SegTree{
  private:
  //配列の要素数
  int n;
  //木のノード
  vector<T> node;
  //ノード1の要素数
  int siz;
  const T INF=1e9;
  void init(){
    //sizをn以上の最小の2冪数にする
    siz=1;
    //nodeのサイズ
    int m=1;
    while(siz<n){
      siz*=2;
      m+=siz;
    }
    //nodeの数を初期化
    node.resize(m);
  }
  public:
  SegTree(int num):n(num){
    init();
  }
  //a[pos]をxに更新
  void update(int pos,T x){
    pos=pos+siz-1;
    node[pos]=x;
    while(pos>=2){
      pos/=2;
      node[pos]=node[pos*2]+node[pos*2+1];
    }
  }
  //半開区間[l,r)の最大値を求める
  //u:現在のセル番号、[a,b):セルに対応する半開区間、[l,r):求めたい半開区間
  //半開区間[l,r)の最大値を求めるにはquery(l,r,1,siz+1,1)を呼び出せばよい
  T query(int l,int r,int a,int b,int u){
    //一切含まれない場合
    if(r<=a||b<=l){
      return 0;
    }
    //完全に含まれる場合
    if(l<=a&&b<=r){
      return node[u];
    }
    int m=(a+b)/2;
    T leftAns=query(l,r,a,m,u*2);
    T rightAns=query(l,r,m,b,u*2+1);
    return leftAns+rightAns;
  }
  //半開区間[l,r)の最大値を求める
  T calcQuery(int l,int r){
    return query(l,r,1,siz+1,1);
  }
  int getSiz(){
    return siz;
  }
};
int main(){
  int n;
  cin>>n;
  SegTree<int> stree(n);
  long long ans=0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    ans+=(long long)stree.calcQuery(a,n+1);
    stree.update(a,1);
  }
  cout<<ans<<endl;
  return 0;
}