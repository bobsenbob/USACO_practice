/*
ID: david.w4
TASK: diamond
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	int N, K, fstart = 0, fend = 0,fmax = 0,sstart = 0, send = 0,smax = 0, rv = 0;
	cin >> N >> K;
	vector<int> diamonds(N);
	for (int i = 0; i < N; i++)
		cin >> diamonds[i];
	sort(diamonds.begin(), diamonds.end());
	for (; fend < N;) {
		//cout << diamonds[fstart] << " and " << diamonds[fend] << " " << K << (diamonds[fend] - diamonds[fstart] <= K )<< "\n";
		//check if sequence is viable
		if (diamonds[fend] - diamonds[fstart] <= K) {
			//declare length of first sequence
			fmax = fend - fstart + 1;
			send = sstart;
			//iterate for second sequence up until the beginning of the first sequence
			for (; send < fstart;) {
				//cout << "first sequence : " << diamonds[fstart] << ", " << diamonds[fend] << " second sequence: " << diamonds[sstart] << ", " << diamonds[send] << "\n";
				if (diamonds[send] - diamonds[sstart] <= K) {
					smax = max(smax, send - sstart + 1);
					send++;                     
				}
				else {
					sstart++;
				}
				rv = max(rv, fmax + smax);
				//cout << rv;
			}
			fend++;
			
		}
		else
			fstart++;
	}
	cout << rv;;
	
}

