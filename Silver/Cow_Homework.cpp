/*
ID: david.w4
TASK: homework
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

double mean(vector<double> scores) {
	double min = scores[0], minIndex = 0;
	double sum = 0;
	for (double i = 0; i < scores.size(); i++)
		if (scores[i] < min)
		{
			min = scores[i];
			minIndex = i;
		}
	scores[minIndex] = 0;
	for (double i = 0; i < scores.size(); i++)
		sum += scores[i];
	return sum / (scores.size() - 1);
}

int main()
{
	//ifstream fin("10.in");
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	double K = 0, current = 0;
	double currAverage = 0, average = 0, sum = 0;
	cin >> K;
	vector<double> problems(K);//Input order
	vector<double> scores;//Backwards order
	vector<double> returns;
	vector<double> sums(K);
	vector<double> mins;
	//Stores all scores into an integer vector
	for (double i = 0; i < K; i++) {
		cin >> problems[i];
	}
	
	
	//Stores all scores in reverse order into an integer vector
	for (double i = 0; i < problems.size(); i++)
	{
		scores.push_back(problems[problems.size() - 1 - i]);
	}
	sums[0] = problems[0];
	for (int i = 1; i < K; i++) {
		sums[i] = ((sums[i - 1] + problems[i]));
	}

	//for (int i = 0; i < K; i++)
	//for (int i = 0; i < K; i++)
		//cout << sums[i] << "\n";
	//Finds sum of all 
	for (int i = 0; i < scores.size(); i++)
		sum += scores[i];

	for (double i = 1; i < problems.size() - 1; i++) {
		sum -= scores[scores.size() - 1];
		scores.pop_back();
		//cout << "sum: " << sum;
		average = sum / (problems.size() - i);
		if (average > currAverage) {
			returns.clear();
			returns.push_back(i);
			currAverage = average;
		}
		else if (average == currAverage)
			returns.push_back(i);
		//cout << "avg: " << average << " curr: " << currAverage << "\n";
		//sum -= scores[scores.size() - 1];
		//scores.pop_back();
		
	}
	
	for (double i = 0; i < returns.size(); i++)
		cout << returns[i] << "\n";
	return 0;
}

