#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	vector <int> a = {1,3,2,1,1,3};
	vector <int> mul(a.size());
	
	int result = 0;

	for(int i=0; i<a.size(); i++){
		vector <int> temp(a.size()) ;
		vector <int> sumt(a.size(), 1);
		for(int j=0; j<a.size(); j++){
			if(i==j){
				temp[j] = a[i]+1;
			} else {
				temp[j] = a[j];
			}
			//cout << temp[j] << endl;
			sumt[i] *= temp[j];
		}
		//cout << sumt[i] << endl;
		result = max(result, sumt[i]); 
	}
	
	cout << result << endl;

	return 0;
}
