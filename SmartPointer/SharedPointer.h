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

private:
    T *rowPtr;

};
#endif //CPP_UNDER_THE_HOOD_SHAREDPOINTER_H
