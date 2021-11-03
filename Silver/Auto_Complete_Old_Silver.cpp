/*
ID: david.w4
TASK:auto
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct wordPair {
	int originalIndex;
	string word;
	wordPair() {}
	wordPair(int ind, string a) : originalIndex(ind), word(a) {}
};
bool compareByWord(const wordPair& a, const wordPair& b) {
	return a.word < b.word;
}
vector<wordPair> dict;
int binIndex(string a, int place) {
	int l = 0, r = dict.size() - 1, mid = 0;
	string test;
	for (; l <= r;) {
		mid = (l + r) / 2;
		test = dict[mid].word.substr(0, a.length());
		if (test.compare(a) < 0)
			l = mid + 1;
		else if (test.compare(a) > 0)
			r = mid - 1;
		else if (l != mid)
			r = mid;
		else {
			//cout << mid << " " << l << " " << r << "\n";
			break;
		}
		//cout << mid << " " << l << " " << r << "\n";
	}
	if ((dict[mid].word.substr(0, a.length()).compare(a) != 0))
		return -1;
	else if (!(mid + place - 1 >= dict.size()) && dict[mid + place - 1].word.substr(0, a.length()).compare(a) == 0)
		return dict[mid + place - 1].originalIndex;
	else
		return  -1;

	
}
int main()
{
	freopen("auto.in", "r", stdin);
	freopen("auto.out", "w", stdout);
	int W, N, rv, queryplace;
	string querystring, filler;
	cin >> W >> N;
	dict.resize(W);
	for (int i = 0; i < W; i++) {
		cin >> filler;
		dict[i] = wordPair(i + 1, filler);
	}
	sort(dict.begin(), dict.end(), compareByWord);
	for (int i = 0; i < N; i++) {
		cin >> queryplace >> querystring;
		cout << binIndex(querystring, queryplace) << "\n";

	}

}

