// Blocked Billboard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int getArea(int board[]) {
	int area = 0;
	int x = (board[2] - board[0]);
	int y = (board[3] - board[1]);
	if (x < 0 || y < 0)
		x = 0;
	area = x * y;
	if (area < 0)
		area = 0;
	return area;
}
int overlap(int billboard[], int blockboard[]) {
	int area = 0;
	int leftBound = max(billboard[0], blockboard[0]);
	int rightBound = min(billboard[2], blockboard[2]);
	int lowerBound = max(billboard[1], blockboard[1]);
	int upperBound = min(billboard[3], blockboard[3]);
	int bounds[] = { leftBound, lowerBound, rightBound, upperBound };
	area = getArea(bounds);

	return area;
}
int main()
{
	ifstream fin("3.in");
	ofstream fout("billboard.out");
	int billboardA[4];
	int billboardB[4];
	int blockboard[4];
	for (int i = 0; i < 4; i++) {
		fin >> billboardA[i];
	}
	for (int i = 0; i < 4; i++) {
		fin >> billboardB[i];
	}
	for (int i = 0; i < 4; i++) {
		fin >> blockboard[i];
	}
	int totalArea = getArea(billboardA) + getArea(billboardB);
	totalArea -= overlap(billboardA, blockboard);
	totalArea -= overlap(billboardB, blockboard);
	cout << totalArea;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
