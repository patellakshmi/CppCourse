#include <iostream>
#include "algorithm/Util.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <thread>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void threeWayPartitioning(int *arr, int &l, int &h, int leftPivot, int rightPivot){

    cout<< "leftPivot: "<<leftPivot<<endl;
    cout<< "rightPivot: "<<rightPivot<<endl;

    for( int i = l ; i <= h; ){

        if( arr[i] < leftPivot){
            cout<< "Swapping-data: "<< arr[i] <<" with "<<arr[l]<<"\n";
            cout<< "Swapping-index: "<< i <<" with "<< l <<"\n";
            swap(arr[i], arr[l]);
            i++;
            l++;
            cout<< "l=>"<< l <<" i=>"<<i<<" h=>"<<h<<"\n";
        }else if( arr[i] > rightPivot ){
            cout<< "Swapping-data: "<< arr[i] <<" with "<<arr[h]<<"\n";
            cout<< "Swapping-index: "<< i <<" with "<< h <<"\n";
            swap(arr[i], arr[h]);
            h--;
            cout<< "l=>"<< l <<" i=>"<<i<<" h=>"<<h<<"\n";
        }else{
            i++;
            cout<< "l=>"<< l <<" i=>"<<i<<" h=>"<<h<<"\n";
        }

        cout<< "Arr:"<<endl;
        for(int k = 0; k <= 8; k++ ){
            cout<< " "<< arr[k];
        }
        cout<< ""<<endl;


    }

}



int main()
{

    int arr[] ={0,2,1,1,1,0,0,0,1};
    int l = 0;
    int h = 8;
    threeWayPartitioning(arr, l, h, 1,1);


    return 0;

}