#include <iostream>
#include <vector>

using namespace std;

class Cryptography
{
public:
	long long encrypt(vector <int> numbers)
	{
		long long ans = 0;

		for(int i=0; i<numbers.size(); i++)
		{
			long long temp = 1;
			for(int j=0; j<numbers.size(); j++)
			{
				if(i==j){
					temp *= (numbers[j]+1);
				} else {
					temp *= numbers[j];
				}

			}
			ans = max(ans, temp);
		}

		return ans;
	}

};

int main(void)
{
	vector <int> numbers = {1000, 999, 998, 997, 996, 995};
	
	Cryptography Cryp;
	long long result = Cryp.encrypt(numbers);
	cout << result << endl;
	
	return 0;
}
