#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class NumberMagicEasy
{
	char Check(int X[], int number)
	{
		for(int x=0; x<8; x++){
			if(X[x] == number) return 'Y' ;
		}
		return 'N';
	}
public:
	int theNumber(string answer)
	{
		int A[] = {1,2,3,4,5,6,7,8};
		int B[] = {1,2,3,4,9,10,11,12};
		int C[] = {1,2,5,6,9,10,13,14};
		int D[] = {1,3,5,7,9,11,13,15};

		for(int i=1; i<=16; i++){
			if(Check(A,i) != answer[0]) continue;
			if(Check(B,i) != answer[1]) continue;
			if(Check(C,i) != answer[2]) continue;
			if(Check(D,i) != answer[3]) continue;
			
			return i;
		}

		return 0;
	}
};

int main(void)
{
	string answer = "YNNN";

	NumberMagicEasy NME ;
	int result = NME.theNumber(answer);

	cout << result  << endl;


	return 0;
}
