#include <iostream>
#include <vector>
using namespace std;

void generate_all_subarrays(vector<int> *array, vector<vector<int>> *subarrays)
{
	int size = 0;
	while(size < array->size())
	{
		int start = 0;
		for(; start < array->size(); start++)
		{
			int end = start + size;
			if(end < array->size())
			{
				vector<int> subarray;
				for(int i = start; i <= end; i++)
				{
					subarray.push_back(array->at(i));
				}
				subarrays->push_back(subarray);
			}
		}
		size++;
	}
}

// Main
int main(int argc, char const *argv[])
{
	vector<int> array = {1,2,3,4,5};
	vector<vector<int>> subarrays;
	generate_all_subarrays(&array, &subarrays);
	for(int i = 0; i < subarrays.size(); i++)
	{
		cout<<"[ ";
		for(int j = 0; j < subarrays[i].size(); j++)
		{
			cout<<subarrays[i][j]<<" ";
		}
		cout<<"], ";
	}
	cout<<endl;
	return 0;
}
