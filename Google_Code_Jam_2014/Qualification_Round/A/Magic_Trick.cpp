
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{	 
	static const int SIZE = 4;
	static const int ANSWERS = 2;
	static const int MULTIPLE = -2;
	static const int NONE = -1;

	ifstream in("A-small-practice.in");
	ofstream out("A-small-practice.out");

	int testCases;
	in >> testCases;
	for (int testCase = 1; testCase <= testCases; testCase++){
		cout << "\n\nTest case: " << testCase;
		int selectedRowA;
		in >> selectedRowA;
		cout << "\nSelected rowA: " << selectedRowA;
		int gridA[SIZE][SIZE];
		for (int x = 0; x < SIZE; x++){
			cout << "\n";
			for (int y = 0; y < SIZE; y++){
				in >> gridA[x][y];
				if (x + 1 == selectedRowA){						
					cout << "[" << gridA[x][y] << "]";
				}
				else{
					cout << "|" << gridA[x][y] << "|";
				}
			}
		}	
		int selectedRowB;
		in >> selectedRowB;
		cout << "\nSelected rowB: " << selectedRowB;
		int gridB[SIZE][SIZE];
		for (int x = 0; x < SIZE; x++){
			cout << "\n";
			for (int y = 0; y < SIZE; y++){
				in >> gridB[x][y];
				if (x + 1 == selectedRowB){
					cout << "[" << gridB[x][y] << "]";
				}
				else{
					cout << "|" << gridB[x][y] << "|";
				}
			}
		}
		out << "\nCase #" << testCase << ": ";
		int sameNumber = -1;
		for (int xA = 0; xA < SIZE; xA++){			
			int a = gridA[selectedRowA - 1][xA];
			for (int xB = 0; xB < SIZE; xB++){
				int b = gridB[selectedRowB - 1][xB];
				cout << "\n" << a << "=" << b;
				if (a == b){					
					if (sameNumber == NONE){
						sameNumber = a;
					}
					else{
						sameNumber = MULTIPLE;
					}					
				}
			}			
		}
		if (sameNumber == MULTIPLE){
			cout << "\nMultiple";
			out << "Bad magician!";			
		}
		else if (sameNumber == NONE){
			cout << "\nNone";
			out << "Volunteer cheated!";
					
		}
		else{
			cout << "\n" << sameNumber;
			out << sameNumber;
		}
	}

	in.close();
	out.close();

	return 0;
}

