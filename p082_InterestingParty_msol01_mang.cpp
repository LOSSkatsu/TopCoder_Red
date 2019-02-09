#include <iostream>
#include <vector>

using namespace std;

class InterestingParty
{
public:
	int bestInvitation(vector <string> first, vector <string> second)
	{
		int result = 0;

		for(int i=0; i<first.size(); i++)
		{
			for (int j=0; j<first.size(); j++)
			{
				if(first[i]==first[j] | first[i]==second[j] )
					result += 1 ;
				if(first[i]==second[i])
					result -= 1 ;
			}
		}

		return result ;
	}

};


int main(void)
{
	vector <string> first = {"snakes", "programming", "cobra", "monty"};
	vector <string> second = {"python", "python", "anaconda", "python"};

	InterestingParty IP ;
	int result = IP.bestInvitation(first, second);

	cout << result  << endl;
}
