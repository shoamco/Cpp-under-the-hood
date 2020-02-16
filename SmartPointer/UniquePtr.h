//
// Created by shoam on 2/16/20.
//

#ifndef SMARTPOINTER_UNIQUEPTR_H
#define SMARTPOINTER_UNIQUEPTR_H


/**
unique_ptr<> is one of the Smart pointer implementation to prevent memory leaks.
 A unique_ptr object wraps around a raw pointer and its responsible for its lifetime.
 When this object is destructed then in its destructor it deletes the associated raw pointer.

unique_ptr has its -> and * operator overloaded, so it can be used similar to normal pointer
 A unique_ptr object is always the unique owner of associated raw pointer. We can not copy a unique_ptr object, its only movable.

As each unique_ptr object is sole owner of a raw pointer, therefore in its destructor it directly deletes the associated pointer.
 There is no need of any reference counting
 * */
template<typename T>
class UniquePtr {
public:
    // explicit constructor -not allow implicit to  Prevent unwanted pointer copying so we can manage memory correctly
    explicit UniquePtr(T *ptr = nullptr);

    // Copy constructor
    UniquePtr(UniquePtr<T> &sp) = delete;
    UniquePtr<T> &operator=(const UniquePtr<T> &other);//assignment operator


    ~UniquePtr();

    T &operator*();


    T *operator->();

    T get();

    T* release();//returns a pointer to the managed object and releases the ownership



    void reset();// replaces the managed object
    void swap();//swaps the managed objects

    template<typename U>
    //friend class- to allow polymorphism
    friend
    class uniquePtr;

private:
    T *rowPtr;
;

};
template<typename T>
inline UniquePtr<T>::UniquePtr(T *ptr):rowPtr(ptr){

}
template<typename T>
inline UniquePtr<T>::~UniquePtr(){
delete(rowPtr);
}
template<typename T>

inline  UniquePtr<T> &UniquePtr<T>::operator=(const UniquePtr<T> &other)//assignment operator
{
 if(rowPtr){
     delete(rowPtr);
 }
    rowPtr=other.rowPtr;
    other.rowPtr= nullptr;
}


template<typename T>
inline T UniquePtr<T>::get() {
    return *rowPtr;
}

template<typename T>
inline T &UniquePtr<T>::operator*() {
    return *rowPtr;
}

template<typename T>
inline T *UniquePtr<T>::operator->() {


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
#endif //SMARTPOINTER_UNIQUEPTR_H
