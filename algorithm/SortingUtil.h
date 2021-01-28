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
         void static insertionSort(int *arr,int size);
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


#endif //CPPCOURSE_SORTINGUTIL_H
