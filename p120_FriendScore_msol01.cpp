#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FriendScore
{
public:
	int highestScore(vector <string> friends)
	{
		int ans=0;
		int n = friends[0].length();
		
		for(int i=0; i<n; i++)
		{
			int cnt=0; 
			
			for(int j=0; j<n; j++)
			{
				if(i==j) continue; 
				
				if(friends[i][j]=='Y'){
					cnt++;
				}else{
					for(int k=0; k<n; k++)
					{
						if(friends[j][k]=='Y'&&friends[k][i]=='Y'){
							cnt++;
							break;
						}
					}
				}

			}

			ans = max(ans, cnt);
		}
		
		return ans; 
	}
};


int main(void)
{
	vector <string> friends = {"NYNNN",
				   "YNYNN",
				   "NYNYN",
				   "NNYNY",
				   "NNNYN"};
	FriendScore FS; 
	int result = FS.highestScore(friends); 
	cout << result << endl;
	
	return 0;
}
