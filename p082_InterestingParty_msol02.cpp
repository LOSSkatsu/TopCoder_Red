#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class InterestingParty
{
public:
	int bestInvitation(vector <string> first, vector <string> second)
	{
		int result = 0;
		int n = first.size(); 
		
		for(int i=0; i<n; i++)
		{
			int f = 0;
			int s = 0;
			
			for(int j=0; j<n; j++)
			{
				if(first[i] ==  first[j]) f++;
				if(first[i] == second[j]) f++;
				if(second[i]==  first[j]) s++;
				if(second[i]== second[j]) s++;
			}
			result = max(f, result);
			result = max(s, result);
		}

		return result ;
	}
};

int main(void)
{
	vector <string> first = {"snakes", "programming", "cobra", "monty"};
	vector <string> second = {"python", "python", "anaconda", "python"};
	
	InterestingParty IP;
	int result = IP.bestInvitation(first, second);

	cout << result << endl;
}
