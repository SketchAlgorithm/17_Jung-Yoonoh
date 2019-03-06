#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define INTMAX 2147483640
using namespace std;

int N, x, length;
vector <int> v;
vector <int>::iterator it;
pair <int, int> p[1000000]; // idx, value;
vector<int> t;
int main() {
	cin >> N;
	length = 0;
	v.push_back(INTMAX);
	for (int i = 0; i < N; i++) {
		cin >> x;
		pair<int, int> tmp;
		if (v.back() < x) {
			v.push_back(x);
			length++;
			p[i].first = length;
			p[i].second = x;
		}
		else {
			it = lower_bound(v.begin(), v.end(), x);
			*it = x;
			int temp = it - v.begin();
			p[i].first = temp;
			p[i].second = x;
		}
	}
	cout << v.size() << endl;
	int size = length;

	for (int i = N - 1; i >= 0; i--) {
		if (size == p[i].first) {
			t.push_back(p[i].second);
			size--;
		}
	}
	reverse(t.begin(), t.end());
	for (int i = 0; i < t.size(); i++)
		cout << t[i] << " ";

	return 0;
}
