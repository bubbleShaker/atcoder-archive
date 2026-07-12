#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using vd = vector<double>;
using vl = vector<ll>;
using vs = vector<string>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
//using mint = modint998244353;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int N, D, Q, groupOne, groupTwo;
int sizeOfGroupOne, sizeOfGroupTwo, exchangeNum;
int d[200];
char res1, res2;
unordered_set<int> setOfGroup[100];

void input(){ 
    cin >> N >> D >> Q;
}

void generateGroup() {
    int group = 0;
    rep(i,N) {
        d[i] = group;
        setOfGroup[group].insert(i); //i番目の商品がグループ:groupにある
        group = (group+1)%D;
    }
}

void printGroup() {
    rep(i,N) {
        cout << d[i] << " \n"[i+1 == N];
    }
}

void determineTwoGroup() {
    groupOne = rand()%D;
    groupTwo = rand()%D;
    while(groupOne == groupTwo) {
        groupTwo = rand()%D;
    }
}

void firstQuestion() {
    sizeOfGroupOne = setOfGroup[groupOne].size();
    sizeOfGroupTwo = setOfGroup[groupTwo].size();
    printf("%d %d ",sizeOfGroupOne,sizeOfGroupTwo);
    for(int groupOneNum : setOfGroup[groupOne]) {
        cout << groupOneNum << " ";
    }
    int count = 0;
    for(int groupTwoNum : setOfGroup[groupTwo]) {
        cout << groupTwoNum << " \n"[count+1 == sizeOfGroupTwo];
        count++;
    }
    cout << flush;
}

void getResponse1() {
    cin >> res1;
}

void secondQuestion() {
    exchangeNum = 1;
    printf("%d %d ", exchangeNum, exchangeNum);
    int count1 = 0;
    for(int groupOneNum : setOfGroup[groupOne]) {
        if(count1 == exchangeNum) break;
        cout << groupOneNum << " ";
        count1++;
    }
    int count2 = 0;
    for(int groupTwoNum : setOfGroup[groupTwo]) {
        if(count2 == exchangeNum) break;
        cout << groupTwoNum << " \n"[count2+1 == exchangeNum];
        count2++;
    }
    cout << flush;
}

void getResponse2() {
    cin >> res2;
}

void exchange() {
    if(res1 != res2) return;
    unordered_set<int> tmpSet1 = setOfGroup[groupOne];
    unordered_set<int> tmpSet2 = setOfGroup[groupTwo];
    // cout << "# before "; //--debug
    // for(int val : setOfGroup[groupOne]) {
    //     cout << val << " ";
    // }
    // cout << endl;//--debug
    int count1 = 0;
    for(int groupOneNum : setOfGroup[groupOne]) {
        if(count1 == exchangeNum) break;
        tmpSet1.erase(groupOneNum);
        tmpSet2.insert(groupOneNum);
        count1++;
    }
    int count2 = 0;
    for(int groupTwoNum : setOfGroup[groupTwo]) {
        if(count2 == exchangeNum) break;
        tmpSet2.erase(groupTwoNum);
        tmpSet1.insert(groupTwoNum);
        count2++;
    }
    setOfGroup[groupOne] = tmpSet1;
    setOfGroup[groupTwo] = tmpSet2;
    // cout << "# after "; //--debug
    // for(int val : setOfGroup[groupOne]) {
    //     cout << val << " ";
    // }
    // cout << endl;//--debug
}

void shuffleSet() {
    vector<int> copy1, copy2;
    for(int groupOneNum : setOfGroup[groupOne]) copy1.push_back(groupOneNum);
    for(int groupTwoNum : setOfGroup[groupTwo]) copy2.push_back(groupTwoNum);
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(all(copy1), engine);
    shuffle(all(copy2), engine);
    unordered_set<int> newSet1, newSet2;
    rep(i,copy1.size()) newSet1.insert(copy1[i]);
    rep(i,copy2.size()) newSet2.insert(copy2[i]);
    setOfGroup[groupOne] = newSet1;
    setOfGroup[groupTwo] = newSet2;
}

void changeGroup() {
    for(int i = 0; i < D; i++) {
        for(int syohin : setOfGroup[i]) {
            d[syohin] = i;
        }
    }
}

void solve(){
    srand((unsigned)time(NULL));
    input();
    generateGroup();
    while(Q) {
        determineTwoGroup();
        shuffleSet();
        firstQuestion();
        Q--;
        getResponse1();
        if(Q <= 0) break;
        secondQuestion();
        Q--;
        getResponse2();
        exchange();
        changeGroup();
        // cout << "#c ";//--debug
        // printGroup();//--debug
    }
    printGroup();
}

int main(){
    solve();
    return 0 ;
}