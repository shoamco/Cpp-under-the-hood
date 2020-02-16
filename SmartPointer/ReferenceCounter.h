//
// Created by shoam on 2/13/20.
//

#ifndef CPP_UNDER_THE_HOOD_CONTROLBLOCK_H
#define CPP_UNDER_THE_HOOD_CONTROLBLOCK_H

/**
 * class ReferenceCounter for Reference Counting :
It is a technique of storing the number of references, pointers or handles to a resource such as an object, block of memory, disk space or other resources.

An object referenced by the contained raw pointer will not be destroyed until reference count is greater than zero
 until all copies of std::shared_ptr have been deleted.
 * */
class ReferenceCounter {
public:
    ReferenceCounter(): m_counter(0){};
    //delete copy ctor and assignment operator because they do not want to allow
    ReferenceCounter(const ReferenceCounter &)= delete;//delete copy ctor
    ReferenceCounter& operator=(const ReferenceCounter&) = delete;   //delete copy ctor
    size_t get_counter();
    // Overload post/pre increment
    void operator++();
    void operator++(int );
    // Overload post/pre decrement
    void operator--();
    void operator--(int );
    // Overloading << operator
    friend std::ostream& operator<<(std::ostream& os, const ReferenceCounter& counter);
private:
    size_t m_counter;
};

inline  size_t ReferenceCounter::get_counter(){
    return m_counter;
}
// Overload post/pre increment
inline void ReferenceCounter::operator++()
{
    m_counter++;
}

inline void ReferenceCounter::operator++(int)
{
    m_counter++;
}

// Overload post/pre decrement
inline void ReferenceCounter::operator--()
{
    m_counter--;
}
inline void ReferenceCounter::operator--(int)
{
    m_counter--;
}
// Overloading << operator
inline std::ostream& operator<<(std::ostream& os, const ReferenceCounter& counter)
{
    os << "Counter Value : "
       << counter.m_counter << std::endl;
}
#endif //CPP_UNDER_THE_HOOD_CONTROLBLOCK_H
