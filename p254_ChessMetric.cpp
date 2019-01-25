#include <iostream>
#include <vector>

using  namespace std;

long long ways[100][100][55] = {0};
int dx[] = {1, 1, 1, 0,-1,-1,-1,0, 2, 1,-1,-2,-2,-1,1,2};
int dy[] = {1, 0,-1,-1,-1, 0, 1,1,-1,-2,-2,-1, 1, 2,2,1};

class ChessMetric
{
public:
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves)
	{
		int x,y,i,j;
		int sx = start[0];
		int sy = start[1];
		int ex = end[0];
		int ey = end[1];

		ways[sy][sx][0];

		for(i=1; i<=numMoves; i++)
		{
			for(x=0; x<size; x++)
			{
				for(y=0; y<size; y++)
				{
					for(j=0; j<16; j++)
					{
						int nx = x + dx[j];
						int ny = y + dy[j];
						if(nx<0 || ny<0 || nx >= size || ny >= size)
							continue;

						ways[ny][nx][i] += ways[y][x][i-1];
					}
				}
			}
		}
		return ways[ey][ex][numMoves];
	}
};

int main(void)
{
	int size = 3;
	vector <int> start = {0,0};
	vector <int> end = {2, 2};
	int numMoves = 1;
	
	ChessMetric CM;

	long long result = CM.howMany(size, start, end, numMoves);


	return 0;
}
