/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 08/02/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_ARRAYUTIL_H
#define CPPCOURSE_ARRAYUTIL_H
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
using namespace std;

namespace au{

    class StreamStatistics{
    private:
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int kth;
        int count;
    public:
        StreamStatistics(int kth){ this->kth = kth;this->count = kth; }
        int kthLargest(int x){
            if( count > 0 ){
                minHeap.push(x);
                count--;
                if(minHeap.size() == kth){
                    return minHeap.top();
                }
                return -1;
            }

            if( x > minHeap.top() ){
                minHeap.pop();
                minHeap.push(x);
                return minHeap.top();
            }else{ return minHeap.top(); }
        }
    };

    class ArrayUtil{
    public:
        void rearrange(int *arr,int size);
        void convertToBiggestNumber(int *arr, int size);
        void moveAllNegAtBeginning(int *arr, int size);
        void maxMinArrangement(int *arr, int size);
        void moveAllNegAtEnd(int *arr, int size);
        pair<int, int> largestSubArrEq01(int *arr, int size);
        int maxSubarray(int *arr, int size);
        int countStrictlyIncSubArr(int *arr, int size);
        int largestPairSum(int *arr, int size);
        int lower_bound(int *arr, int l, int h, int k);
        int upper_bound(int *arr, int l, int h, int k);
        int lowerBoundIterative(int *arr, int size,int k);
        int upperBoundIterative(int *arr,int size, int k);
        int getMinDiff(int *arr, int size, int k );
        int min(int a, int b);
        int largestCommonSum(int *arr1,  int *arr2, int size);
        void rotateLeftMatrix(vector<vector<int>> &mat)
    };

    class KStack{
    private:
        int size;
        int kStack;
        int *arr;
        int *top;
        int *next;
        int free;
    public:
        KStack(int size, int kStack){
            this->size = size;
            this->kStack = kStack;
            this->arr = new int[this->size];
            this->top = new int[this->kStack];
            this->next = new int[this->size];
            this->free = 0;
            for(int i = 0; i < size; i++){
                this->arr[i] = -1;
                this->next[i] = i+1;
            }
            this->next[size-1] = -1;
            for(int i = 0; i < kStack; i++){
                this->top[i] = -1;
            }

        }

        void push(int value, int kthStack){

            if( free == -1){
                cout<< "STACK IS FULL!";
            }

            int i = free;
            free = next[i];

            next[i]= top[kthStack];
            top[kthStack] = i;

            arr[i] = value;
        }

        int pop(int kthStack){

            if( top[kthStack] == -1){ cout<< "STACK IS EMPTY"; return  -1; }
            int i = top[kthStack];
            top[kthStack] = next[i];
            next[i] = free;
            free = i;

            return arr[i];
        }
    };

}


void au::ArrayUtil::rearrange(int *arr,int size){
    for(int i = 0; i< size; i++){
        while (arr[i] != -1 && arr[i] != i){
            int valueI = arr[i];
            int valueJ = arr[valueI];
            arr[valueI] = valueI;
            arr[i] = valueJ;
        }
    }
}

void au::ArrayUtil::convertToBiggestNumber(int *arr, int size){

    sort(arr,arr+size,[](int a, int b){

        string aString = to_string(a);
        string bString = to_string(b);
        string ab = aString+bString;
        string ba = bString+aString;
        int abInt = atoi(ab.c_str());
        int baInt = atoi(ba.c_str());
        return abInt > baInt;

    });

};


void au::ArrayUtil::moveAllNegAtBeginning(int *arr, int size){

    int i = 0;
    int j = 0;
    for(int j = 1; j < size; j++){
        if( arr[j] < 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
}


void au::ArrayUtil:: maxMinArrangement(int *arr, int size){

    int low = 0;
    int high = size-1;
    int max = arr[size-1]+1;

    for(int i = 0; i< size; i++){
        if( i %2 == 0 ){
            arr[i] += (arr[high]%max)*max;
            high--;
        }else{
            arr[i] +=(arr[low]%max)*max;
            low++;
        }
    }

    //Restoring the value
    for(int i = 0; i< size; i++){
        arr[i] = arr[i]/max;

    }

}


void au::ArrayUtil::moveAllNegAtEnd(int *arr, int size){

    /*
     * By using Lomuto partition
     * */
    int i = 0;
    for(int j = 0; j < size; j++ ){
        if( arr[j] > 0 ){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
}

pair<int, int> au::ArrayUtil::largestSubArrEq01(int *arr, int size){

    map<int, int> m;
    int sum = 0;
    int maxSize = 0;
    int lastIndex = -1;
    for(int i = 0; i < size; i++){

        sum += arr[i] == 0 ? -1: 1;
        if( sum == 0 ){
            maxSize = i+1;
            lastIndex = i;
        }

        if( m.find(sum+size) != m.end()) {
            int index = m[sum + size];
            if (maxSize < i - index + 1) {
                maxSize = i - index + 1;
                lastIndex = i;
            }
        }else{
            m[sum+size] = i;
        }

    }

    int firstIndex = -1;
    if( lastIndex != -1)
        firstIndex = lastIndex-maxSize+1;

    return make_pair(firstIndex, lastIndex);

}


int au::ArrayUtil::maxSubarray(int *arr, int size){

    int sum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i< size; i++){
        sum += arr[0];
        if( maxSum < sum ){
            maxSum = sum;
        }

        if( sum < 0 ) {
            sum = 0;
        }
    }

    return maxSum;

}


int au::ArrayUtil::countStrictlyIncSubArr(int *arr, int size){

    int totalCount = 0;
    int count = 1;
    for(int i = 1; i < size; i++){
        if( arr[i-1] < arr[i] ){ count++;}
        else{
            totalCount += count*(count-1)/2;
            count = 1;
        }
    }

    totalCount += count*(count-1)/2;

    return totalCount;
}

int au::ArrayUtil::largestPairSum(int *arr, int size){
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    for(int i = 0; i < size; i++){
        if( i <= 1)
            maxHeap.push(arr[i]);
        else{
            if( arr[i] > maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
    }

    if( size < 2){
        return -1;
    }else{
        int sum = maxHeap.top(); maxHeap.pop();
        sum += maxHeap.top();
        return sum;
    }
}

int au::ArrayUtil::lower_bound(int *arr, int l, int h, int k ){

    if( h < l ) return -1;

    if( l == h ){ return l; }

    int mid = ( l + h )/2;
    if( k <= arr[mid] ){
        return lower_bound(arr, l, mid, k);
    }else{
        return lower_bound(arr, mid+1, h, k);
    }

}

int au::ArrayUtil::upper_bound(int *arr, int l, int h, int k ){

    if( h < l ) return -1;

    if( l == h ){ return l; }

    int mid = ( l + h )/2;
    if( k > arr[mid] ){
        return lower_bound(arr, l, mid-1, k);
    }else{
        return lower_bound(arr, mid, h, k);
    }

}

int au::ArrayUtil::lowerBoundIterative(int *arr,int size, int k){

    int low = 0;
    int high = size-1;

    while (low < high){
        int mid = ( low+high)/2;
        if( k <= arr[mid]){
            high = mid;
        }else{
            low = mid+1;
        }
    }

    return low;

}

int au::ArrayUtil::upperBoundIterative(int *arr,int size, int k){

    int low = 0;
    int high = size-1;

    while (low < high){
        int mid = ( low+high)/2;
        if( k <= arr[mid]){
            high = mid;
        }else{
            low = mid+1;
        }
    }

    return low;

}


int au::ArrayUtil::min(int a, int b ){
    if( a < b) return a;
    else return b;
}

int au::ArrayUtil::getMinDiff(int *arr, int size, int k ){

    if( size == 1 ) return 0;

    sort(arr, arr+size);

    int ans = arr[size-1]-arr[0];
    int small = arr[0] +k;
    int big = arr[size-1]-k;

    if( small > big ) swap(small, big );

    for(int i = 1; i < size-1; i++){

        int subtract = arr[i]-k;
        int add = arr[i]+k;

        if( subtract > small || add < big ) continue;

        if( big-subtract < add-small ){
            small = subtract;
        }else{
            big = add;
        }
    }

    return min(ans,(big-small));
}

int au::ArrayUtil::largestCommonSum(int *arr1,  int *arr2, int size){

    map<int, int> m;
    map<int, int>::iterator it;
    int maxLen = INT_MIN;

    int preSum1 = 0;
    int preSum2 = 0;
    for(int i = 0; i < size; i++){
        preSum1 += arr1[i];
        preSum2 += arr2[i];

        int diff = preSum1 - preSum2;

        if( diff == 0 ){

            if( i > maxLen){
                maxLen = i+1;
            }

        }

        if( (it = m.find(diff)) != m.end()){
            int oldIndex = it->second;
            if( i-oldIndex > maxLen){
                maxLen = i - oldIndex;
            }
        }else{
            m[diff] = i;
        }

    }

    return maxLen;

}


void au::ArrayUtil::rotateLeftMatrix(vector<vector<int>> &mat) {

    int startCol = 0;
    int endRow = mat.size() - 1;
    int startRow = 0;
    int endCol = mat[0].size() - 1;

    int i;
    int j;

    cout<< endl;
    cout<< "Befor";
    cout<< endl;

    for(int i = 0; i< mat.size(); i++ ){
        cout<< endl;
        for(int j = 0; j < mat[0].size(); j++){
            cout.width(4);
            cout<< mat[i][j];
        }
    }


    while( startRow < endRow && startCol < endCol ){

        i = startRow;
        j = startCol;

        int temp = mat[i][j];

        while (j+1 <= endCol){
            mat[i][j] = mat[i][j+1];
            j++;
        }

        startRow++;

        while ( i+1 <= endRow){
            mat[i][j] = mat[i+1][j];
            i++;
        }

        endCol--;

        while (j-1 >= startCol) {
            mat[i][j] = mat[i][j - 1];
            j--;
        }

        endRow--;

        while ( i-1 >= startRow){
            mat[i][j] = mat[i-1][j];
            i--;
        }

        startCol++;

        mat[i][j] = temp;

    }



    cout<< endl;
    cout<< "After";
    cout<< endl;

    for(int i = 0; i< mat.size(); i++ ){
        cout<< endl;
        for(int j = 0; j < mat[0].size(); j++){
            cout.width(4);
            cout<< mat[i][j];
        }
    }



}




#endif //CPPCOURSE_ARRAYUTIL_H
