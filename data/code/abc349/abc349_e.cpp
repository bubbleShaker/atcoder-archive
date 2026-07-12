#include <iostream>
#include <vector>
#include <string>
int main(){
  std::vector<std::vector<int>> a(3,std::vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      std::cin>>a[i][j];
    }
  }
  std::vector<std::string> s(3,"www");
  
  auto thereIsLine=[&](std::vector<std::string> s,char color){
    //行方向で揃っているか
    for(int i=0;i<3;i++){
      int cnt=0;
      for(int j=0;j<3;j++){
        if(s[i][j]==color){
          cnt++;
        }
      }
      if(cnt==3){
        return true;
      }
    }
    //列方向で揃っているか
    for(int j=0;j<3;j++){
      int cnt=0;
      for(int i=0;i<3;i++){
        if(s[i][j]==color){
          cnt++;
        }
      }
      if(cnt==3){
        return true;
      }
    }
    //斜めに揃っているか
    if(s[0][0]==s[1][1]&&s[1][1]==s[2][2]&&s[0][0]==color||s[0][2]==s[1][1]&&s[1][1]==s[2][0]&&s[0][2]==color){
      return true;
    }
    //揃っていない場合
    return false;
  };
  
  auto f=[&](auto f,std::vector<std::string> c,std::string player)->std::string{
    //揃ってるのがあるか
    if(thereIsLine(c,'r')){
      return "Takahashi";
    }else if(thereIsLine(c,'b')){
      return "Aoki";
    }
    
    //揃ってるのが無い場合
    bool thereIsWhite=false;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(c[i][j]=='w'){
          thereIsWhite=true;
        }
      }
    }
    //置く場所が無い場合,得点を計算する
    if(!thereIsWhite){
      long long takahashiPoint=0;
      long long aokiPoint=0;
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          if(c[i][j]=='r'){
            takahashiPoint+=(long long)a[i][j];
          }else{
            aokiPoint+=(long long)a[i][j];
          }
        }
      }
      if(takahashiPoint>aokiPoint){
        return "Takahashi";
      }else{
        return "Aoki";
      }
    }
    
    //置く場所がある場合、遷移をする
    
    //たかはしくんが置く場合
    if(player=="Takahashi"){ 
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          std::vector<std::string> cc=c;
          if(c[i][j]=='w'){ //白があったらrとして遷移
            cc[i][j]='r';
            if(f(f,cc,"Aoki")=="Takahashi"){ //1個でも勝てる遷移があるならたかはしくんの勝ち
              return "Takahashi";
            }
          }
        }
      }
      return "Aoki"; //勝てる遷移がなかったらあおきくんの勝ち
    }else if(player=="Aoki"){ //あおきくんが置く場合
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          std::vector<std::string> cc=c;
          if(c[i][j]=='w'){
            cc[i][j]='b';
            if(f(f,cc,"Takahashi")=="Aoki"){ //1個でも勝てる遷移があるならあおきくんの勝ち
              return "Aoki";
            }
          }
        }
      }
      return "Takahashi"; //勝てる遷移が無かったらたかはしくんの勝ち
    }
  };
  
  if(f(f,s,"Takahashi")=="Takahashi"){
    std::cout<<"Takahashi"<<'\n';
  }else{
    std::cout<<"Aoki"<<'\n';
  }
  return 0;
}