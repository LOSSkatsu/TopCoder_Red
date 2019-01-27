#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class StockHistory
{
public : 
	int maximumEarnings(int initialInvestment, int monthlyContribution, vector <string> stockPrices)
	{
		int money = initialInvestment;
		int month = stockPrices.size();
		int corp = 1;
		char *s = (char *)stockPrices[0].c_str();
		while( *s++) if(*s==' ') corp++ ;
		
		int prices[50][999];
		double max=0, profit=0;
		double proportion[50] = {0};
		bool buy[50] = {false};

		for(int i=0; i<month; i++)
		{	
			string s = stockPrices[i];
			for(int j=0; j<corp; j++)
			{
				int pos = s.find(" ");
				if(pos == string::npos){
					prices[i][j] = atoi(s.c_str());
				} else {
					prices[i][j] = atoi(s.substr(0, pos).c_str());
					s = s.substr(pos+1, s.size());
				}
			}
		}

		for(int i=month-2; 0<=i; i--)
		{
			for(int j=0; j<corp; j++)
			{
				double p = 1.0*prices[month-1][j] / prices[i][j] - 1;
				if(0 < p && max < p){
					buy[i] = true;
					max = p;
					proportion[i] = p;
				}

			}

		}
		
		for(int i=0; i<month; i++)
		{
			if(buy[i]){
				profit += money*proportion[i];
				money = 0;
			}
			money += monthlyContribution;
		}
		return (int)round(profit);
	}
};

int main(void)
{
	int initialInvestment = 1000;
	int monthlycontribution = 0;
	vector <string> stockPrices = {"10 20 30", "15 24 32"};

	StockHistory SH;
	int result = SH.maximumEarnings(initialInvestment, monthlycontribution, stockPrices);
	cout << result << endl;
	return 0;
}





