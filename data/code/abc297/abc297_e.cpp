#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<long long> a(n);
  for(auto &&in:a){
    cin>>in;
  }
  sort(a.begin(),a.end());
  set<long long> confirmedSet;
  vector<long long> confirmed;//最短距離が確定した頂点
  auto dijkstra=[&](){
    priority_queue<long long,vector<long long>,greater<long long>> hque;
    for(auto num:a){
      hque.push(num);
    }
    while(!hque.empty()&&confirmed.size()<k){
      // cerr<<confirmed.size()<<'\n';
      long long u=hque.top();
      hque.pop();
      if(confirmedSet.count(u)){// !確定済み頂点である間、キューの最小値を削除し続ける
        continue;// !これを入れないとO(M^2)になってしまうケースがありそう。
        // !実際に実験すると、下の*での確認だけでは、同じ頂点に対して複数の{コスト,頂点}の要素が入りうると分かる。
        // !これを入れないと同じ頂点に対してN回ループ処理することになり、ボトルネックになりうる。
        // !実験メモ
        // !完全グラフに対して、キューへのpushの時にコストが全部同じになるようにしてシミュレーション。
        // !キューの要素は合計で2M個になった。
        // !これらの要素全てについてN回調べると、2M+(2M-N)N回の計算をするため、O(NM)となる。
        // !この!での確認を行えば2M+log(MlogM)でconfirmを全て確定できる。
        // !よって全体でO(MlogM)になりそう。
      }
      confirmedSet.insert(u);
      confirmed.push_back(u);
      for(int i=0;i<n;i++){
        long long v=u+a[i];
        if(!confirmedSet.count(v)){//隣接している未確定頂点についてcurを更新
          // *正直こっちの確認は計算量削減にはあまり寄与しない
          //各頂点の次数の総和は2Mなので、2M回しかキューには入らなく、!で示した部分があればそれぞれO(1)しか影響しない。
          hque.push(v);//ヒープキューに暫定距離を入れつつ
          // cur[v]=min(cur[v],c+cur[u]);//!暫定距離を更新していく
          // //!暫定距離の更新は現在の値とのchminを取りつつ更新することに注意
          // //!push時にcur更新、pop時にconfirm確定、という気持ちでよさそう
          // //!curは更新されるとは限らないことに注意
        }
      }
    }
  };
  dijkstra();
  // for(auto out=confirmed.begin();out!=confirmed.end();out++){
  //   cout<<*out<<((out!=--confirmed.end())?' ':'\n');
  // }
  cout<<confirmed[k-1]<<'\n';
}