#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate_power_set(string str, string set, vector<string> *powerset, int n)
{
	
	// If we reach a point where there are no more characters in the string to consider then we add the generated set to the powerset and exit the recursion.
	if(n >= 0)
	{
		// Lets Exclude the last character and go on.
		generate_power_set(str,set,powerset,n-1);
		// Lets Include the last character and go on.
		generate_power_set(str,set+=str.at(n),powerset,n-1);
	}
	else powerset->push_back(set);
}

// Main
int main(int argc, char const *argv[])
{
	string str = "xyz";
	vector<string> powerset;
	string set = "";
	generate_power_set(str,set,&powerset,str.size()-1);
	for(auto itr = powerset.begin(); itr != powerset.end(); itr++) cout<<*itr<<" ";
	cout<<endl;
	cout<<powerset.size()<<endl;
	return 0;
}
