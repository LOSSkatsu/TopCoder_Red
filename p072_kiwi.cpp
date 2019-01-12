#include <vector>
#include <iostream> 

using namespace std;

class KiwiJuiceEasy
{
public:
	vector <int> thePouring(vector <int> capacities,
				vector <int> bottles,
				vector <int> fromId,
				vector <int> toId)
	{	
		for( int i=0; i< fromId.size(); i++){
			int f = fromId[i];
			int t = toId[i];
			int space = capacities[t] - bottles[t];

			if(space >= bottles[f]){
				int vol = bottles[f];
				bottles[t] += vol;
				bottles[f] = 0;
			} else {
				int vol = space;
				bottles[t] += vol;
				bottles[f] -= vol;
			}
		}

		return bottles;
	}

};


int main(void)
{
	vector <int> a = {10, 10};
	vector <int> b = { 5,  8};
	vector <int> c = { 0};
	vector <int> d = { 1};
	
	KiwiJuiceEasy Kiwi;
	vector <int> result = Kiwi.thePouring(a,b,c,d);

	for(int i=0; i < result.size(); i++){
		cout << result[i];
		cout << " ";
	}
	
	return 0;

}
