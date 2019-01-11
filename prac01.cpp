#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector <int> capacities ;
	vector <int> bottles;
	vector <int> fromId;
	vector <int> toId;

	capacities = {14, 35, 86, 58, 25, 62};
	bottles	   = { 6, 34, 27, 38,  9, 60};
	fromId     = { 1,  2,  4,  5,  3,  3, 1, 0};
	toId       = { 0,  1,  2,  4,  2,  5, 3, 1};

	for(int i=0; i < fromId.size(); i++){

		int f = fromId[i] ;
		int t = toId[i] ;
		int space = capacities[t]-bottles[t];

		if(space >= bottles[f]){
			int vol = bottles[f];
			bottles[t] += vol;
			bottles[f] = 0;
		} else {
			int vol = space ;
			bottles[t] += vol;
			bottles[f] -= vol;
		}

	}


	for(int i=0; i < bottles.size(); i++{
		cout << bottles[i];
		cout << " ";
	}

}
