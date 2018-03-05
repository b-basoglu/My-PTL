#ifndef __PTL_MERGE_SORT_HPP__
#define __PTL_MERGE_SORT_HPP__
#include <cstddef>


namespace ptl {
    
    template<class T>
    void merge(vector<T> &vec,int first,int mid,int last){
        T tmp[last+1];
        int first1=first;
        int last1=mid;
        int first2=mid+1;
        int last2=last;
        int index= first1;
        for(;first1<=last1 && first2 <=last2;++index ){

            if(vec[first1]<=vec[first2]){

                tmp[index]=vec[first1];
                first1 ++;

            }
            else{

                tmp[index]=vec[first2];
                first2 ++;
            }
        }

        for(;first1<=last1;++index,first1++){
            tmp[index]=vec[first1];
        }
        for(;first2<=last2;++index,first2++){
            tmp[index]=vec[first2];
        }
        for(index=first;index<=last;index++){
            vec[index]=tmp[index];
            
        }


    }


    template<class T>
    void mergesort(vector<T> &vec,int first,int last){
        
        if(first<last){
            int mid=(first+last)/2;
            mergesort(vec,first,mid);

            mergesort(vec,mid+1,last);

            merge(vec,first,mid,last);
            
        }
    }


}

#endif /* __PTL_MERGE_SORT_HPP__ */