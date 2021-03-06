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
overall time complexity

#pragma mark - quickSort     O(n log(n))                 квазилинейная
#pragma mark - boubleSort    O(n^2)                     полиномиальная
#pragma mark - mergeSort     O(n log(n))                 квазилинейная
#pragma mark - recursion     O(m^n)                     экспоненциальная
#pragma mark - Heap Sort     O(n log(n))                квазилинейная (in - place algorith)

#pragma mark - binarySearch  O(log(n))                  логарифмическая

//Conquer(властвуй)
//enormously(чрезвычайно)
//denoting(обозначает)
//average(средний)
//Auxiliary (вспомогательный)

// Time Complexity - big O

// Auxiliary Space
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

//https://www.geeksforgeeks.org/heap-sort/

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

#pragma mark - mergeSort

void mergeSort(int * _arr, int * _helper, int _low, int _middle, int _hight)
{
    for (int i = _low; i <= _hight; i++)
    {
        _helper[i] = _arr[i];
    }
    
    int helperLeft = _low;
    int helperRight = _middle + 1;
    int current = _low;
    
    while (helperLeft <= _middle && helperRight <= _hight)
    {
        if (_helper[helperLeft] <= _helper[helperRight])
        {
            _arr[current] = _helper[helperLeft++];
        }
        else
        {
            _arr[current] = _helper[helperRight++];
        }
        
        current++;
    }
    
    int remaning = _middle - helperLeft;
    
    for (int i = 0; i <= remaning; i++)
    {
        _arr[current + i] = _helper[helperLeft + i];
    }
}

void mergeSort(int* _arr, int* _helper, int _low, int _hight)
{
    if (_low < _hight)
    {
        int middle = (_low + _hight) / 2;
        
        cout << "sort left side" << "   _low: " << _low << "   _hight: " << _hight << endl;
        mergeSort(_arr, _helper, _low, middle); // sort left side
        
        cout << "sort right side" << "  _low: " << _low << "   _hight: " << _hight << endl;
        
        mergeSort(_arr, _helper, middle + 1, _hight); // sort right side
        
        cout << "merge" << endl;
        
        mergeSort(_arr, _helper, _low, middle, _hight); // merge
    }
    else
    cout << endl << "end recursion" << endl << endl;
}

void mergeSort(int* _arr, int _size)
{
    int* helper = new int[_size];
    
    mergeSort(_arr, helper, 0, _size - 1);
    
    if (helper)
    {
        delete[] helper;
        
        helper = NULL;
    }
}

#pragma mark - boubleSort

void swap(int & a,
          int & b
          )
{
    int t = a;
    a = b;
    b = t;
}

// add sort from the end
void boubleSort(int * _arr,
                int _size
                )
{
    for (int i = 0; i < _size; i++)
        for (int j = 0; j < _size - i; j++)
            if (_arr[j] > _arr[j + 1])
                swap(_arr[j], _arr[j + 1]);
}

#pragma mark - quickSort Sort

int processing(int * _array, int _l, int _h)
{
    int pivot = _array[(_l + _h) / 2];
    
    while (_l <= _h)
    {
        while (_array[_l] < pivot)
        {
            _l++;
        }
        
        while (pivot < _array[_h])
        {
            _h--;
        }
        
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
    {
        quickSort(_array, _l, index - 1);
    }
    
    if (index < _h )
    {
        quickSort(_array, index, _h);
    }
    
}

#pragma mark - Selection Sort

void selectionSort(int *arr, int n) {
    
    int i, j, min_idx;
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[min_idx] > arr[j])
                min_idx = j;
        
        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
    
}

#pragma mark - Selection Stable Sort

void selectionStableSort(int *arr, int size) {
    // Iterate through array elements
    for (int i = 0; i < size - 1; i++)
    {
        // Loop invariant : Elements till a[i - 1] are already sorted.
        
        // Find minimum element from arr[i] to arr[n - 1].
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[min_idx] > arr[j])
                min_idx = j;
        
        // Move minimum element at current i.
        int value = arr[min_idx];
        while (min_idx > i) {
            arr[min_idx] = arr[min_idx - 1];
            min_idx--;
        }
        arr[i] = value;
    }
}

#pragma mark - Insertion Sort

void insertionSort(int* arr, int size)
{
    int i, key, j;
    
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        
        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead (вперед) of their current position */
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j--];
            //j -= 1;
        }
        arr[j + 1] = key;
    }
}

#pragma mark - Heap Sort

void heapify(int *arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    largest = l;
    
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    largest = r;
    
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        
        // Recursively heapify the affected sub-tree
        std::cout << "start recursiv call" << std::endl;
        heapify(arr, n, largest);
        std::cout << "finished recursiv call" << std::endl;
    }
}

void heapSort(int *arr, int size) {
    // Build heap (rearrange array)
    for (auto i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    
    printArray(arr, size);
    std::cout << "Heap was created" << std::endl;
    
    // One by one extract an element from heap
    for (auto i = size - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
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
