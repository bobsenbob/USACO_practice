/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
void printv(vector<int> a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cardgame.in", "r", stdin); freopen("cardgame.out", "w", stdout);
	int N, bessit = 0, elsit = 0, rv = 0;
	cin >> N;
	vector<int> elsief(N / 2);
	vector<int> elsiel(N / 2);
	vector<int> bessief(N / 2);
	vector<int> bessiel(N / 2);
	vector<int> bessie(0);
	vector<int> deck(2 * N);
	for (int i = 0; i < N / 2; i++){
		cin >> elsief[i];
		deck[elsief[i] - 1] = 1;
	}
	for (int i = 0; i < N / 2; i++){
		cin >> elsiel[i];
		deck[elsiel[i] - 1] = 1;
	}

	for (int i = 0; i < deck.size(); i++)
		if (!deck[i])
			bessie.push_back(i + 1);
	//split bessies deck into first(greater) half and last(lesser) half
	sort (bessie.begin(), bessie.end());
	//descending
	for (int i = 0; i < N / 2; i++)
		bessiel[N / 2 - i - 1] = bessie[i];
	//ascending
	for (int i = N / 2; i < N; i++)
		bessief[i - (N / 2)] = bessie[i];
	//first half
	sort(elsief.begin(), elsief.end());
	for (;bessit < bessief.size(); bessit++){
		if (bessief[bessit] > elsief[elsit]){
			rv++;
			elsit++;
			bessief[bessit] = 0;
		}
	}

	sort(elsiel.begin(), elsiel.end(), greater<int>());
	bessit = 0;
	elsit = 0;

	for (;bessit < bessiel.size(); bessit++){
		if (bessiel[bessit] < elsiel[elsit]){
			rv++;
			elsit++;
			bessiel[bessit] = 10000000;
		}
	}
	cout << rv;
	return 0;
}

