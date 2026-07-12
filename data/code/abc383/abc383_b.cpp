#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
vector<P> pvec;
int h,w,d;

bool is_ok(int i,int j,int x,int y){
  auto [x1,y1]=pvec[i];
  auto [x2,y2]=pvec[j];
  if(abs(x1-x)+abs(y1-y)<=d) return true;
  if(abs(x2-x)+abs(y2-y)<=d) return true;
  return false;
}

int main(){
  cin>>h>>w>>d;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin>>s[i];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='.') pvec.push_back({i,j});//床のマスを記録
    }
  }
  int n=pvec.size();
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      //i,j番目のマスに加湿器を置く
      int cnt=0;//床であり加湿される数の個数
      for(int si=0;si<h;si++){
        for(int sj=0;sj<w;sj++){
          if(s[si][sj]=='.'&&is_ok(i,j,si,sj)){//床であり2つの加湿器のいずれかからマンハッタン距離がd以内ならばcnt++
            cnt++;
          }
        }
      }
      ans=max(ans,cnt);//答えの更新
    }
  }
  cout<<ans<<endl;
  return 0;
}