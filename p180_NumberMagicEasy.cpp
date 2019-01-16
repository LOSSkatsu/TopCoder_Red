#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class NumberMagicEasy
{
public:
	int theNumber(string answer)
	{
		string c[] = {
			"YYYYYYYYNNNNNNNN",
			"YYYYNNNNYYYYNNNN",
			"YYNNYYNNYYNNYYNN",
			"YNYNYNYNYNYNYNYN"
		};

		for( int i=0; i<=15; i++){
			string temp = "";
			for( int j=0; j<4; j++) temp += c[j][i];
			if( answer == temp ) return i+1;
		}
		return 0;
	}
};

int main(void)
{
	string answer = "NNNN";

	NumberMagicEasy NME ;
	
	int result = NME.theNumber(answer);
	
	cout << result << endl;

	return 0;
}


