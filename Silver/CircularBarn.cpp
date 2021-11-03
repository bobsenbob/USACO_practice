/*
ID: david.w4
TASK: cbarn
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct Cow {
	int position;
	int travelled;
	Cow() : position(0), travelled(0){}
	Cow(int pos, int distance) : position(pos), travelled(distance) {}
};
bool sortByPosition(const Cow& a, const Cow& b) {
	return a.position < b.position;
}
int nextIndex(int a, int N) {
	a++;
	if (a >= N)
		a = 0;
	return a;
}
int main()
{
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	long long N, rv = 0;
	cin >> N;
	bool linedUp = false;
	vector<queue<Cow>> barn(N);
	for (int i = 0; i < N; i++) {
		int cows;
		cin >> cows;
		for (int j = 0; j < cows; j++)
			barn[i].push(Cow(i, 0));
	}
	//for (int i = 0; i < barn.size(); i++)
		//cout << barn[i].size() << "\n";
	for (;!linedUp;) {
		linedUp = true;
		for (int j = barn.size() - 1; j >= 0; j--) {
			//cout << j << "\n";
			//if the next room is empty
			//cout << nextIndex(j, N);
			if (barn[nextIndex(j, N)].size() == 0 && barn[j].size() != 0)
			{
				//cows are out of order
				linedUp = false;
				//increase distance of moved cow
				barn[j].front().travelled++;
				//move to next room
				barn[nextIndex(j, N)].push(barn[j].front());
				barn[j].pop();
				
				
			}
			//for (int i = 0; i < barn.size(); i++)
				//cout << barn[i].size() << "\n";
		}
		
	}
	for (int i = 0; i < barn.size(); i++)
		rv += barn[i].front().travelled * barn[i].front().travelled;
	cout << rv;
	return 0;
}

