#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int solve();
int findMinWin(int xWinNum);
int findMaxWin();
void init();

int tc;
int N, M; //선수 수, 남은 경기 수
int minIdx, maxIdx;
vector<int> winNum; // n번째 선수의 승수
vector<pair<int, int>> match; // 경기리스트
int gameNumCnt[12];
int exceptZero[12]; // 1~11번 선수만 사용
bool checkFull = false;

int solve() {

	if (winNum.at(0) + gameNumCnt[0] <= findMaxWin()) // X가 우승할 수 있는지 판단
		return -1;

	vector<pair<int, int>>::iterator iter = match.begin(); // begin,erase함수를 Templete pair<int,int>에 대해 재정의해야한다.
	findMinWin(winNum.at(0));
	while ((winNum.at(0) - 1 > winNum.at(minIdx))) {
		for(iter = match.begin(); iter != match.end();) {
			if ((winNum.at(0) - 1 > winNum.at(minIdx)))
				break;
			if ((*iter).first == minIdx || (*iter).second == minIdx) {
				gameNumCnt[(*iter).first]--;
				gameNumCnt[(*iter).second]--;
				winNum.at(minIdx)++;
				iter = match.erase(iter);
			}
			else {
				iter++;
			}
		}
		if (match.size() == 0)
			break;
		findMinWin(winNum.at(0));
		if (checkFull)
			minIdx = 0;
	}
	return winNum.at(0);
}

int findMinWin(int xWinNum) {
	int findIdx = 1;
	int Min = gameNumCnt[1] + winNum[1];
	for (int i = 2; i < 12; i++) {
		if (gameNumCnt[i] + winNum[i] < Min) {
			Min = gameNumCnt[i] + winNum[i];
			minIdx = findIdx = i;
		}
	}
	if (findIdx == 1 && winNum[findIdx] + 1 == xWinNum)
		checkFull = true;
	else checkFull = false;
	return Min;
}

int findMaxWin() {
	int findIdx = 1;
	int Max = exceptZero[1] + winNum[1]; 
	for (int i = 2; i < 12; i++) {
		if (exceptZero[i] + winNum[i] > Max) {
			Max = exceptZero[i] + winNum[i];
		}
	}
	return Max;
}

void init() {
	for (int i = 0; i < 12; i++) {
		gameNumCnt[i] = 0;
		exceptZero[i] = 0;
	}
	checkFull = false;
	minIdx = -1; 
}

int main() {
	cin >> tc;
	int a[12], b[100];
	while (tc--) {
		init();
		int temp1, temp2;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
			winNum.push_back(a[i]);
		}
		for (int i = 0; i < M; i++) {
			cin >> temp1 >> temp2;
			pair<int, int> t;
			t.first = temp1; t.second = temp2;
			if (temp1 != 0 && temp2 != 0) {
				exceptZero[temp1]++; exceptZero[temp2]++;
			}
			match.push_back(t);
			gameNumCnt[temp1]++; gameNumCnt[temp2]++;
		}
		cout << solve() << endl;
		winNum.clear(); match.clear();
	}
	return 0;
}
