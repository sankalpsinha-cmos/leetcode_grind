#include <iostream>
#include <vector>

using namespace std;

class Sorting{
	public:
/*--------------------------------------------------------------*/
	// Swapper
	void swap(int *a, int *b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}
/*--------------------------------------------------------------*/
	// Printer
	void printer(vector<int> *array)
	{
		for(auto itr = array->begin(); itr != array->end(); itr++) cout<<*itr<<" ";
		cout<<endl;
	}
/*--------------------------------------------------------------*/
	// Bubble Sort
	void bubble_sort(vector<int> *array)
	{
		cout<<"Input Array"<<endl;
		printer(array);
		cout<<"Running Buuble Sort"<<endl;
		for(int i = array->size(); i >= 0; i--)
		{
			for(int j = 1; j < i; j++)
			{
				if(array->at(j-1) > array->at(j)) swap(&array->at(j-1),&array->at(j));
			}
		}
	}
/*--------------------------------------------------------------*/
	// Insertion Sort
	void insertion_sort(vector<int> *array)
	{
		cout<<"Input Array"<<endl;
		printer(array);
		cout<<"Running Insertion Sort"<<endl;
		int i = 1;
		while(i < array->size())
		{
			int key = array->at(i);
			int j = i - 1;
			while(j >= 0 && array->at(j)> key)
			{
				array->at(j+1) = array->at(j);
				j--;
			}
			array->at(j+1) = key;
			i++;
		}
	}
/*--------------------------------------------------------------*/
	// Selection Sort
	void selection_sort(vector<int> *array)
	{
		cout<<"The Input Array"<<endl;
		printer(array);
		cout<<"Running Selection Sort"<<endl;
		quick_sort(array,0,array->size()-1);
		for(int i = 0; i < array->size(); i++)
		{
			int smallest = i;
			for(int j = i; j < array->size(); j++)
			{
				if(array->at(j) < array->at(smallest)) smallest = j;
			}
			swap(&array->at(smallest),&array->at(i));
		}
	}

/*--------------------------------------------------------------*/
	//Quick Sort
	int partition(vector<int> *array, int low, int high)
	{
		int pivot_idx = high;
		int i = low;
		int j = low - 1;
		while(i < high)
		{
			if(array->at(i) <= array->at(pivot_idx))
			{
				swap(&array->at(i), &array->at(++j));
			}
			i++;
		}
		swap(&array->at(++j),&array->at(pivot_idx));
		return j;
	}

	void quick_sort(vector<int> *array, int low, int high)
	{
		if(low < high)
		{
			int pivot_idx = partition(array,low,high);
			quick_sort(array,low,pivot_idx - 1);
			quick_sort(array, pivot_idx + 1, high);
		}
	}
	void quick_sort_caller(vector<int> *array)
	{
		cout<<"The Input Array"<<endl;
		printer(array);
		cout<<"Running Quick Sort"<<endl;
		quick_sort(array,0,array->size()-1);
	}
/*--------------------------------------------------------------*/
	// Merge Sort
	void merge(vector<int> *array, int low, int mid, int high)
	{
		int las = mid - low + 1;
		int ras = high - mid;
		int L[las], R[ras];
		for(int i = 0; i < las; i++) L[i] = array->at(low+i);
		for(int i = 0; i < ras; i++) R[i] = array->at(mid+1+i);
		int i = 0;
		int j = 0;
		int k = low;
		while(i < las && j < ras)
		{
			if(L[i] < R[j])
			{
				array->at(k) = L[i];
				i++;
			}
			else
			{
				array->at(k) = R[j];
				j++;
			}
			k++;
		}
		while(i < las)
		{
			array->at(k) = L[i];
			i++;
			k++;
		}
		while(j < ras)
		{
			array->at(k) = R[j];
			j++;
			k++;
		}
	}
	void merge_sort(vector<int> *array, int low, int high)
	{
		if(low < high)
		{
			int mid = (low + high)/2;
			merge_sort(array,low,mid);
			merge_sort(array,mid+1,high);
			merge(array,low,mid,high);
		}
	}
	void merge_sort_caller(vector<int> *array)
	{
		cout<<"The Input Array"<<endl;
		printer(array);
		cout<<"Running Merge Sort"<<endl;
		merge_sort(array,0,array->size()-1);
	}
/*--------------------------------------------------------------*/
	// Heap_Sort
	void siftUp(vector<int> *array, int index, int end)
	{
		int left = 2*index + 1;
		int right = 2*index + 2;
		int largest = index;
		if(left <= end && array->at(left) > array->at(largest)) largest = left;
		if(right <= end && array->at(right) > array->at(largest)) largest = right;
		if(largest != index)
		{
			swap(&array->at(largest), &array->at(index));
			siftUp(array,largest,end);
		}
	}

	void remove(vector<int> *array, int size)
	{
		swap(&array->at(0), &array->at(size));
		siftUp(array,0,--size);
	}

	void build_heap(vector<int> *array)
	{
		for(int i = array->size()/2 - 1; i >= 0; i --)
		{
			siftUp(array,i,array->size()-1);
		}
	}
	void heap_sort(vector<int> *array)
	{
		int size = array->size()-1;
		build_heap(array);
		while(size >= 0)
		{
			remove(array,size);
			size--;
		}
	}
	void heap_sort_caller(vector<int> *array)
	{
		cout<<"The Input Array"<<endl;
		printer(array);
		cout<<"After Heap Sort"<<endl;
		heap_sort(array);
	}
};

/*--------------------------------------------------------------*/
// Main
int main(int argc, char const *argv[])
{
	vector<int> array = {8,9,7,10,4,5,6,1,2,3};
	Sorting s;
	s.selection_sort(&array);
	s.printer(&array);
	return 0;
}
