/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
string s, t;
void remove(int start){
	size_t a = s.find(t, start);
	if (a != string::npos){
		s.erase(a, t.length());
		remove(a - t.length());
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("censor.in", "r", stdin); freopen("censor.out", "w", stdout);
	int start = 0;
	size_t found;
	cin >> s >> t;
	for (;s.length() > t.length();){
		if (s.find(t) != string::npos)
			remove(0);
		else
			break;
	}
	cout << s;
	return 0;
}

