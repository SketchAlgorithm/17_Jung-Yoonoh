#include <iostream>
#include <algorithm>
using namespace std;

int solve(int, int);
void init();

int testCase;
int triangleSize;
int check[101][101] = { 0, };
int triangle[101][101] = { 0, };


void init() {
	for(int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++) {
			check[i][j] = 0;
			triangle[i][j] = 0;
		}
}
int solve(int y, int x) {
	if (y > triangleSize)
		return 0;
	int& ret = check[y][x];

	if (ret != 0)
		return ret;

	ret = triangle[y][x] + max(solve(y + 1, x), solve(y + 1, x + 1));
	return ret;
}

int main()
{
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		init();
		cin >> triangleSize;
		for (int j = 0; j < triangleSize; j++)
			for (int k = 0; k <= j; k++)
				cin >> triangle[j][k];
		cout << solve(0, 0) << endl;
	}

	return 0;
}
