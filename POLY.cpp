#include <iostream>
#define MOD 10000000
using namespace std;

int tc, N;
int cache[100][100];
int getPolyNum(int n, int std) {
	int& ret = cache[n][std];
	if (n == std) 
		return 1;
	if (ret != -1)
		return ret;
	ret = 0;
	int blocks = n - std;
	for (int i = 1; i <= blocks; i++) {
		ret += (std + i - 1) * getPolyNum(blocks, i);
		ret %= MOD;
	}
	return ret;
}
void init() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			cache[i][j] = -1;
}

int main() {
	cin >> tc;
	while (tc--) {
		cin >> N;
		int sum = 1; 
		init();
		for (int i = 1; i < N; i++) {
			sum += getPolyNum(N, i);
			sum %= MOD;
		}
		cout << sum << endl;
	}
	return 0;
}
