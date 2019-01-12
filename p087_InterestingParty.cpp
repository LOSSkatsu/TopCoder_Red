#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class InterestingParty
{
public:
	int bestInvitation(vector <string> first, vector <string> second)
	{
		
		int ans = 0;
		for(int i=0; i<first.size(); i++){
			int f=0;
			int s=0;
			for(int j=0; j<first.size(); j++){
				if(first[i] ==   first[j]) f++;
				if(first[i] ==  second[j]) f++;
				if(second[i] ==  first[j]) s++;
				if(second[i] == second[j]) s++;
			}
			ans = max(ans, f);
			ans = max(ans, s);
		}
		return ans;
	}
};



int main(void)
{
	vector <string> first  = {"variety", "diversity",  "loquacity", "courtesy"};
	vector <string> second = {"talking",  "speaking", "discussion",  "meeting"};
	
	InterestingParty Party;
	int result;

	result = Party.bestInvitation(first, second);
	
	
	cout << result << endl;
	
	return 0;
}
