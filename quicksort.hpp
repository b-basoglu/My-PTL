#ifndef __PTL_QUICKSORT_HPP__
#define __PTL_QUICKSORT_HPP__
#include <algorithm>
#include <cstddef>

namespace ptl {
    
    template <class T>
    void partition(vector<T> &theArray, int first, int last,int &pivotIndex) {
        
        // i did'nt care about pivot if you want to choose one write a function which makes pivot the first element of list
        

        T pivot = theArray[first];
        int lastS1 = first;           // index of last item in S1
        int firstUnknown = first + 1; // index of 1st item in unknown
       
        // move one item at a time until unknown region is empty
        for (; firstUnknown <= last; ++firstUnknown) {
            if (theArray[firstUnknown] < pivot) {    
                ++lastS1;
                std::swap(theArray[firstUnknown], theArray[lastS1]);
            }      
        }
        // place pivot in proper position and mark its location
        std::swap(theArray[first], theArray[lastS1]);
        pivotIndex = lastS1;
    }

    template<class T>
    void quicksort(vector<T> &vec,int first,int last){
        int pivot_index=0;
        if(first<last){
            
            partition(vec,first,last,pivot_index);

            quicksort(vec,first,pivot_index-1);
            quicksort(vec,pivot_index+1,last);
        }

    }
}


#endif /* __PTL_QUICKSORT_HPP__ */