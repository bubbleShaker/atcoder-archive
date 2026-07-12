#include <iostream>
int main(){
  char sab,sac,sbc;
  std::cin>>sab>>sac>>sbc;
  
  if(sab=='<'&&sac=='<'){
    if(sbc=='<'){
      std::cout<<'B'<<'\n';
    }else{
      std::cout<<'C'<<'\n';
    }
  }else if(sab=='>'&&sbc=='<'){
    if(sac=='<'){
      std::cout<<'A'<<'\n';
    }else{
      std::cout<<'C'<<'\n';
    }
  }else if(sac=='>'&&sbc=='>'){
    if(sab=='<'){
      std::cout<<'A'<<'\n';
    }else{
      std::cout<<'B'<<'\n';
    }
  }
  return 0;
}