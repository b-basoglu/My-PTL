#ifndef __PTL_SELECTION_SORT_H__
#define __PTL_SELECTION_SORT_H__
#include <algorithm>
#include <cstddef>

namespace ptl {
	template <class T>
	void selectionsort(vector<T> &arg){
		int i,j;
		int min;
		int size=arg.size();
		for(i=0;i<size;i++){
			min=i;
			for(j=i+1;j<size;j++){
				if(arg[j]<arg[min]){
					min=j;
				}
			}
			std::swap(arg[i],arg[min]);
			
		}
	}
}

#endif /* __PTL_SELECTION_SORT_H__ */