#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class KiwiJuiceEasy
{
public:
	vector <int> thePouring(vector <int> capacities, 
				vector <int> bottles,
				vector <int> fromId,
				vector <int> toId)
	{
		for(int i=0; i<fromId.size(); i++)
		{
			bottles[fromId[i]] = max(0, bottles[fromId[i]]-(capacities[toId[i]]-bottles[toId[i]]));
			bottles[toId[i]] = min(capacities[toId[i]], bottles[fromId[i]]+bottles[toId[i]]);
		}
		
		return bottles;
	}
};

int main(void)
{
	vector <int> capacities = {30, 20, 10};
	vector <int> bottles    = {10,  5,  5};
	vector <int> fromId     = {0,   1,  2};
	vector <int> toId       = {1,   2,  0};
	
	KiwiJuiceEasy KJ;
	vector <int> result = KJ.thePouring(capacities, bottles, fromId, toId);
	
	for(int i=0; i<result.size(); i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}
