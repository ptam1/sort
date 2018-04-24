#include <iostream>
using namespace std; 
// Precondition: data[first_index] through
// data[last_index] are array elements in no
// particular order. The temp array has
// locations temp[first_index] through
// temp[last_index].
// Postcondition: The elements
// data[first_index] through data[last_index]
// have been rearranged so that they are
// ordered from smallest to largest. The array
// elements temp[first_index] through
// temp[last_index] have been used as
// temporary storage and now contain a
// copy of data[first_index] through
// data[last_index].
void mergesort(int data[ ], size_t first_index, size_t last_index, int temp[ ]);

int main()
{
	cout << "Testing Merge Sort" << endl;
    cout << "The Original Array is: " << " ";
	int a[] = {3,8,5,1,4,7};
	
	for(int i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}
	int temp[6];
	mergesort(a, 0, 6, temp);
	return 0;
}


void mergesort(int data[ ], size_t first_index, size_t last_index, int temp[ ])
{
	int left_size = last_index/2;
	int right_size = last_index-left_size; 
	int *left; 
	left = new int [left_size];
	int *right;
	right = new int [right_size];
	//Store first half of data array to left subarray
	for(int i = first_index; i < left_size; i++)
	{
		left[i] = data[i];
	}
	//Store second half of data array to right subarray
	for(int i = 0; i < right_size; i++)
	{
		right[i] = data[i+(last_index/2)];
	}
	
    int temp_num = 0;	
    //Sort left subarray
	for(int i = 0; i < left_size; i++)
	{
		for(int j = i+1; j < left_size; j++)
		if(left[i+1] < left[i])
	{
		temp_num = left[i];
		left[i] = left[j];
		left[j] = temp_num;
	}
	}

	int temp_num2 = 0;
	//Sort right array
	for(int i = 0; i < right_size; i++)
	{
		for(int j = i+1; j < right_size; j++)
		if(right[i+1] < right[i])
	{
		temp_num2 = right[i];
		right[i] = right[j];
		right[j] = temp_num2;
	}
	}

   //Merge left and right arrays together
   int a = 0;
   int b = 0;
   int i = 0;
   
   //Traverse both subarrays
   while((a < left_size) && (b < right_size))
   {
      if(left[a] < right[b])
	  {
		  temp[i++] = left[a++];
	  }
	  else
	  {
		  temp[i++] = right[b++];
	  }
   }
   
   //Store remaining elements from left subarray
   while(a < left_size)
   {
	   temp[i++] = left[a++];
   }
   
   //Store remaining elements from right subarray
   while(b < right_size)
   {
	   temp[i++] = right[b++];
   }

    //Move temp contents to data array
    for(int i = 0; i < left_size+right_size; i++)
	{
		data[i] = temp[i];
	}
    //Print sorted array	
	cout << endl;
	 cout << "The Sorted Array is:" << " ";
	 for(int i = 0; i < last_index; i++)
	{
		cout << data[i] << " ";
	}

   delete [] left;
   delete [] right;
}