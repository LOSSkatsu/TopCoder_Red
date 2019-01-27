#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

class ColorfulBoxesAndBalls
{
public : 
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int ans = INT_MIN;
		int change = min(numRed, numBlue);

		for(int i=0; i<=change; i++)
		{
			int myscore = (numRed - i) * onlyRed + (numBlue - i) * onlyBlue + 2*i*bothColors;

			ans = max(ans, myscore);
		}

		return ans;
	}
};

int main(void)
{
	int numRed = 5;
	int numBlue = 5;
	int onlyRed = 464;
	int onlyBlue = 464;
	int bothColors = 464;

	ColorfulBoxesAndBalls CB;
	
	int result = CB.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);

	cout << result << endl;

	return 0;
}
