/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
struct word{
	long long syllables;
	long long rhyme;
	word() {}
	word(long long s, long long r) : syllables(s), rhyme(r) {}
};
long long modPow(long long base, long long exp){
	long long rv =  1;
	for (;exp > 0;){
		if (exp % 2 == 0){
			base *= base;
			exp /= 2;
			base %= mod;
		}
		else{
			rv *= base;
			exp -=1;
			rv %= mod;
		}

	}
	return rv % mod;

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("poetry.in", "r", stdin); freopen("poetry.out", "w", stdout);
	long long N, M, K, s, r, rv = 1;
	char a;
	cin >> N >> M >> K;
	vector<long long> dp(K + 1);
	//number of ways to form a line with i syllables
	vector<long long> ends(K + 1);
	//number of ways to end a line with rhyme i;
	vector<long long> scheme(26);
	//counts repeated rhymes
	vector<long long> totends(26);
	vector<word> words(N);
	dp[0] = 1;
	for (long long i = 0; i < N; i++){
		cin >> s >> r;
		words[i] = word(s, r);
	}
	for (long long i = 0; i < M; i++){
		cin >> a;
		scheme[a - 65]++;
	}
	for (long long i = 1; i <= K; i++){
		for (long long j = 0; j < N; j++){
			if (words[j].syllables <= i){
				dp[i] += dp[i - words[j].syllables];
				dp[i] %= mod;
			}
		}
	}
	for (long long i = 0; i < N; i++){
		ends[words[i].rhyme] += dp[K - words[i].syllables];
		ends[words[i].rhyme] %= mod;
	}
	for (long long i = 0; i < 26; i++){
		if (scheme[i] == 0){
			totends[i] = 1;
			continue;
		}
		for (long long j = 1; j <= K; j++){
			totends[i] += modPow(ends[j], scheme[i]);
			totends[i] %= mod;
		}
	}
	for (long long i = 0; i < 26; i++){
		rv *= totends[i];
		rv %= mod;
	}
	cout << rv;
	return 0;
}

