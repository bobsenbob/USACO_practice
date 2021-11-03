/*
ID: david.w4
TASK: highcard
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	//ifstream fin("3.in");
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	int N, play, res, count = 0, Elsit = 0, Bessit = 0;
	cin >> N;
	vector<int> Elsie(N);
	vector<int> aux(2*N);
	vector<int> Bessie;
	for (int i = 0; i < N; i++) {
		cin >> Elsie[i];
		
	}
	for (int i = 0; i < N; i++) {
		aux[Elsie[i]-1] = Elsie[i];

	}
		//cout << aux[i] << " ";
	//cout << "\n";
	//assigns remaining cards to bessie, sorted
	for (int i = 0; i < 2 * N; i++) {
		//cout << "y";
		if (aux[i] == 0) {
			Bessie.push_back(i + 1);

		}
	}
			//sorted Elsie
			sort(Elsie.begin(), Elsie.end());
			for (; Bessit < Bessie.size() && Elsit < Elsie.size(); Bessit++) {
				if (Bessie[Bessit] > Elsie[Elsit]) {
					//cout << "bessie: " << Bessie[Bessit] << " elsie: " << Elsie[Elsit] << "\n";
					Bessie[Bessit] = 0;
					count++;
					Elsit++;
				}

			}
			/*for (int i = 0; i < Bessie.size(); i++)
			{
				cout << Bessie[i] << "\n";// << " " << Elsie[i] << "\n";
			}*/


			cout << count;

		}


