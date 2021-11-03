/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
struct word{
	long long length;
	long long rhyme;
	word() {}
	word(long long l, long long r) : length(l), rhyme(r) {}
};
long long expo(long long base, long long exp){
	long long rv = 1;
	for (;exp > 0;){
		if (exp % 2 != 0){
			rv *= base;
			rv %= mod;
			exp--;
		}
		else{
			base *= base;
			base %= mod;
			exp /= 2;
		}

	}
	return rv % mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("poetry.in", "r", stdin); freopen("poetry.out", "w", stdout);
	long long N, M, K, a, b, rv = 1;
	char c;
	cin >> N >> M >> K;

	//ways to construct a line that is i syllables long 
	vector<long long> ways(K + 1);
	ways[0] = 1;
	//ways to construct a line that is K syllables long and ends with rhyme scheme i
	vector<long long> lines (N + 1);
	vector<word> words(N);
	vector<long long> scheme(26);
	vector<long long> pos(26);
	for (long long i = 0; i < N; i++){
		cin >> a >> b;
		words[i] = word(a, b);
	}
	for (long long i = 0; i < M; i++){
		cin >> c;
		scheme[c - 65]++;
	}
	for (long long i = 1; i <= K; i++){
		for (long long j = 0; j < N; j++){
			if (i >= words[j].length){
				ways[i] += ways[i - words[j].length];
				ways[i] %= mod;
			}
		}
	}
	for (long long i = 0; i < N; i++){
		lines[words[i].rhyme] += ways[K - words[i].length];
		lines[words[i].rhyme] %= mod;
	}
	for (long long i = 0; i < 26; i++){
		if (scheme[i] == 0){
			pos[i] = 1;
			continue;
		}
		for(long long j = 0; j <= N; j++){
				pos[i] += expo(lines[j], scheme[i]);
				pos[i] %= mod;
		}
	}
	for (long long i = 0; i < 26; i++){
		rv *= pos[i];
		rv %= mod;
	}
	cout << rv;
	return 0;
}

