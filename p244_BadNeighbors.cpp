#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BadNeighbors
{
public:
	int maxDonations(vector <int> donations)
	{
		int i;
		int ans = 0;

		int N = donations.size();
		int *dp = new int[N];
		
		for(i=0; i<N-1; i++)
		{
			dp[i] = donations[i];
			if(i>0) dp[i] = max(dp[i], dp[i-1]);
			if(i>1) dp[i] = max(dp[i], dp[i-2]+donations[i]);
			ans = max(ans, dp[i]);
		}

		for(i=0; i<N-1; i++)
		{
			dp[i] = donations[i+1];
			if(i>0) dp[i]=max(dp[i], dp[i-1]);
			if(i>1) dp[i]=max(dp[i], dp[i-2]+donations[i+1]);
			ans = max(ans, dp[i]);
		}

		delete [] dp;
		return ans;
	}
};


int main(void)
{
	vector <int> donations = {10, 3, 2, 5, 7, 8};
	
	BadNeighbors BN;
	int result = BN.maxDonations(donations);

	cout << result << endl;


	return 0;
}
