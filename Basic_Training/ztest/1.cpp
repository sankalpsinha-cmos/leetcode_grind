#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate_all_subarrays(string *str, vector<string> *subarrays)
{
	int size = 0;
	while(size < str->size())
	{
		int start = 0;
		for(; start < str->size(); start++)
		{
			int end = start + size;
			if(end < str->size())
			{
				string subarray;
				for(int i = start; i <= end; i++)
				{
					subarray += str->at(i);
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
	string str = "abc";
	vector<string> subarrays;
	generate_all_subarrays(&str, &subarrays);
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
