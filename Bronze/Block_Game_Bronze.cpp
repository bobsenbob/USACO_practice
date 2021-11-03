/*
ID: dwang5766
TASK: blocks
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct block{
	string front;
	string back;
	block() {}
	block(string f, string b) : front(f), back(b) {}
};
vector<int> calculate(block a){
	vector<int> front(26);
	vector<int> back(26);
	vector<int> rv(26);
	for (int i = 0; i < a.front.length(); i++)
		front[(int)a.front.at(i) - 97]++;
	for (int i = 0; i < a.back.length(); i++)
		back[(int)a.back.at(i) - 97]++;
	for (int i = 0; i < 26; i++)
		rv[i] = max(front[i], back[i]);
	return rv;

}
int main()
{
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	int N;
	cin >> N;
	string a, b;
	vector<int> amount(26);
	vector<int> adding(26);
	vector<block> blocks(N);
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		blocks[i] = block(a, b);
	}
	for (int i = 0; i < N; i++){
		adding = calculate(blocks[i]);
		for (int j = 0; j < 26; j++)
			amount[j] += adding[j];
	}
	for (int i = 0; i < 26; i++)
		cout << amount[i] << "\n";
	system("pause");
	return 0;

}

