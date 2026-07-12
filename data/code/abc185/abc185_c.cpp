#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(std::string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

int main(){
  std::string bunbo_s="39916800";
  __int128_t bunbo=parse(bunbo_s);
  int l;
  std::cin>>l;
  __int128_t bunshi=1;
  for(int i=1;i<=11;i++){
    int tmp=l-i;
    std::string tmp_s=std::to_string(tmp);
    __int128_t val=parse(tmp_s);
    bunshi*=val;
  }
  std::cout<<bunshi/bunbo<<'\n';
  return 0;
}