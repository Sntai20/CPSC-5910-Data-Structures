//
// Created by Scott McMaster on 5/8/2021.
//

#ifndef LECTURE_QUICKSORT_H
#define LECTURE_QUICKSORT_H

#include "insertionsort.h"

const int MIN_SIZE = 3;

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
template<class ItemType>
int partition(ItemType theArray[], int low, int high) {
    int middle = low + (high - low) / 2;

    if ((theArray[middle] >= theArray[low] && theArray[middle] <= theArray[high])
        || (theArray[middle] <= theArray[low] && theArray[middle] >= theArray[high]))
        std::swap(theArray[high], theArray[middle]);

    if ((theArray[high] >= theArray[low] && theArray[high] <= theArray[middle])
        || (theArray[high] <= theArray[low] && theArray[high] >= theArray[middle]))
        std::swap(theArray[low], theArray[high]);


    int pivot = theArray[low];
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
        } while (theArray[i] < pivot);

        do {
            j--;
        } while (theArray[j] > pivot);

        if (i >= j)
            return j;

        std::swap(theArray[i], theArray[j]);
    }
}

/** Sorts an array into ascending order. Uses the quick sort with
    median-of-three pivot selection for arrays of at least MIN_SIZE
    entries, and uses the insertion sort for other arrays.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template<class ItemType>
void quickSort(ItemType theArray[], int first, int last) {
    if ((last - first + 1) < MIN_SIZE) {
        insertionSort(theArray, last - first);
    } else {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(theArray, first, last);

        // Sort subarrays S1 and S2
        quickSort(theArray, first, pivotIndex - 1);
        quickSort(theArray, pivotIndex + 1, last);
    }  // end if
}  // end quickSort

#endif //LECTURE_QUICKSORT_H
