#include <iostream>
#include <algorithm>

class AutoLoan
{
public:
	double interestRate(double price, double monthlyPayment, int loanTerm)
	{
		double balance;
		double high=100, low=0, mid=0;
		
		while((1e-9 < high-low)&&(1e-9 <(high-low)/high))
		{
			balance = price;
			mid = (high+low)/2 ;

			for(int j=0; j<loanTerm; j++)
			{
				balance *= mid/1200 + 1;
				balance -= monthlyPayment;
			}
			if(0<balance) high=mid;
			else low = mid;
		}
		return mid;
	}
};

int main(void)
{
	double price = 2000;
	double monthlyPayment = 510;
	int loanTerm = 4;
	
	AutoLoan AL ;
	double result = AL.interestRate(price, monthlyPayment, loanTerm); 

	std::cout << result << std::endl;

	return 0;
}
