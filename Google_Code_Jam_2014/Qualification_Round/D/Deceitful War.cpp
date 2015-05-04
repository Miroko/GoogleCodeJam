
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

double getLightestBlock(list<double> &blocks){
	double currentLightest = blocks.front();
	for (double block : blocks){
		if (block < currentLightest){
			currentLightest = block;
		}
	}
	return currentLightest;
}

double getHeaviestBlock(list<double> &blocks){
	double currentHeaviest = blocks.front();
	for (double block : blocks){
		if (block > currentHeaviest){
			currentHeaviest = block;
		}
	}
	return currentHeaviest;
}

double getBestBlockToPlay(double blockToWin, list<double> &blocks){
	double currentBest = blocks.front();
	for (double block : blocks){
		double differenceOld = currentBest - blockToWin;
		double differenceNew = block - blockToWin;
		if (differenceOld < 0) {
			currentBest = block;
		}
		else if (differenceOld > 0 && differenceNew > 0
			&& differenceNew < differenceOld){
			currentBest = block;
		}		
	}
	if (currentBest - blockToWin < 0){
		currentBest = getLightestBlock(blocks);
	}
	return currentBest;
}

bool canPlayDeceitful(list<double> &blocksNaomi, list<double> &blocksKen){
	double lightestKen = getLightestBlock(blocksKen);
	double deceifulBlock = getBestBlockToPlay(lightestKen, blocksNaomi);
	if (deceifulBlock > lightestKen){
		return true;
	}
	else return false;
}

int main()
{
	ifstream in("D-large-practice.in");
	ofstream out("D-large-practice.out");

	int testCases;
	in >> testCases;
	for (int testCaseNumber = 1; testCaseNumber <= testCases; testCaseNumber++){
		out << "Case #" << testCaseNumber << ": ";
		cout << "Case: " << testCaseNumber;
		list<double> blocksKen;
		int winsNaomiNormal = 0;
		int winsNaomiDeceitful = 0;
		list<double> blocksNaomi;
		int numberOfBlocks;
		in >> numberOfBlocks;
		for (int i = 0; i < numberOfBlocks; i++){
			double block;
			in >> block;
			blocksNaomi.push_back(block);
		}
		for (int i = 0; i < numberOfBlocks; i++){
			double block;
			in >> block;
			blocksKen.push_back(block);
		}

		list<double> blocksKenTemp = blocksKen;
		list<double> blocksNaomiTemp = blocksNaomi;
		while (!blocksNaomiTemp.empty()){
			double blockNaomiPlays;
			double blockKenPlays;
			// Deceitful
			if (canPlayDeceitful(blocksNaomi, blocksKen)){
				// Naomi tells Ken that this block is heavier than any of his

				// Ken plays his lightest to lose as little as possible
				blockKenPlays = getLightestBlock(blocksKen);	

				// Naomi really plays a block that weights just a little more than Ken's lightest
				blockNaomiPlays = getBestBlockToPlay(blockKenPlays, blocksNaomi);
			}
			else
			{
				// Naomi's heaviest is lighter than Ken's lightest
				// So Naomi has to play normally to not get caught of cheating
				blockNaomiPlays = blocksNaomi.front();
				blockKenPlays = getBestBlockToPlay(blockNaomiPlays, blocksKen);
			}
			if (blockNaomiPlays > blockKenPlays){
				winsNaomiDeceitful++;
			}
			blocksNaomi.remove(blockNaomiPlays);
			blocksKen.remove(blockKenPlays);

			// Normal
			blockNaomiPlays = blocksNaomiTemp.front();
			blockKenPlays = getBestBlockToPlay(blockNaomiPlays, blocksKenTemp);
			if (blockNaomiPlays > blockKenPlays){
				winsNaomiNormal++;				
			}
			blocksNaomiTemp.remove(blockNaomiPlays);
			blocksKenTemp.remove(blockKenPlays);
		}
		out << winsNaomiDeceitful << " ";
		out << winsNaomiNormal << "\n";
	}

	in.close();
	out.close();
	return 0;
}



