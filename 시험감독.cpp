#include <iostream>
using namespace std;
int N, B, C;
int a[1000000];

// 자료형을 생각하자
long long solve() {
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		a[i] -= B;
		cnt++;
		if (a[i] > 0) {
			int temp = (a[i] / C) + 1;
			if (!(a[i] % C))
				temp--;
			cnt += temp;
		}
	}
	return cnt;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> a[i];
	cin >> B >> C;
	cout << solve();
	return 0;
}
