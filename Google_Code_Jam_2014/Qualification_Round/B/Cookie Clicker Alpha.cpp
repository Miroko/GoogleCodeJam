
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream in("B-large-practice.in");
	ofstream out("B-large-practice.out");

	out.precision(12);
	
	int testCases;
	in >> testCases;
	for (int testCaseNumber = 1; testCaseNumber <= testCases; testCaseNumber++){
		out << "\nCase #" << testCaseNumber << ": ";
		double currentTime = 0;
		double elapsedTime = 0;
		double cookies = 0;
		double productionPerSecond = 2;
		double farmCost;
		double farmProductionPerSecond;
		double winCost;
		in >> farmCost;
		in >> farmProductionPerSecond;
		in >> winCost;
		while (cookies < winCost){
			currentTime += elapsedTime;
			cookies += (productionPerSecond * elapsedTime);
			double timeToWinIfWait = (winCost - cookies) / productionPerSecond;
			double timeToWinIfBuy = (winCost - (cookies - farmCost)) / (productionPerSecond + farmProductionPerSecond);
			if (timeToWinIfBuy < timeToWinIfWait){
				if (cookies >= farmCost){
					// Buy farm
					cookies -= farmCost;
					productionPerSecond += farmProductionPerSecond;
				}
				else{
					// Wait for enough cookies
				}
				// Next possible buy
				elapsedTime = (farmCost - cookies) / productionPerSecond;
			}
			else{
				// Wait for win
				currentTime += (timeToWinIfWait);
				break;
			}			
		}
		out << currentTime;
	}
	in.close();
	out.close();
	return 0;
}


