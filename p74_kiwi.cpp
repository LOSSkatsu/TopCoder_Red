
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class KiwiJuiceEasy
{
public :
	vector <int> thePouring( vector <int> capacities,
				 vector <int> bottles,
				 vector <int> fromId,
				 vector <int> toId )
	{
		for(int i=0; i < fromId.size(); i++){
			int f = fromId[i];
			int t = toId[i];

			int vol = min(bottles[f], capacities[t]-bottles[t]);

			bottles[f] -= vol;
			bottles[t] += vol;
		}
		return bottles;
	}

};

int main(void)
{
	vector <int> a = {30, 20, 10};
	vector <int> b = {10, 5, 5};
	vector <int> c = {0, 1, 2};
	vector <int> d = {1, 2, 0};
	
	KiwiJuiceEasy Kiwi;
	vector <int> result = Kiwi.thePouring(a, b, c, d) ;

	for(int i=0; i<result.size(); i++){
		cout << result[i] << " " ;
	}

	return 0;
}
