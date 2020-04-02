 #include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
	//vector<int> array = {0,1,21,33,45,45,45,45,45,45,61,71,73};
	vector<int> array = {45,45,45,45,45,45,45,45,45,45,61,71,73};
	vector<int> range;
	int target = 45;

	// Finding the lower range
	int low = 0;
	int high = array.size() - 1;
	while(low <= high)
	{
		int mid = (low + high)/2;

		if(array[mid] == target)
		{
			if(mid-1 < 0 || array[mid-1] < target)
			{
				range.push_back(mid);
				break;
			}
			else
			{
				high = mid - 1;
			}
		}
		else if(array[mid] > target)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	// Finding the upper bound
	low = 0;
	high = array.size() - 1;
	while(low <= high)
	{
		int mid = (low+high)/2;

		if(array[mid] == target)
		{
			if(mid+1 > array.size() - 1 || array[mid+1] > target)
			{
				range.push_back(mid);
				break;
			}
			else
			{
				low = mid + 1;
			}
		}
		else if(array[mid] > target)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout<<"["<<range[0]<<","<<range[1]<<"]"<<endl;
	return 0;
}



























/*
QUICK-SELECT 

int partition(vector<int> *array, int low, int high)
{
	int pivot = high;
	int i = low;
	int j = low - 1;
	for(;i < high; i++)
	{
		if(array->at(i) < array->at(pivot))
		{
			swap(array->at(i),array->at(++j));
		}
	}
	swap(array->at(++j),array->at(pivot));
	return j;
}

int quickselect(vector<int> *array, int k)
{
	int low = 0;
	int high = array->size()-1;
	while(low <= high)
	{
		int index = partition(array,low,high);
		if(index == k - 1) return array->at(index);
		else if(k -1 > index)
		{
			low = index + 1;
		}
		else
		{
			high = index - 1;
		}
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	vector<int> array = {8,5,2,9,7,6,3};
	int k;
	cout<<"Find the kth smallest integer where k is: ";cin>>k;
	cout<<"The kth smallest integer is "<<quickselect(&array,k)<<endl;
	return 0;
}
*/
