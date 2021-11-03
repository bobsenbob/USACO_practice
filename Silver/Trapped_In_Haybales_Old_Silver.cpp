/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct bale{
	int size;
	int position;
	bale(){}
	bale(int s, int p) : size(s), position(p) {}
	bool operator<(const bale &other) const{
		return position < other.position;
	}
};
vector<bale> bales;
void printV(vector<int> a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
	int N, B, r, l, speed, a, b, orr, orl, br = -INT_MAX, bl = -INT_MAX, rv = INT_MAX;
	bool escape = false;
	cin >> N >> B;
	
	bales = vector<bale>(N);
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		bales[i] = bale(a, b);
	}
	vector<int> speeds(N);
	vector<bool> access(N, false);
	sort(bales.begin(), bales.end());
	if (B > bales[bales.size() - 1].position || B < bales[0].position){
		cout << -1;
		return 0;
	}
	for (int i = 0; i < bales.size() - 1; i++){
		orr = i + 1;
		if (B > bales[i].position && B < bales[i + 1].position){
			break;
		}
	}
	orl = orr - 1;
	r = orr;
	l = orl;
	//sweep right
	for (;true;){
		//break as many left bales as possible
		for (;l >= 0 && bales[l].size < bales[r].position - bales[l].position; l--);
		if (l < 0)
			escape = true;
		if (bales[r].size >= bales[r].position - bales[l].position)
			break;
		else{
			speeds[r] = bales[r].position - bales[l].position;
			access[r] = true;
			r++;
		}
		if (r >= bales.size()){
			escape = true;
			break;
		}

	}
	r = orr;
	l = orl;
	//sweep left
	for (;true;){
			//break as many right bales as possible
		for (;r < bales.size() && bales[r].size < bales[r].position - bales[l].position; r++);
		if (r >= bales.size())
			escape = true;
		if (bales[l].size >= bales[r].position - bales[l].position)
			break;
		else{
			speeds[l] = bales[r].position - bales[l].position;
			access[l] = true;
			l--;
		}
		if (l < 0){
			escape = true;
			break;
		}

	}
	//printV(speeds);
	if (!escape)
		cout << 0;
	else{
		escape = true;
		for (int i = orr; i < bales.size(); i++)
			br = max(br, bales[i].size - bales[i].position + bales[orl].position);
		for (int i = orl; i >= 0; i--)
			bl = max(bl, bales[i].size - bales[orr].position + bales[i].position);
		//cout << br << " " << bl << "\n";
		//left ones
		for (int i = 0; i <= orl; i++)
			if (access[i] && bales[orl].position - bales[i].position <= br){
				escape = false;
				rv = min(rv, speeds[i] - bales[i].size);
			}
		//right ones
		for (int i = orr; i < bales.size(); i++){
			if (access[i] && bales[i].position - bales[orr].position <= bl){
				escape = false;
				rv = min(rv, speeds[i] - bales[i].size);
			}
		}
		if (escape)
			cout << -1;
		else
			cout << max(rv, 0);

	}
	return 0;
}

