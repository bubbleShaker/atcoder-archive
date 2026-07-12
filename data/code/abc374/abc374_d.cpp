#include <bits/stdc++.h>
using namespace std;
using P=pair<double,double>;

double cal_time(double speed,P p1,P p2){
  auto [sx,sy]=p1;
  auto [gx,gy]=p2;
  double dist=sqrt((sx-gx)*(sx-gx)+(sy-gy)*(sy-gy));
  return dist/speed;
}

int main(){
  const double INF=2e18;
  int n;
  double s,t;
  cin>>n>>s>>t;
  vector<pair<P,P>> ab_cd(n);
  for(int i=0;i<n;i++){
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    ab_cd[i]=make_pair(make_pair(a,b),make_pair(c,d));
  }
  double ans=INF;
  //bit全探索
  for(int bit=0;bit<(1<<n);bit++){
    bitset<6> bts(bit);
    //順列全探索
    vector<int> per(n);
    for(int i=0;i<n;i++)per[i]=i;
    do{
      double now_x=0,now_y=0;
      double cost=0;
      
      for(int i=0;i<n;i++){
        auto [p1,p2]=ab_cd[per[i]];
        auto [a,b]=p1;
        auto [c,d]=p2;
        //step1.現在地点から開始位置まで移動
        //step2.開始位置から終了位置まで移動
        if(bts[per[i]]){//1なら(a,b)→(c,d)
          cost+=cal_time(s,make_pair(now_x,now_y),make_pair(a,b));//(a,b)まで移動
          cost+=cal_time(t,make_pair(a,b),make_pair(c,d));//(c,d)まで移動
          now_x=c;
          now_y=d;
        }else{//0なら(c,d)→(a,b)
          cost+=cal_time(s,make_pair(now_x,now_y),make_pair(c,d));//(c,d)まで移動
          cost+=cal_time(t,make_pair(c,d),make_pair(a,b));//(a,b)まで移動
          now_x=a;
          now_y=b;
        }
      }
      
      ans=min(ans,cost);
    }while(next_permutation(per.begin(),per.end()));
  }
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
  return 0;
}