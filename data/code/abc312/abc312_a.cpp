#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    string s;
    cin >> s;
    if(s == "ACE" ||s == "BDF" ||s == "CEG" ||s == "DFA" ||s == "EGB" ||s == "FAC" ||s == "GBD"){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
