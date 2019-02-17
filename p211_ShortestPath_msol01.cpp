#include <iostream>

using namespace std;

const int h=5, w=4;
int dp[h+1][w+1];

class shortPath{ 
public:
	
	int dfs(int nowh, int noww){
		if(nowh>h || noww>w) return 0;
		if(nowh==h && noww==w) return 1;
		if(dp[nowh][noww] != 0) return dp[nowh][noww];
		return dp[nowh][noww] = dfs(nowh+1, noww) + dfs(nowh, noww+1);
	}
};

int main(void)
{
	int nowh = 0;
	int noww = 0;
	
	shortPath sP;

	int result = sP.dfs(nowh, noww) ;
	cout << result <<endl;

	return 0; 
}
