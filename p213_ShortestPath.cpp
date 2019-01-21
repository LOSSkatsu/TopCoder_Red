#include <iostream>

using namespace std;

int calc(int h, int w)
{
	
	int dp[h+1][w+1];

	dp[0][0] = 1;
	for(int i=0; i<=h; i++)
	{
		for(int j=0; j<=w; j++)
		{
			if(i != 0) dp[i][j] += dp[i-1][j];
			if(j != 0) dp[i][j] += dp[i][j-1];
		}
	}
	
	return dp[h][w];
}


int main(void)
{
	int h = 5;
	int w = 4;

	int result = calc(h, w);
	cout << result << endl;

	return 0;
}
