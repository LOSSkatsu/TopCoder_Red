#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class InterestingParty
{
public:
	int bestInvitation(vector <string> first, vector <string> second)
	{

		map <string, int> dic;

		for(int i=0; i<first.size(); i++){
			dic[ first[i]] = 0;
			dic[second[i]] = 0;
		}

		for(int i=0; i<first.size(); i++){
			dic[ first[i]]++;
			dic[second[i]]++;
		}

		int ans=0;
		map <string, int>::iterator it;

		for(it=dic.begin(); it != dic.end(); it++){
			ans=max(ans, it->second);
		}
	
		return ans;
	}
};

int main(void)
{
	vector <string> first = {"fishing", "gardening", "swimming", "fishing"};
	vector <string> second = {"hunting","fishing","fishing","biting"};

	int result;
	InterestingParty Party;
	result = Party.bestInvitation(first, second);

	cout << result<< endl;



}
