//
// Created by shoam on 2/13/20.
//

#ifndef CPP_UNDER_THE_HOOD_SHAREDPOINTER_H
#define CPP_UNDER_THE_HOOD_SHAREDPOINTER_H
/**
 * Shared Pointers :
A std::shared_ptr is a container for raw pointers. It is a reference counting ownership model
 it maintains the reference count of its contained pointer in cooperation with all copies of the std::shared_ptr.
 So, the counter is incremented each time a new pointer points to the resource and decremented when destructor of the object is called**/


#include "ReferenceCounter.h"

template<typename T>
class SharedPointer {
public:
    // explicit constructor -not allow implicit
    explicit SharedPointer(T *ptr = nullptr);
    // Copy constructor
    SharedPointer(SharedPointer<T>& sp);
    ~SharedPointer();

    T &operator*();


    T *operator->();

    T get();

private:
    T *rowPtr;
    ReferenceCounter *referenceCounter;

};

template<typename T>
inline SharedPointer<T>::SharedPointer(T *ptr):rowPtr(ptr),referenceCounter(new ReferenceCounter()) {

    if (rowPtr) {
        ++(*referenceCounter);
    }
    std::cout<<"in ctor "<<*referenceCounter;

}
// Copy constructor
template<typename T>
inline SharedPointer<T>::SharedPointer(SharedPointer<T>& sp):rowPtr(sp.rowPtr),referenceCounter(sp.referenceCounter){
    ++(*referenceCounter);
    std::cout<<"in copy ctor "<<*referenceCounter;
}

template<typename T>
inline SharedPointer<T>::~SharedPointer() {
    std::cout<<"in dtor referenceCounter "<<*referenceCounter<<std::endl;
    --(*referenceCounter);;
    if (referenceCounter->get_counter() == 0) {
        delete (rowPtr);
        std::cout<<"delete SharedPtr  \n";
    }


}

template<typename T>
inline T SharedPointer<T>::get() {
    return *rowPtr;
}

template<typename T>
inline T &SharedPointer<T>::operator*() {
    return *rowPtr;
}

template<typename T>
inline T *SharedPointer<T>::operator->() {
    /**
      Overloding arrow operator so that members of T can be accessed
    like a pointer (useful if T represents a class or struct or union type)
     */
    return rowPtr;
}


/**   Comparison operator    */



//inline SharedPointer<T>::operator bool() {
//    return rowPtr;
//}
template<typename T>
inline bool operator==(T &ptr1, T &ptr2) {
    return ptr1.get() == ptr2.get();
}

template<typename T>
inline bool operator>=(T &ptr1, T &ptr2) {
    return ptr1.get() >= ptr2.get();
}

template<typename T>
inline bool operator>(T &ptr1, T &ptr2) {
    return ptr1.get() > ptr2.get();
}

template<typename T>
inline bool operator<=(T &ptr1, T &ptr2) {
    return ptr1.get() <= ptr2.get();
}

template<typename T>
inline bool operator<(T &ptr1, T &ptr2) {
    return ptr1.get() < ptr2.get();
}

#endif //CPP_UNDER_THE_HOOD_SHAREDPOINTER_H
