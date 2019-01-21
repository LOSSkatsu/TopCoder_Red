#include <iostream>

using namespace std;

int dfs(int nowh, int noww)
{
	const int h=5, w=4;
	
	if(nowh > h || noww > w) return 0;
	if(nowh == h && noww == w) return 1;
	return dfs(nowh+1, noww) + dfs(nowh, noww+1);
}

int main(void)
{
	int present_h = 0;
	int present_w = 0;

	int result = dfs(present_h, present_w);

	cout << result << endl;

	return 0;
}
