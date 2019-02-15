#include <iostream>

using namespace std;

int testCase;
int n, m; //학생,쌍
bool matelist[10][10];
bool friendcheck[10];

int solve(bool friendcheck[10]) {
	int selectNum = -1;

	for (int i = 0; i < n; i++) {
		if (!friendcheck[i]) {
			selectNum = i;
			break;
		}
	}
	if (selectNum == -1)
		return 1;
	int total = 0;
	for (int i = selectNum + 1; i < n; i++) {
		if (!friendcheck[i] && matelist[selectNum][i]) {
			friendcheck[i] = true;
			friendcheck[selectNum] = true;
			total += solve(friendcheck);
			friendcheck[i] = false;
			friendcheck[selectNum] = false;
		}
	}
	return total;
}
void init() {
	for (int i = 0; i < 10; i++) {
		friendcheck[i] = false;
		for (int j = 0; j < 10; j++)
			matelist[i][j] = false;
	}

}

int main() {
	cin >> testCase;
	int temp1, temp2;
	while (testCase--) {
		cin >> n >> m;
		init();
		for (int i = 0; i < m; i++) {
			cin >> temp1 >> temp2;
			matelist[temp1][temp2] = true;
			matelist[temp2][temp1] = true;
		}
		cout << solve(friendcheck) << endl;
	}
	return 0;
}
