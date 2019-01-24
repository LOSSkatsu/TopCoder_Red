#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long salaries[50] = {0};

class CorporationSalary
{
public:
	long long totalSalary(vector <string> relations)
	{
		long long total = 0;
		for(int i=0; i<relations.size(); i++)
		{
			total += getSalary(i, relations);
		}

		return total;
	}

	long long getSalary(int i, vector <string> relations)
	{
		if(salaries[i]==0)
		{
			long long salary = 0;
			string relation = relations[i];

			for(int j=0; j<relation.size(); j++)
			{
				if(relation[j]=='Y'){
					salary += getSalary(j, relations);
				}
			}

			if(salary==0) salary=1;
			salaries[i] = salary;
		}
		return salaries[i];
	}
};


int main(void)
{
	vector <string> rel = {"NYNNYN",
			       "NNNNNN",
			       "NNNNNN",
			       "NNYNNN",
			       "NNNNNN",
			       "NNNYYN"};
	CorporationSalary CS;
	long long result = CS.totalSalary(rel);
	cout << result << endl;

	return 0;
}
