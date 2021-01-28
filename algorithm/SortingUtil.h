//
// Created by Lakshmi S Patel on 29/01/21.
//

#ifndef CPPCOURSE_SORTINGUTIL_H
#define CPPCOURSE_SORTINGUTIL_H
#include <iostream>
using namespace std;

namespace sortutil {

    class SortingUtil {
    public:
         void insertionSort(int *arr,int size);
         int partition(int *arr, int low, int high);
    };

};

void sortutil::SortingUtil::insertionSort(int *arr, int size) {

    /* This sorting technique is very useful where we need to insert the elements at appropriate position according to
     * sorting.
     * Ex. Find next greater number using given set of number in array.
     * If you solve above problem, you find insertion sorting technique is used to placed the effective element at
     * appropriate position to get the bigger number.
     * */

    for(int i = 1; i< size; i++){
        int key = arr[i];
        int j = i-1;
        while( j >= 0 && key < arr[j]){
            swap(arr[j], arr[j+1]);
            j--;
        }
        arr[j+1] = key;
    }
}


int sortutil::SortingUtil::partition(int *arr, int low, int high){
    /* Partition the array by taking the last element as pivot element.
     * There are different ways to take the pivot element but here I considering the last element as pivot.
     *
     * main idea: rest of element from index - low to high-1 we need to partition into two group one group
     * consist of lesser elements and another group consist of greater element.
     * for that let the variable which track the middle element of two group always point to the last element of lesser
     * group.
     *
     * whenever we find the greater element just we need to increase the tracking variable by one and swap with greater
     * element so that after swapping tracking variable positioned to right position - it is at last element of lesser
     * group.
     * We need to understand clearly at initially tracking variable should be at low-1 position because we dont have group.
     * wherever or whenever we get the lesser element during scanning from low to high-1. we first increase the tracking
     * variable and than swap the element.
     *
     * */

    int pivot = arr[size-1];
    int trackingIndex = low-1;

    for( int i = low; i <= high-1; i++){

        if( arr[i] < pivot){
            trackingIndex++;
            swap(arr[i], arr[trackingIndex]);
        }
        swap(arr[i], arr[++trackingIndex]);
        return trackingIndex;

    }

}


#endif //CPPCOURSE_SORTINGUTIL_H
