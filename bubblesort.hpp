#ifndef __PTL_BUBBLE_SORT_H__
#define __PTL_BUBBLE_SORT_H__
#include <algorithm>
#include <cstddef>

namespace ptl {
	template<class T>
	void bubblesort(vector<T> &vec){
		int size=vec.size();
		bool sort=0;
		int i,j;
		for(i=0 ; i<size && !sort; i++){
			sort=1;
			for(j=size-1;j>0;j--){
				if(vec[j-1]>vec[j]){
					std::swap(vec[j],vec[j-1]);
					sort=0;
				}
			}
		}
}


#endif /* __PTL_SELECTION_SORT_H__ */