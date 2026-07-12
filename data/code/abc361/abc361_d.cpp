#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <map>
int main(){
  int n;
  std::string s,t;
  std::cin>>n>>s>>t;
  //空きマスは'.'とする
  s+=".";
  s+=".";
  t+=".";
  t+=".";
  const long long INF=4e18;
  auto dijkstra=[&](std::string start){//1-indexed想定
    std::map<std::string,long long> cur;//暫定距離を記録
    std::map<std::string,bool> confirmed;//最短距離が確定した頂点
    std::priority_queue<std::pair<long long,std::string>,std::vector<std::pair<long long,std::string>>,std::greater<std::pair<long long,std::string>>> hque;
    hque.push({0,start});
    cur[start]=0;
    while(!hque.empty()){
      auto [_,u]=hque.top();
      hque.pop();
      if(confirmed.count(u)){// !確定済み頂点である間、キューの最小値を削除し続ける
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
      confirmed[u]=true;
      
      //前計算
      int k; //k,k+1番目を空とする
      for(int i=0;i<n+1;i++){
        if(u[i]=='.'&&u[i+1]=='.'){
          k=i;
          continue;
        }
      }
      
      //遷移を考える
      for(int i=0;i<n+1;i++){
        if(i==k||i+1==k||i==k+1){
          continue;
        }
        std::string v=u;
        for(int j=0;j<2;j++){
          v[k+j]=u[i+j];
          v[i+j]='.';
        }
        // std::cout<<"v is "<<v<<'\n';
        if(!confirmed.count(v)){
          if(!cur.count(v)){ //curの初期化をする
            cur[v]=INF;
          }
          cur[v]=std::min(cur[v],1+cur[u]);
          hque.push({cur[v],v});
        }
      }
      
      
      // for(auto [c,v]:g[u]){
      //   if(!confirmed[v]){//隣接している未確定頂点についてcurを更新
      //     // *正直こっちの確認は計算量削減にはあまり寄与しない
      //     //各頂点の次数の総和は2Mなので、2M回しかキューには入らなく、!で示した部分があればそれぞれO(1)しか影響しない。
      //     cur[v]=std::min(cur[v],c+cur[u]);//!暫定距離を更新していく
      //     //!暫定距離の更新は現在の値とのchminを取りつつ更新することに注意
      //     //!push時にcur更新、pop時にconfirm確定、という気持ちでよさそう
      //     //!curは更新されるとは限らないことに注意
      //     hque.push({cur[v],v});//ヒープキューに暫定距離を入れつつ
      //   }
      // }
    }
    return cur;
  };
  std::map<std::string,long long> cur=dijkstra(s);
  if(cur.count(t)){
    std::cout<<cur[t]<<'\n';
  }else{
    std::cout<<-1<<'\n';
  }
  return 0;
}