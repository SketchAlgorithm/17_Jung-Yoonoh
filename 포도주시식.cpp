#include <iostream>
#include <algorithm>
using namespace std;

int tc, n, sav = 0;
int grape[10001];
int cache[10001] = {0,}; // 현재까지 마실 수 있는 최대 양
//2차원시 용량펑

int solve() {
	for (int i = 1; i < 3; i++) 
		i == 1 ? cache[i] = grape[i] : cache[i] = grape[i] + grape[i - 1]; // 잔이 2개이하일경우 답이 바로 나옴
	for (int i = 3; i <= n; i++) { 
    // 현재 잔 포함 3개만 고려(연속 3개 방지)
    // 상황은 현재 바로 전 부터 3개 이전까지 고려 -> 잔 이전의 상황 + 잔 이므로
		sav = max(cache[i - 3] + grape[i - 1] + grape[i], cache[i - 2] + grape[i]);
		sav = max(sav, cache[i - 1]);
		cache[i] = sav;
	}

	return cache[n];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> grape[i];
	cout << solve() << endl;
	return 0;
}
