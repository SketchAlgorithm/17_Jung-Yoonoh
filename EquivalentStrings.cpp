#include <iostream>
#include <string>
using namespace std;

//string a, b;
//double a1[26], a2[26], b1[26], b2[26];
//
//void init() {
//	for (int i = 0; i < 26; i++) 
//		a1[i] = a2[i] = b1[i] = b2[i] = 0;
//}
//
//int main() {
//	bool check = true;
//	cin >> a >> b;
//	init();
//	if (a == b) {
//		cout << "YES" << endl;
//		return 0;
//	}
//	if (a.size() % 2) {
//		cout << "NO" << endl;
//		return 0;
//	}
//	for (int i = 0; i < a.size(); i++) {
//		if (i < a.size() / 2)
//			a1[a.at(i) - 'a']++;
//		else a2[a.at(i) - 'a']++;
//	}
//	for (int i = 0; i < b.size(); i++) {
//		if (i < b.size() / 2)
//			b1[b.at(i) - 'a']++;
//		else b2[b.at(i) - 'a']++;
//	}
//
//	for (int i = 0; i < 26; i++) {
//		if (a1[i] != b1[i] || a2[i] != b2[i]) {
//			check = false;
//			break;
//		}
//	}
//
//	if (check) {
//		cout << "YES" << endl;
//		return 0;
//	}
//	check = true;
//	for (int i = 0; i < 26; i++) {
//		if (a1[i] != b2[i] || a2[i] != b1[i]) {
//			check = false;
//			break;
//		}
//	}
//	if (check)
//		cout << "YES" << endl;
//	else cout << "NO" << endl;
//
//	return 0;
//}

string a, b, a1, a2, b1, b2;
string solve(string c)
{
	if (c.size() % 2) 
		return c;
	string s1 = solve(c.substr(0, c.size() / 2));
	string s2 = solve(c.substr(c.size() / 2, c.size()));
	if (s1 > s2)
		return (s2 + s1);
	else return (s1 + s2);
}
int main() {
	cin >> a >> b;
	if (solve(a) == solve(b))
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
