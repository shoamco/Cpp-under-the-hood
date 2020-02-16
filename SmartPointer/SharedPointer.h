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
template <typename T>
class SharedPointer{
public:
    // explicit constructor -not allow implicit
    explicit SharedPointer(T *ptr= nullptr);
    ~SharedPointer();
    T &operator*();


    T *operator->();
    T get();
private:
    T *rowPtr;
    ReferenceCounter *referenceCounter;

};
inline SharedPointer::SharedPointer(){
    if(rowPtr){
        ++referenceCounter;
    }
}
inline SharedPointer::~SharedPointer(){
    if(referenceCounterl.get_counter()==0){
       delete(rowPtr);
    }
    else:
       --referenceCounter;

}

inline T SharedPointer<T>::get(){
    return *rowPtr;
}
inline  T &SharedPointer::operator*(){
    return *rowPtr;
}
inline T *SharedPtr<T>::operator->() {
    /**
      Overloding arrow operator so that members of T can be accessed
    like a pointer (useful if T represents a class or struct or union type)
     */
    return rowPtr;
}


/**   Comparison operator    */
template<typename T>
inline bool operator==(T &ptr1, T &ptr2) {
    return ptr1 == ptr2;
}

template<typename T>
inline bool operator>=(T &ptr1, T &ptr2) {
    return ptr1 >= ptr2;
}

template<typename T>
inline bool operator>(T &ptr1, T &ptr2) {
    return ptr1 > ptr2;
}

template<typename T>
inline bool operator<=(T &ptr1, T &ptr2) {
    return ptr1 <= ptr2;
}

template<typename T>
inline bool operator<(T &ptr1, T &ptr2) {
    return ptr1 < ptr2;
}

#endif //CPP_UNDER_THE_HOOD_SHAREDPOINTER_H
