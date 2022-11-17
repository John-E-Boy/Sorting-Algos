/**************************************
Template created by Kazumi Slott
CS311

Your name:
Your programmer number:
Any difficulties?:
**************************************/

#include <iostream>
using namespace std;

void swap(int& data1, int& data2)
{
  int temp = data1;
  data1 = data2;
  data2 = temp;
}

void print(const int ar[], int n)
{
  for(int i = 0; i < n; i++)
    cout << ar[i] << " ";
}


//https://www.youtube.com/watch?v=ROalU379l3U
//Implement the insertion sort by watching the above youTube video. Your algorithm has to match their dance.
void insertionSort(int ar[], int n)
{
  
  for (int j = 0; j < n; j++)
    {
      for(int i = j + 1 ; i < n; i++)
	{
	  if (ar[j] > ar[i]) 
	    {
	      swap(ar[i], ar[j]);
	    }
	}
    }

  //call swap
}


//The following function sorts the array in ascending orer by moving the largest value to the end.
//Change the code so the array gets sorted in ascending order by moving the smallest value to the beginning.
//You can find more information in my homework document
void selectionSort(int array[], int N)
{
  int small; //the index of the largest value

  //last is the last index in unsorted part
  for(int last = 0; last < N - 1; last++)
    {
      small = last; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = last + 1; i < N; i++)
	{
	  if(array[i] < array[small]) //The current item is larger
	    small = i;
	}

	//swap the largest with the last item in the unsorted part
      swap(array[small],array[last]);
    }
}


//Replace the ????s.
//For more info on bubble sort, read my CS211 lec notes "Lec notes 2-2: bubble sort"
//You could also watch my CS211 lecture recording "Lecture 2/5(Fri) - bubble sort and enum" 

void bubbleSort(int ar[], int s)
{
  bool swapped = false; //true if there was swapping in the current iteration, false otherwise                                   
  int last = s - 2; //last is the index of the left element of the last pair to be checked in the current iteration.

  while( swapped != true) //swapping required in the previous iteration or the first iteration starts                        
    {
      swapped = true; //no swapping has happened yet when a new iteration starts.                                         

      for(int i = 0 ; i <= last; i ++) //check each adjacent pair of items in the unsorted part                     
        {
	  if(ar[i] > ar[i + 1]) //the pair is out of order                                                          
	    {
	      swap(ar[i],ar[i+1]);
	      swapped = false;
	      // ????????? //swapping required - meaning we need to proceed to the next iteration.                            
	    }
        }
      last --; //the area to be checked shrinks down after each iteration                                         
    }//end of while                                                                                               
}


int partition(int a[], int start, int end)
{
  //I have 3 variables: pivot, i and swap_index. You may have any local variables.
  int pivot = end;
  int red = start;

  //For implementation of this function, refer to my lecture notes "quick sort".
  //If you used a different algorithm, I would assume you cheated and give you zero points.

  for (int green = start; green < end + 1  ; green++)
    {


      if (a[green] < a[end])
        {

          swap(a[green], a[red]); // swap if element at green is less than pivot
          red++; // advance red
        }

    }

  swap(a[red], a[pivot]);
  return red;
  //This function returns the index where the pivot value went in//copy and paste partition() from your quickSort.cpp
}

void quickSort(int ar[], int start, int end)
{
  if(start < end)//If the partition has only one element or none, return.
    {
      partition(ar, start  , end);
      //quickSort(ar, start,  partition(ar,start, end) - 1);
      quickSort(ar, partition(ar,start,end) + 1 , end);//quickSort on the left partition
      quickSort(ar, start,  partition(ar,start, end) - 1);
      return;
    }                   //In other words, if the partition has at least 2 elements, go inside the if.
  else                 //use start and end to figure out how many elements you have in the partition.
    {
      return;
    }
//copy and paste quickSort() from your quickSort.cpp   
}


void merge(int ar[], int first, int last)
{
  //copy and paste merge() from your mergeSort.cpp
  int size = (last - first)+1; // size of dynamic array
  int* temp = new int[size]; // declare new dynamic array
  int left = first;
  int mid = (first + last)/2;
  int right = mid + 1;
  int tempCount = 0;



  while (left <= mid && right <= last)
    {
      if (ar[left] > ar[right])
        {
          temp[tempCount] = ar[right]; // if right less than left put right in temp array
          right++; // progress right half
          tempCount++; // next slot of temp array
        }
      else
        {
          temp[tempCount] = ar[left];
          left++;
          tempCount++;
        }
    }


  while(right <= last)
    {
      temp[tempCount] = ar[right]; // if right less than left put right in temp array
      right++; // progress right half
      tempCount++; // next slot of temp array
    }

  while(left <= mid)
    // if right bigger than left
    {
      temp[tempCount] = ar[left];
      left++;
      tempCount++;
    }




  int arCount = 0;
  // put values into array
  for (int i = first; i <= last; i++ )
    {
      ar[i] = temp[arCount];
      arCount++;
    }

  delete[]temp;

}

void mergeSort(int ar[], int first, int last)

{
  if ( (last - first) < 1)
    {
      return;
    }
  else
    {
      int mid = (first + last)/2;
      mergeSort(ar, first, mid); // left
      mergeSort(ar, mid + 1, last); // right
      merge(ar, first, last);

    }
//copy and paste mergeSort()from your mergeSort.cpp   
}


