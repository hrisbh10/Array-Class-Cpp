#include <assert.h>
#include <cstddef>

template<typename T>
class Array{
	T **a;
	short int curr_arr;
	int idx;
	static const size_t BASE_SIZE = 1;
	static const short int num_array = 26;

public:
	Array(){
		a = new T*[num_array];
		curr_arr = 0;
		idx = 0;
	}
	Array(size_t n){
		a = new T*[num_array];
		curr_arr = 0;
		idx = 0;

		if(!n)
			return;

		while(n-1 >= (BASE_SIZE<<curr_arr)){
			a[curr_arr] = new T[BASE_SIZE<<curr_arr];
			n -= (BASE_SIZE<<curr_arr);
			curr_arr++;
		}
		idx = n;
		a[curr_arr] = new T[BASE_SIZE<<curr_arr];
		++curr_arr;
	}

	T& operator[](int i){
		register short int x = 0;
		while(i >= (BASE_SIZE<<x)){
			i -= (BASE_SIZE<<x);
			x++;
		}
		return a[x][i];
	}

	size_t size(){
		if(curr_arr == 0)
			return 0;
		size_t sz = (BASE_SIZE<<curr_arr);
		sz -= (BASE_SIZE<<(curr_arr-1))-idx+1;
		return sz;
	}

	bool empty(){
		return (curr_arr == 0);
	}

	T& back();		//the last pushed element
	
	void push_back(T x); //push at the last

	void pop_back();	//pop the last element

};

template<typename T>
void Array<T>::push_back(T val){
	if(curr_arr == 0)
		a[curr_arr++] = new T[BASE_SIZE];
	
	if(idx >= (BASE_SIZE<<(curr_arr-1))){
		a[curr_arr] = new T[BASE_SIZE<<curr_arr];
		idx = 0;
		curr_arr++;
	}

	a[curr_arr-1][idx++] = val;

}

template<typename T>
void Array<T>::pop_back(){
	assert(curr_arr > 0);
	--idx;
	if(!idx){
		delete[] a[--curr_arr];
		if(curr_arr)
			idx = (BASE_SIZE<<(curr_arr-1));
	}
}

template<typename T>
T& Array<T>::back(){
	return a[curr_arr-1][idx-1];
}