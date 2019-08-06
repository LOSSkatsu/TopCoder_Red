#include <iostream>
#include <string>

using namespace std; 

bool grid[100][100] = {false}; 
int vx[] = {1, -1, 0, 0};
int vy[] = {0, 0, 1, -1};
double prob[4]; 


class CrazyBot{

public:
	double getProbability(int n, int east, int west, int south, int north)
	{
		prob[0] = east / 100.0; 
		prob[1] = west / 100.0; 
		prob[2] = south / 100.0;
		prob[3] = north / 100.0; 

		return dfs(50, 50, n); 
	}

	double dfs(int x, int y, int n)
	{
		if(grid[x][y]) return 0;
		if(n==0) return 1; 
		
		grid[x][y] = true; 
		double ret = 0; 
		for(int i=0; i<4; i++)
		{
			ret += dfs(x+vx[i], y+vy[i], n-1)*prob[i];

		}
		grid[x][y] = false;
		return ret;
	}
}; 


int main()
{
	int n = 2; 
	int east = 25; 
	int west = 25; 
	int south = 25; 
	int north = 25; 
	double res; 

	CrazyBot Crazy;
	res = Crazy.getProbability(n, east, west, south, north); 
	cout << res << endl;
	return 0;
}
