#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2147483647
using namespace std;

int tc, N, num;
vector <int> v;
vector <int>::iterator it;
int main() {
	cin >> tc;
	while (tc--) {
		cin >> N;
		v.clear();
		v.push_back(MAX);
		for (int i = 0; i < N; i++) {
			cin >> num;
			if (v.back() < num)
				v.push_back(num);
			else {
				it = lower_bound(v.begin(), v.end(), num);
				*it = num;
			}
		}
		cout << v.size() << endl;
	}
	return 0;
}
