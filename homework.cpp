#include <iostream>

template <typename T>
struct Vector {

 int size;
 int capacity;
 T* arr;
};


template <typename T>
void pushback(Vector<T> *vec, T elem) {

if(vec->size == vec->capacity) {
   vec->capacity = (vec->capacity + 1) * 2;
   T* newarr = new T[vec->capacity];
   for(int i = 0; i < vec->size; ++i) {
       newarr[i] = vec->arr[i];
   }
   delete[] vec->arr;
   vec->arr = newarr;
}

 vec->arr[vec->size] = elem;
 vec->size++; 
}



template <typename T>
void erase(Vector<T> *vec, size_t pos) {
   
  if(pos < vec->size) {
  T* newarr = new T[vec->capacity - 1];
  for(int i = 0; i < pos; ++i ) {
      newarr[i] = vec->arr[i];
  }
  for(int i = pos + 1; i < vec->size; ++i) {
      newarr[i-1] = vec->arr[i];
  }
  delete[] vec->arr;
  vec->arr = newarr;
  vec->size--;
  }

 else {
    std::cout << "Your position is invalid";
    return;
 }
} 



template<typename T>
T at(Vector<T> *vec, int pos) {
   if(pos >= vec->size) {
      std::cout << "Invalid position";
      return -1;
   } 
   return vec->arr[pos];
 }



template<typename T>
void insert(Vector<T> *vec, int pos, T val){
  
  if(pos >= vec->size){
     std::cout << "Invalid position";
     return;
  }

  if(vec->size == vec->capacity) {
  vec->capacity++;
  }

  vec->size++;
  T *newarr = new T[vec->capacity];

  for(int i = 0; i < pos; ++i){
     newarr[i] = vec->arr[i];
  }

  newarr[pos] = val;

  for(int i = pos + 1; i < vec->size; ++i){
     newarr[i] = vec->arr[i-1]; 
  }

  delete[] vec->arr;
  vec->arr = newarr; 
 
}


int main(){

Vector<int> myarr;
myarr.arr = new int[myarr.capacity];

pushback(&myarr, 22);
pushback(&myarr, 18);
pushback(&myarr, 3);
insert(&myarr,1,17);
for(int i = 0; i < myarr.size; ++i) {
    std::cout <<  myarr.arr[i] << "  ";
}
  delete[] myarr.arr;

return 0;
}


