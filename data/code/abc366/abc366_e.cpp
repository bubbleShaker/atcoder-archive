#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
int main(){
  int n;
  long long d;
  std::cin>>n>>d;
  std::vector<long long> x(n),y(n);
  std::map<long long,int> map_x,map_y;
  long long M=1e6;
  for(int i=0;i<n;i++){
    std::cin>>x[i]>>y[i];
    map_x[x[i]]++;
    map_y[y[i]]++;
  }
  auto greater_than=[&](std::vector<long long> vec,long long val){ //valより大きいvecの要素数
    int ret=std::upper_bound(vec.begin(),vec.end(),val)-vec.begin();
    return (int)vec.size()-ret;
  };
  auto less_than=[&](std::vector<long long> vec,long long val){ //val未満のvecの要素数
    int ret=std::lower_bound(vec.begin(),vec.end(),val)-vec.begin();
    return ret;
  };
  
  // ↓コストの前計算
  std::sort(x.begin(),x.end());
  std::sort(y.begin(),y.end());
  
  std::vector<long long> cost_x((int)2*(M+d)+1),cost_y((int)2*(M+d)+1); //-M+d→0,0→M+d,M+d→2*(M+d)として扱う
  //一番左のx座標でのx軸のコストを計算する
  for(int i=0;i<n;i++){
    cost_x[0]+=std::abs(-(long long)(M+d)-x[i]);
  }
  //cntの初期解
  int dec_cnt_x=greater_than(x,-(long long)(M+d));
  int inc_cnt_x=less_than(x,-(long long)(M+d)+1);
  for(int x=-(int)(M+d);x<(int)(M+d);x++){
    int prev_x=x;
    int now_x=prev_x+1;
    cost_x[now_x+(int)(M+d)]=cost_x[prev_x+(int)(M+d)]+inc_cnt_x-dec_cnt_x;
    //xを動かした時のcntの動きを考える
    if(map_x.count(now_x)){ //今のx座標と同じx座標を持つ点があるならば
      inc_cnt_x+=map_x[now_x]; //xを移動後、コストを1増やす要素の個数がその個数だけ増える
      dec_cnt_x-=map_x[now_x]; //コストを1減らす要素の個数がその個数だけ減る
    }
  }
  
  //一番下のy座標でのy軸のコストを計算する
  for(int i=0;i<n;i++){
    cost_y[0]+=std::abs(-(long long)(M+d)-y[i]);
  }
  //cntの初期解
  int dec_cnt_y=greater_than(y,-(long long)(M+d));
  int inc_cnt_y=less_than(y,-(long long)(M+d)+1);
  for(int y=-(int)(M+d);y<(int)(M+d);y++){
    int prev_y=y;
    int now_y=prev_y+1;
    cost_y[now_y+(int)(M+d)]=cost_y[prev_y+(int)(M+d)]+inc_cnt_y-dec_cnt_y;
    //dec_cnt,inc_cntを更新する
    if(map_y.count(now_y)){ //移動前のy座標と同じy座標を持つ点があるならば
      inc_cnt_y+=map_y[now_y]; //コストを1増やす要素の個数が1増える
      dec_cnt_y-=map_y[now_y]; //コストを1減らす要素の個数が1減る
    }
  }
  // ↑コストの前計算

  // ↓cost_x+cost_y<=dを満たす(x,y)の計算  
  std::sort(cost_x.begin(),cost_x.end());
  std::sort(cost_y.begin(),cost_y.end());
  
  long long ans=0;
  //尺取り法で実装する
  int r_idx=2*(M+d); //cost_y用の添え字r_idx
  for(int i=0;i<(int)2*(M+d)+1;i++){
    while(r_idx>=0&&cost_y[r_idx]+cost_x[i]>d){ //cost_x+cost_y>dとなるcost_yならばr_idx--
      r_idx--;
    }
    ans+=(long long)r_idx+1;
  }
  // ↑cost_x+cost_y<=dを満たす(x,y)の計算
  
  // std::cout<<"test"<<'\n';
  std::cout<<ans<<'\n';
  return 0;
}