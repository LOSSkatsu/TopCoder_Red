#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cryptography
{
public:
	long long encrypt(vector <int> numbers)
	{
		long long result = 1;
		int n = numbers.size();

		for(int i=0; i<n; i++)
		{
			long long temp_max = 1;
	
			for(int j= 1; j<n; j++)
			{	
				if(i==j){
					temp_max *= numbers[j]+1 ;
				}else{
					temp_max *= numbers[j]; 
				}
			}

			result = max(temp_max, result);
		}

		return result ;
	}
};

int main(void)
{
	vector <int> num = {1,3,2,1,1,3};

	Cryptography CG;
	
	long long result = CG.encrypt(num);

	cout << result << endl;
}
