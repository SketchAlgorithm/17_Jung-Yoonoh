#include <iostream>
#include <vector>
using namespace std;

struct Info {
	int x;
	int y;
	int cctv;
	Info(int x, int y, int c) :x(x), y(y), cctv(c) {}
};

int row, col;
int room[8][8] = { 0, };
vector <Info> info;
int savMin = 64;
//9은 감시구역

int count() {
	int temp = 0;
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++)
			if (room[i][j] == 0)
				temp++;

	return temp;
}

void rotate(int dir, int x, int y) {
	//상
	if (dir == 0) {
		int ny = y - 1;
		if (ny < 0) return;
		if (room[ny][x] == 6) return;
		room[ny][x] = 9;
		rotate(0, x, ny);
	}
	//우
	else if (dir == 1) {
		int nx = x + 1;
		if (nx > col - 1) return;
		if (room[y][nx] == 6) return;
		room[y][nx] = 9;
		rotate(1, nx, y);
	}
	//하
	else if (dir == 2) {
		int ny = y + 1;
		if (ny > row - 1) return;
		if (room[ny][x] == 6) return;
		room[ny][x] = 9;
		rotate(2, x, ny);
	}
	//좌
	else {
		int nx = x - 1;
		if (nx < 0) return;
		if (room[y][nx] == 6) return;
		room[y][nx] = 9;
		rotate(3, nx, y);
	}
}

void savMap(int (*a)[8], int (*b)[8]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] = b[i][j];
		}
	}

}

void solve(int cnt) {
	if (cnt >= info.size()) {
		int cantsee = count();
		if (savMin > cantsee)
			savMin = cantsee;
	}
	else {
		int kind = info.at(cnt).cctv;
		int x = info.at(cnt).x;
		int y = info.at(cnt).y;

		int temp[8][8];

		//1번 cctv는 단방향
		if (kind == 1) {
			for (int i = 0; i < 4; i++) {
				savMap(temp, room);
				rotate(i, x, y);
				solve(cnt + 1);
				savMap(room, temp);
			}
		}
		//2번 cctv는 양쪽
		else if (kind == 2) {
			for (int i = 0; i < 2; i++) {
				savMap(temp, room);
				rotate(i, x, y);
				rotate(i + 2, x, y);
				solve(cnt + 1);
				savMap(room, temp);
			}
		}
		//3번 cctv는 90도 2방향씩
		else if (kind == 3) {
			for (int i = 0; i < 4; i++) {
				savMap(temp, room);
				rotate(i, x, y);
				rotate((i + 1) % 4, x, y);
				solve(cnt + 1);
				savMap(room, temp);
			}
		}
		//4번 cctv 3방향씩
		else if (kind == 4) {
			for (int i = 0; i < 4; i++) {
				savMap(temp, room);
				rotate(i, x, y);
				rotate((i + 1) % 4, x, y);
				rotate((i + 2) % 4, x, y);
				solve(cnt + 1);
				savMap(room, temp);
			}
		}
		//5번 cctv 4방향
		else {
			savMap(temp, room);
			for (int i = 0; i < 4; i++) {
				rotate(i, x, y);
			}
			solve(cnt + 1);
			savMap(room, temp);
		}
	}
}

int main() {
	cin >> row >> col;
	int roomSize = row * col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> room[i][j];
			if (room[i][j] != 0 && room[i][j] != 6)
				info.push_back(Info(j, i, room[i][j]));
		}
	}
	solve(0);
	cout << savMin << endl;

	return 0;
}
