#include <iostream>
#include <assert.h>
using namespace std;


void InsertSort(int *array,size_t size)  
{  
	assert(array);  
	for (size_t i=1;i<size;++i)  
	{  
		int tmp=array[i];  
		int pos=i-1;  
		while (pos >= 0 && array[pos] > tmp)  
		{  
			array[pos+1]=array[pos];  
			--pos;  
		}  
		array[pos+1]=tmp;  
	}  
}

void ShellSort(int *array,size_t size)  
{  
	int gap=size;  
	while(gap > 1)  
	{  
		gap=gap/3+1;
		for (size_t i=gap;i<size;++i)  
		{  
			int tmp=array[i];  
			int pos=i-gap;  
			while (pos >= 0 && array[pos] > tmp)  
			{  
				array[pos+gap]=array[pos];  
				pos -= gap;  
			}  
			array[pos+gap]=tmp;  
		}  
	}  
}

void SelectSort(int *array , size_t size)
{
	assert(array);
	int left = 0;
	int right = size-1;
	while (left < right)
	{
		int min , max ;
		min = max= left;
		for (int i = left; i<=right ; ++i)
		{
			if(array[i]<array[min])
			{
				min = i;
			}
			if (array[i]>array[max])
			{
				max = i;
			}
			swap(array[left],array[min]);
			if (left = max)
			{
				max = min ;
			}
			swap(array[right],array[max]);
			++left;
			++right;
		}
	}
}

void quickSort(int *array, int left, int right)  
{  
	if (left< right)  
	{        
		int i = left, j = right, x = array[left];  
		while (i < j)  
		{  
			while(i < j && array[j]>= x)
				j--;   
			if(i < j)  
				array[i++] = array[j];  
			while(i < j && array[i]< x)
				i++;   
			if(i < j)  
				array[j--] = array[i];  
		}  
		array[i] = x;  
		quickSort(array, left, i - 1);
		quickSort(array, i + 1, right);  
	}  
}

void _MergeSort(int *array, int *tmp , int left , int right)
{
	if (left>right)
	{
		return ;
	}
	int mid = (left/2)+(right/2);
	if (left < mid)
	{
		_MergeSort(array,tmp,left,mid);
	}
	if (mid+1 < right)
	{
		_MergeSort(array,tmp,mid+1,right);
	}
	int index = left;
	int begin1=left , end1 = mid;
	int begin2=mid+1, end2 = right;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1]<array[begin2])
		{
			tmp[index++] = array[begin1++];
		}
		else
		{
			tmp[index++] = array[begin2++];
		}
	}
	while (begin1<=end1)
	{
		tmp[index++] = array[begin1++];
	}
	while (begin2<=end2)
	{
		tmp[index++] = array[begin2++];
	}
	for (int i = left ; i<= right ; ++i)
	{
		array[i] = array[i];
	}
}

void MergeSort(int*array , int size)
{
	assert(array);
	int left=0;
	int right=size-1;
	if ((right-left)>=15)
	{
		int *tmp= new int[size];
		_MergeSort(array,tmp,0,size-1);
		delete[] tmp;
	}
	else
	{
		InsertSort(array,(right-left));//
	}
}



void print(int *array , size_t size)
{
	for (size_t i=0;i<size;++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}



int main ()
{
	int array[] = {3,2,1,4,6,5,9,7,8};
	size_t size = sizeof(array)/sizeof(array[0]);
	InsertSort(array,size);
	print(array,size);
	ShellSort(array,size);
	print(array,size);
	//SelectSort(array,size);
	//print(array,size);
	quickSort(array,0,size-1);
	print(array,size);
	MergeSort(array,size);
	print(array,size);

	system("pause");
}