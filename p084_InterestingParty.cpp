#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector <string> first  = {"fishing", "gardening", "swimming", "fishing"};
	vector <string> second = {"hunting", "fishing", "fishing", "biting"};
	
	int ans = 0;
	
	for(int i=0; i<first.size(); i++){
		int f=0;
		int s=0;
		for(int j=0; j<first.size(); j++){
			if(first[i]  == first[j])  f++ ;
			if(first[i]  == second[j]) f++ ;
			if(second[i] == first[j])  s++ ;
			if(second[i] == second[j]) s++ ;
		}
		ans = max(f, ans);
		ans = max(s, ans);

	}

	
	cout << ans << endl;

	return 0;


}
