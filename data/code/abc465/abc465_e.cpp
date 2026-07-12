#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <bit>
#include <atcoder/all>
#include <format>

using namespace std;
using namespace atcoder;
using ll = long long;

ll dp[510][2][2][1LL << 11][3];
int checkedDp[510][2][2][1LL << 11][3];

int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	const ll MOD = 998244353;
	// dp[digit][isTight][isLeadingZero][bit_set][modulo]

	int fir = s[0] - '0';
	for (int num = 1;num <= fir;num++) {
		int mod = num % 3;
		int t = (num == fir) ? 1 : 0;
		int l = 0;
		int b = (num==0)?0:1LL << num;
		dp[0][t][l][b][mod] = 1;
		/*printf("num:%d, t:%d, l:%d, b:%d, mod:%d\n", num, t, l, b, mod);*/
	}

	dp[0][0][1][0][0] = 1;

	/*cout << "before : " << dp[0][0][0][0b0000010][1] << endl;*/


	for (int d = 0;d < n-1;d++) {
		int curNum = s[d] - '0';
		int neNum = (d < n-1) ? s[d + 1]-'0' : 0;
		for (int l = 0;l < 2;l++) {
			for (int m = 0; m < 3; m++) {
				for (int t = 0;t < 2;t++) {
					for (int nowNum = 0;nowNum <= ((t == 0) ? 9 : curNum);nowNum++) {
						for (int b = 0; b < 1LL << 10; b++) {
							if (l == 0 && ((b & (1LL << nowNum)) == 0)) {
								continue;
							}
							if (popcount((uint32_t)b) > d+1) continue;

							b = (nowNum == 0) ? b : b | (1LL << nowNum);
							ll cur = dp[d][t][l][b][m];
							/*printf("curが0です : digit is %d, nowNum is %d, l is %d, tight is %d, cur is %d, m is %d, ", d, nowNum, l, t, cur, m);
							cout << format("bitSet is {:#b}\n", b);*/
							if (cur == 0) continue;
							if (checkedDp[d][t][l][b][m] > 0) continue;
							checkedDp[d][t][l][b][m]++;

							/*printf("\n------------\n");

							printf("cur が 1 以上です : cur is %d\n", cur);*/

							int maxNum = (t == 0) ? 9 : neNum;
							/*printf("maxNum is %d\n", maxNum);*/
							for (int nextNum = 0;nextNum <= maxNum;nextNum++) {
								/*printf("digit is %d, nowNum is %d, t is %d, l is %d, b is %d, m is %d, ", d, nowNum, t, l, b, m);
								cout << format("bitSet is {:#b}\n", b);*/
								int nextTight = (nextNum == maxNum && t == 1) ? 1 : 0;
								int nextLeading = (l == 1 && nextNum == 0) ? 1 : 0;
								int nextBit = (nextNum == 0 && l == 1) ? b : (b | 1LL << nextNum);
								int nextModulo = (m * 10 + nextNum) % 3;
								/*printf("n_digit is %d, n_nowNum is %d, n_t is %d, n_l is %d, n_b is %d, n_m is %d, ", d+1, nextNum, nextTight, nextLeading, nextBit, nextModulo);
								cout << format("n_bitSet is {:#b}\n", nextBit);*/
								dp[d + 1][nextTight][nextLeading][nextBit][nextModulo] += cur;
								dp[d + 1][nextTight][nextLeading][nextBit][nextModulo] %= MOD;
							}
							/*printf("------------\n\n");*/
						}
					}
				}
			}
		}
	}

	ll ans = 0;

	for (int t = 0; t < 2;t++) {
		for (int l = 0;l < 2;l++) {
			for (int b = 1; b < 1LL << 11; b++) {
				for (int m = 0;m < 3;m++) {
					int cnt = 0;
					if (m==0) {
						cnt++;
					}
					if (b & (1LL << 3)) {
						cnt++;
					}
					if (popcount((uint32_t)b) == 3) {
						cnt++;
					}
					ll dpCnt = dp[n-1][t][l][b][m];
					if (cnt == 1 && dpCnt > 0) {
						ans += dpCnt;
						ans %= MOD;
						/*if (m == 0)printf("条件 1 のみ満たしています : ");
						if (b & (1LL << 3))printf("条件 2 のみ満たしています : ");
						if (popcount((uint32_t)b) == 3)printf("条件 3 のみ満たしています : ");
						printf("t is %d, l is %d, m is %d, ", t, l, m);
						cout << format("bitSet is {:#b}, ", b);
						printf("dpCnt is %d\n", dpCnt);*/
					}
				}
			}
		}
	}
	cout << ans << endl;
}
