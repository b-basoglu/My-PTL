#include <iostream>
#include <vector>
#include <string>
using namespace std;



template<class T> 
void newswap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}
template<class T>
void print(vector<T> &v, int pass) {
  int size = v.size();
  cout << "Pass " << pass << ": ";
  for(int i=0; i<size; i++)
    cout << v[i] << " ";
  cout << endl;
}
template<class T> void print_sortedvec(vector<T> &v) {
  int size = v.size();
  for(int i=0; i<size; i++)
    cout << v[i] << " ";
  cout << endl;
}

/*Shuffle function to mix the input*/
template<class T> void shuffle(vector<T> &v) {
  int size = v.size()-1;
  srand(time(NULL));
  for(int i=size-1; i>0; i--) {
     int j = rand() % (size+1);
     newswap(v[i],v[j]);
  }

}


//Selection Sort***********************************************************************************************************


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
		//print(arg,i); 				//to follow how to sort
		newswap(arg[i],arg[min]);
		
	}

}



//Insertion Sort*************************************************************************************************************


template<class T>
void insertionsort(vector<T> &arg){
	int i,j;
	int size = arg.size();
	for(i = 1;i < size;i++){
		for(j = i; j > 0;j--){
			if(arg[j-1]>arg[j]){
				newswap(arg[j-1],arg[j]);
			}
		}
		//print(arg,i); 				//to follow how to sort
	}
}



//Bubble Sort****************************************************************************************************************



template<class T>
void bubblesort(vector<T> &vec){
	int size=vec.size();
	bool sort=0;
	int i,j;
	for(i=0 ; i<size && !sort; i++){
		sort=1;
		for(j=size-1;j>0;j--){
			if(vec[j-1]>vec[j]){
				swap(vec[j],vec[j-1]);
				sort=0;
			}
		}
		//print(arg,i); 				//to follow how to sort

	}
}


//Merge Sort****************************************************************************************************************








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
		//print_sortedvec(vec);
		
	}
}



//Quick Sort****************************************************************************************************

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
            swap(theArray[firstUnknown], theArray[lastS1]);
        }	   
    }
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1]);
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
	//print_sortedvec(vec);

}







int main(){
	vector<int> v_int {13,4,2,5,1,8,98,5,34,45,67};
	int v_int_size=v_int.size()-1;
	vector<string> v_str {"bob","martin","benjamin","yousef","sally","alise"};
	int v_str_size=v_str.size()-1;

	/*************Selection Sort********************/
	shuffle(v_int);								//This is for mixing vector
	selectionsort(v_int);
	cout<<	"Selectionsort on integer:" << endl;
	print_sortedvec(v_int);

	shuffle(v_str);								//This is for mixing vector
	selectionsort(v_str);
	cout<<	"Selection Sort on string:" << endl;
	print_sortedvec(v_str);
	cout<<	"**********************************************************" << endl;
	


	/*************Insertion Sort********************/
	shuffle(v_int);								//This is for mixing vector
	insertionsort(v_int);
	cout<<	"insertion Sort on integer:" << endl;
	print_sortedvec(v_int);

	shuffle(v_str);								//This is for mixing vector
	insertionsort(v_str);
	cout<<	"Insertion Sort on string:" << endl;
	print_sortedvec(v_str);

	cout<<	"**********************************************************" << endl;
	

	/*************Bubble Sort********************/
	shuffle(v_int);								//This is for mixing vector
	bubblesort(v_int);
	cout<<	"Bubble Sort on integer:" << endl;
	print_sortedvec(v_int);

	shuffle(v_str);								//This is for mixing vector
	bubblesort(v_str);
	cout<<	"Bubble Sort on string:" << endl;
	print_sortedvec(v_str);


	cout<<	"**********************************************************" << endl;
	

	/*************Merge Sort********************/
	shuffle(v_int);								//This is for mixing vector
	mergesort(v_int,0,v_int_size);
	cout<<	"Selectionsort on integer:" << endl;
	print_sortedvec(v_int);

	shuffle(v_str);								//This is for mixing vector
	mergesort(v_str,0,v_str_size);
	cout<<	"Merge sort on string:" << endl;
	print_sortedvec(v_str);

	
	cout<<	"**********************************************************" << endl;
	

	/*************Quick Sort********************/
	shuffle(v_int);								//This is for mixing vector
	quicksort(v_int,0,v_int_size);
	cout<<	"Quick sort on integer:" << endl;
	print_sortedvec(v_int);

	shuffle(v_str);								//This is for mixing vector
	quicksort(v_str,0,v_str_size);
	cout<<	"Quick sort on string:" << endl;
	print_sortedvec(v_str);

}

