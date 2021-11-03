/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
map<char, vector<int>> mods;
map<char, int> total;
vector<char> chars {'B', 'E', 'S', 'I', 'G', 'O', 'M'};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("bgm.in", "r", stdin); freopen("bgm.out", "w", stdout);
	long long N, b, first = 0, second = 0, third = 0, ft = 0, st = 0, tt = 0;
	char a;
	cin >> N;
	for (int i = 0; i < chars.size(); i++){
		mods.insert({chars[i], vector<int>(7, 0)});
		total.insert({chars[i], 0});
	}
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		mods[a][(b % 7 + 7) % 7]++;
		total[a]++;
	}
	//First expression: BESSIE
	//B
	for (int i = 0; i < 7; i++){
		//E
		for (int j = 0; j < 7; j++){
			//S
			for (int k = 0; k < 7; k++){
				//I
				for (int l = 0; l < 7; l++){
					if ((i + 2 * j + 2 * k + l) % 7 == 0){
						first += mods['B'][i] * mods['E'][j] * mods['S'][k] * mods['I'][l];
						break;
					}
				}
			}
		}
	}
	//Second expression: GOES
	//G
	for (int i = 0; i < 7; i++){
		//O
		for (int j = 0; j < 7; j++){
			//E
			for (int k = 0; k < 7; k++){
				//S
				for (int l = 0; l < 7; l++)
					if ((i + j + k + l) % 7 == 0){
						second += mods['G'][i] * mods['O'][j] * mods['E'][k] * mods['S'][l];
						break;
					}
			}
		}
	}
	//Third expression: MOO
	//M
	for (int i = 0; i < 7; i++){
		//O
		for (int j = 0; j < 7; j++)
			if ((i + 2 * j) % 7 == 0){
				third += mods['M'][i] * mods['O'][j];
				break;
			}
	}
	ft = total['B'] * total['E'] * total['S'] * total['I'];
	st = total['G'] * total['O'] * total['E'] * total['S'];
	tt = total['M'] * total['O'];
	//cout << first << " " << second << " " << third << "\n";
	cout << first * st * tt + second * ft * tt + third * ft * st - first * second * tt - first * third * st - second * third * ft + first * second * third;
	return 0;
}

