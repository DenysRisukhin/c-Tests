//
//  Searching.h
//  Test2019
//
//  Created by Denys Risukhin on 9/24/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <list>
#include <set>
#include <map>
#include <iomanip>
#include <exception>

using namespace std;

// overall time complexity

#pragma mark - quickSort     O(n log(n))                квазилинейная
#pragma mark - boubleSort    O(n^2)                     полиномиальная
#pragma mark - mergeSort     O(n log(n))                квазилинейная
#pragma mark - recursion     O(m^n)                     экспоненциальная
#pragma mark - Heap Sort     O(n log(n))                квазилинейная (in - place algorith)



//Conquer (властвуй)
//enormously (чрезвычайно)
//denoting (обозначает)
//average (средний)
//Auxiliary (вспомогательный)

// Time Complexity - Big O

// Auxiliary (Уг_зєлєр_!иии) Space
// Is the extra space or temporary space used by an algorithm.

// Space Complexity of an algorithm
// Is total space taken by the algorithm with respect
// to the input size. Space complexity includes both
// Auxiliary space and space used by input.

// Example
// if we want to compare standard sorting algorithms on
// the basis of space, then Auxiliary Space would be a
// better criteria than Space Complexity.
// MSort uses O(n) auxiliary space, Insertion sort and
// Heap Sort use O(1) auxiliary space.
// Space complexity of all these sorting algorithms is O(n) though.

link----> https://www.geeksforgeeks.org/quick-sort/

#pragma mark - quickSort

// Auxiliary Space: O(log(n))
// Big O
//            average: O(n log(n))
//            worst  : O(n^2)
// Description.
// Like MSort, QSort is a Divide and Conquer algorithm.
// It picks an element as pivot and partitions the given array
// around the picked pivot.
// Versions of QSort that pick pivot in different ways:
//  - always pick first element as pivot;
//  - always pick last element as pivot;
//  - pick random element as pivot;
//  - pick median as pivot;

// The key process in QSort is partition().
// Partitions Target: given an array
// and an element x of array as pivot, put x at
// its correct position in sorted array and
// put all smaller elements (smaller than x)
// before x, and put all greater
// elements (greater than x) after x.
// All this should be done in linear time.

// Usage
// 1. For sorting Arrays
// For arrays, MergeSort loses due to the use of
// extra O(N) storage space.
// QSort is an in-place sort (doesn’t require
// any extra storage)
// MSort requires O(N) extra storage,
// N - expensive array size.
// Allocating & de-allocating the extra
// space used for MSort increases the
// running time of the algorithm.
// Comparing average complexity we find that
// both type of sorts have O(NlogN)
// average complexity
// but the constants differ.


//link----> https://www.geeksforgeeks.org/merge-sort/

#pragma mark - Merge Sort
// Big O            : O(n log(n)) in all 3 cases
// Space Complexity : O(n)
// Auxiliary Space  : O(n)

// Big O = O(nLog(n)) because MSort always divides
// the array in two halves and take linear
// time to merge two halves.

// MSort is a Divide and Conquer algorithm.
// It divides input array in two halves,
// calls itself for the two halves and then merges
// the two sorted halves. The merge() function is
// used for merging two halves. The merge(arr, l, m, r)
// is key process that assumes that arr[l..m] and arr[m+1..r]
// are sorted and merges the two sorted sub-arrays into one

// Usage:
// 1. Useful for sorting linked lists in O(nLogn) time.
//    In case of linked lists the case is different
//    mainly due to difference in memory allocation of
//    arrays and linked lists.
// Unlike arrays, linked list nodes may not be adjacent
// in memory.

// Unlike array, in linked list, we can insert items in
// the middle in O(1) extra space and O(1) time. Therefore
// merge operation of merge sort can be implemented without
// extra space for linked lists.

// In arrays, we can do random access as elements are
// continuous in memory. Let us say we have an integer
// (4-byte) array A and let the address of A[0] be x then
// to access A[i], we can directly access the memory at (x + i*4).

// Unlike arrays, we can not do random access in linked list.
// Quick Sort requires a lot of this kind of access.
// In linked list to access i’th index, we have to travel
// each and every node from the head to i’th node as we
// don’t have continuous block of memory. Therefore,
// the overhead increases for quick sort. Merge sort accesses
// data sequentially and the need of random access is low.

// 2. Inversion Count Problem
// 3. Used in External Sorting

// https://www.geeksforgeeks.org/heap-sort/

#pragma mark - Heap Sort
// Big O            : O(n log(n)) in all 3 cases
// Space Complexity : O(nLogn)
// Auxiliary Space  : O(1)

// Weakness  :   has limited uses because Quicksort
//               and Mergesort are better in practice.
// Advantages:   is enormously used.

//Its typical implementation is not stable, but can be made stable

// To heapify a subtree rooted with
// node i - index in arr[].
// n - size of heap

//Time complexity of heapify             : O(Logn)
//Time complexity of createAndBuildHeap(): O(n)
//overall time complexity                : O(nLogn)


// [45, 55, 2, 76]

//Explanation
//1. Building the Max-Heap:
//
//We start from the last non-leaf node and move upwards, calling heapify on each node. This ensures that all subtrees are max-heaps.

//Step 1: Max-heapify sub-tree rooted at index 1:

    //When we build a binary heap, we use a complete binary tree representation, which ensures that all levels are filled from left to right. This means we add elements level by level, filling each level from left to right before moving to the next level.

//       45
//      /  \
//    55    2
//   /
//  76
//Max-heap after step 1:
//       45
//      /  \
//    76    2
//   /
//  55
//
//Step 2: Max-heapify sub-tree rooted at index 0:
//       45
//      /  \
//    76    2
//   /
//  55
//Max-heap after step 2:
//       76
//      /  \
//    45    2
//   /
//  55

//2. Heapifying:
//
// The heapify function compares the node with its left and right children and ensures the largest element is at the root of the subtree. If the root is not the largest, it swaps with the largest child and recursively heapifies the affected subtree.

//3. Extracting Elements:
//
// After building the max-heap, we repeatedly swap the root (largest element) with the last element in the heap and reduce the heap size by one.
// We then call heapify on the root to ensure the remaining elements still form a max-heap.

//Step 1: Swap root (76) with last element (55), heapify:

//       76
//      /  \
//    45    2
//   /
//  55

//Array: [55, 45, 2, 76]
//Max-heap after heapify:
//       55
//      /  \
//    45    2
//
//Step 2: Swap root (55) with second last element (2), heapify:
//       2
//      /  \
//    45    55
//Array: [2, 45, 55, 76]
//Max-heap after heapify:
//       45
//      /
//     2
//
//Step 3: Swap root (45) with last element (2), heapify:
//Array: [2, 45, 55, 76]
//Max-heap after heapify:
//       2
//

#pragma mark - boubleSort

// Big O
//            average  : O(n^2)
//            worst    : O(n^2)
//           best     : O(n)
// Worst case occurs when array is reverse sorted.
// Best case occurs when array is already sorted.

// Space Complexity : O(n)
// Auxiliary Space  : O(1)

// Boundary Cases: Bubble sort takes minimum time
// (Order of n) when elements are already sorted.

// Usage:
// In computer graphics it is popular
// for its capability to detect a very small error
// (like swap of just two elements) in almost-sorted
// arrays and fix it with just linear complexity (2n).
// For example, it is used in a polygon filling algorithm,
// where bounding lines are sorted by their x coordinate
// at a specific scan line (a line parallel to x axis)
// and with incrementing y their order changes (two elements
// are swapped) only at intersections of two lines

//https://www.geeksforgeeks.org/selection-sort/

#pragma mark - Selection Sort

// Big O          : O(n^2) in all 3 cases
// Auxiliary Space: O(1)

// Advantages: never makes more than O(n) swaps
// and can be useful when memory write is a costly
// operation.

//https://www.geeksforgeeks.org/stable-selection-sort/

#pragma mark - Selection Stable Sort
// Selection sort can be made Stable if instead
// of swapping, the minimum element is placed in
// its position without swapping i.e. by placing
// the number in its position by pushing every
// element one step forward.

//https://www.geeksforgeeks.org/insertion-sort/

#pragma mark - Insertion Sort

// Big O
//            average  : O(n^2)
//            worst    : O(n^2)
//           best     : O(n)

// Space Complexity :
// Auxiliary Space  : O(1)

// Boundary Cases : Insertion sort takes maximum
// time to sort if elements are sorted in reverse order.

// And it takes minimum time(Order of n) when elements
// are already sorted.
// Stable : Yes

// Usage:
// Used when number of elements is small.
// It can also be useful when input array is
// almost sorted, only few elements are misplaced
// in complete big array.

#pragma mark - Binary Insertion Sort
// We can use binary search to reduce the number
// of comparisons in normal insertion sort.
// Binary Insertion Sort uses binary search to find
// the proper location to insert the selected item
// at each iteration. In normal insertion, sorting
// takes O(n) (at i-th iteration) in worst case.
// We can reduce it to O(log(n)) by using binary search.
// The algorithm, as a whole, still has a running worst
// case running time of O(n2) because of the series of
// swaps required for each insertion.

/////////////////////////////////////////

#pragma mark - mergeSort ###########################################################################################

void mergeSort(int* _arr, int* _helperArray, int _lowID, int _middleID, int _hightID)
{
    // step 1
    for (int i = _lowID; i <= _hightID; i++)
        _helperArray[i] = _arr[i];

    // step 2
    int helperLeftID = _lowID;
    int helperRightID = _middleID + 1;
    int currentID = _lowID;

    // step 3
    // let's do the copy from _helperArray to _arr
    while (helperLeftID <= _middleID && helperRightID <= _hightID)
    {
        if (_helperArray[helperLeftID] <= _helperArray[helperRightID])
        {
            _arr[currentID] = _helperArray[helperLeftID];
            
            helperLeftID++;
        }
        else
        {
            _arr[currentID] = _helperArray[helperRightID];
            
            helperRightID++;
        }
        
        currentID++;
    }

    // step 4
    int remaning = _middleID - helperLeftID;

    // step 5
    for (int i = 0; i <= remaning; i++)
        _arr[currentID + i] = _helperArray[helperLeftID + i];
}

void mergeSort(int * _arr, int * _helper, int _low, int _hight)
{
    if (_low < _hight)
    {
        int middleID = (_low + _hight) / 2;

        cout << "sort left side" << "   _low: " << _low << "   _hight: " << _hight << endl;
        mergeSort(_arr, _helper, _low, middleID); // sort left side

        cout << "sort right side" << "  _low: " << _low << "   _hight: " << _hight << endl;

        mergeSort(_arr, _helper, middleID + 1, _hight); // sort right side

        cout << "merge" << endl;

        mergeSort(_arr, _helper, _low, middleID, _hight); // merge
    }
    else
        cout << endl << "recursion has finished" << endl << endl;
}

void mergeSort(int * _arr, int _size)
{
    int* helperArr = new int[_size];

    mergeSort(_arr, helperArr, 0, _size - 1);

    if (helperArr)
    {
        delete[] helperArr;
        helperArr = NULL;
    }
}

#pragma mark - boubleSort ###########################################################################################

void swap(int & a,
          int & b)
{
    int t = a;
    a = b;
    b = t;
}

void boubleSort(int * _arr,
                int _size)
{
    for (int i = 0; i < _size; i++)
        for (int j = 0; j < _size - i - 1; j++)
            if (_arr[j] > _arr[j + 1])
                swap(_arr[j], _arr[j + 1]);
}

#pragma mark - quickSort Sort ###########################################################################################

// [45, 55, 2, 76, 99, 4, 12]

int processing(int * _array, int _l, int _h) {
    int pivot = _array[(_l + _h) / 2];
    
    while (_l <= _h)
    {
        while (_array[_l] < pivot) // decrease >
            _l++;
        
        while (pivot < _array[_h]) // decrease <
            _h--;
        
        if (_l <= _h)
        {
            swap(_array[_l], _array[_h]);
            _l++;
            _h--;
        }
    }

    return _l;
}

void quickSort(int * _array, int _l, int _h) {
    int index = processing(_array, _l, _h);
    
    if (_l < index - 1)
        quickSort(_array, _l, index - 1);
    
    if (index < _h )
        quickSort(_array, index, _h);
}

#pragma mark - Selection Sort ###########################################################################################

void selectionSort(int *arr, int n) {
    int i = 0;
    int j = 0;
    int min_idx = 0;
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
    
}

#pragma mark - Selection Stable Sort ###########################################################################################

void selectionStableSort(int *arr, int size) {
    // Iterate through array elements
    for (int i = 0; i < size - 1; i++)
    {
        // Loop invariant : Elements till a[i - 1] are already sorted.

        // Find minimum element from arr[i] to arr[n - 1].
        int min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }

        // Move minimum element at current i.
        int value = arr[min_idx];
        while (min_idx > i)
        {
            arr[min_idx] = arr[min_idx - 1];
            min_idx--;
        }
        arr[i] = value;
    }
}

#pragma mark - Insertion Sort ###########################################################################################

//                  [23, 1, 10, 5, 2]
//                      |
//                  [1, 23, 10, 5, 2]
//                      |
//                  [1, 10, 23, 5, 2]
//                      |
//                  [1, 5, 10, 23, 2]
//                      |
//                  [1, 2, 5, 10, 23]

void insertionSort(int* arr, int size)
{
    int i, j;
    int keyValue = 0;

    for (i = 1; i < size; i++)
    {
        keyValue = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead (вперед) of their current position */

        while (j >= 0 && arr[j] > keyValue)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = keyValue;
    }
}

#pragma mark - Heap Sort ###########################################################################################

void heapify(int* array, int heapSize, int rootIndex)
{
    int largestIndex = rootIndex;  // Initialize largest as root
    int leftChildIndex = 2 * rootIndex + 1;  // Left child
    int rightChildIndex = 2 * rootIndex + 2;  // Right child

   
    // Ensure leftChildIndex is within bounds before accessing
    if (leftChildIndex < heapSize) {
           cout << "Left child value: " << array[leftChildIndex] << endl;
            // If left child is larger than root
           if (array[leftChildIndex] > array[largestIndex])
               largestIndex = leftChildIndex;
       }

    // Ensure rightChildIndex is within bounds before accessing
    if (rightChildIndex < heapSize) {
        cout << "Right child value: " << array[rightChildIndex] << endl;\
        // If right child is larger than largest so far
        if (array[rightChildIndex] > array[largestIndex])
            largestIndex = rightChildIndex;
    }

    // If largest is not root
    if (largestIndex != rootIndex)
    {
        swap(array[rootIndex], array[largestIndex]);

        cout << "recursion" << endl;
        // Recursively heapify the affected sub-tree
        heapify(array, heapSize, largestIndex);
    }
    else
    {
        cout << "stop recursion" << endl;
    }
}

void heapSort(int* array, int size)
{
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        cout << "+" << endl;
        heapify(array, size, i);
    }

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--)
    {
        // Move current root to end
        swap(array[0], array[i]);

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

#pragma mark - Radix Sort
// runtime of 0(kn)
//where n is the number of elements and k is the number of passes of the sorting algorithm.
//    Radix Sort is a linear sorting algorithm that sorts elements by processing them digit by digit. It is an efficient sorting algorithm for integers or strings with fixed-size keys.

//Radix sort is a sorting algorithm for integers (and some other data types) that takes advantage of the fact that integers have a finite(конечный) number of bits. In radix sort, we iterate through each digit of the number, grouping numbers by each digit. For example, if we have an array of integers, we might first sort by the first digit, so that the Os are grouped together. Then, we sort each of these groupings by the next digit. We repeat this process sorting by each subsequent digit, until finally the whole array is sorted.
//Unlike comparison sorting algorithms, which cannot perform better than O(n log(n)) in the average(средний) case, radix sort has a runtime of 0( kn)

//int arr[]{170, 45, 75, 90, 802, 24, 2, 66};


// A utility function to get maximum
// value in arr[]
int getMax(int* arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

//getOccurrenceID(arr[i], exp) extracts the digit at the current exp place value (units, tens, hundreds, etc.) from arr[i]. For example, if exp is 10 (tens place), getOccurrenceID(802, 10) returns 0.
int getOccurrenceID(const int val, const int exp)
{
    const int delta = val / exp;
    const int occurrenceID = delta % 10;
    
    return occurrenceID;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(int* arr, int size, int exp)
{
    // Output array
    int output[size];

    int i = 0;
    int count[10] = { 0 };

    // 1. Store count of occurrences (вхождение)
    // in count[]
    // count: [0, 1, 2, 1, 1, 0, 1, 0, 1, 0]
//    This means:
//
//    0 occurs 0 times
//    1 occurs 1 time
//    2 occurs 2 times
//    3 occurs 1 time
//    4 occurs 1 time
//    5 occurs 0 times
//    6 occurs 1 time
//    7 occurs 0 times
//    8 occurs 1 time
//    9 occurs 0 times
    for (i = 0; i < size; i++)
    {
        const int occurrenceID = getOccurrenceID(arr[i], exp);
        count[occurrenceID]++;
    }

    // 2. Cumulative(Накопительный) Count Array: The cycle updates the count array to reflect the cumulative count, which represents the position of the digit in the output array.
    // Change count[i], so that count[i] now contains actual position of this digit in output[]

//    The cycle converts the count array from a simple count of occurrences to a cumulative count, which reflects the positions of digits in the sorted order. This step is essential for correctly placing the elements in the output array during the counting sort phase of Radix Sort.


//    After each iteration, the count array gets updated as follows:
//
//    i = 1: count[1] = count[1] + count[0] -> [0, 1, 2, 1, 1, 0, 1, 0, 1, 0]
//    i = 2: count[2] = count[2] + count[1] -> [0, 1, 3, 1, 1, 0, 1, 0, 1, 0]
//    i = 3: count[3] = count[3] + count[2] -> [0, 1, 3, 4, 1, 0, 1, 0, 1, 0]
//    i = 4: count[4] = count[4] + count[3] -> [0, 1, 3, 4, 5, 0, 1, 0, 1, 0]
//    i = 5: count[5] = count[5] + count[4] -> [0, 1, 3, 4, 5, 5, 1, 0, 1, 0]
//    i = 6: count[6] = count[6] + count[5] -> [0, 1, 3, 4, 5, 5, 6, 0, 1, 0]
//    i = 7: count[7] = count[7] + count[6] -> [0, 1, 3, 4, 5, 5, 6, 6, 1, 0]
//    i = 8: count[8] = count[8] + count[7] -> [0, 1, 3, 4, 5, 5, 6, 6, 7, 0]
//    i = 9: count[9] = count[9] + count[8] -> [0, 1, 3, 4, 5, 5, 6, 6, 7, 7]

//    The final count array now looks like this:
//
//    count: [0, 1, 3, 4, 5, 5, 6, 6, 7, 7]
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = size - 1; i >= 0; i--)
    {
        const int occurrenceID = getOccurrenceID(arr[i], exp);
        
//        count[occurrenceID] gives the cumulative count for the digit occurrenceID. Subtracting 1 gives the correct index for placing arr[i] in the output array.
//        For example, if occurrenceID is 2 and count[2] is 3, then outputID is 2. This means the next number with digit 2 will be placed in index 2 of the output array.
        const int outputID = count[occurrenceID] - 1;
        
        // Build the output array in reverse order
        // int outputID = size - count[occurrenceID];
        
        // The element arr[i] is placed in the output array at the index outputID.
        output[outputID] = arr[i];
        
//        The cumulative count for the digit occurrenceID is decremented by 1. This ensures that the next element with the same digit will be placed in the correct previous position.
        count[occurrenceID]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixsort(int* arr, int size)
{

    // Find the maximum number to
    // know number of digits
    int maxValue = getMax(arr, size);

    // Do counting sort for every digit.
    // Note that instead of passing digit number, exp is passed
    // exp is 10^i where i is current digit number
    for (int exp = 1; maxValue / exp > 0; exp *= 10)
    {
        cout << "exp = " << exp << endl;
        cout << "maxValue / exp = " << maxValue / exp << endl;
        countSort(arr, size, exp);
    }
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


//Tests

//int main() {
//    const int size = 15;
//
//    int arr[size] = { 1110, 2 , 6 ,-9, 5 , 116, -8000, 9, -66, 443, -3, 1, -6, 90005, 7 };
//
//    quickSort(arr, 0, size - 1);
//    //boubleSort
//    //mergeSort
//    //binarySearch
//
//    for (int i = 0; i < size; i++)
//    cout << arr[i] << ' ';
//
//    cout << endl;
//
//    system("pause");
//
//    return 0;
//}


#endif /* Sorting_h */
