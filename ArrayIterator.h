#ifndef _ARRAYITERATOR_H_
#define _ARRAYITERATOR_H_

#include "Array.h"

template <typename T> 
class ArrayIterator 
{ 
public: 
  ///Type definition of the element type
  typedef T type;

  /**
   * Initializing constructor
   * 
   * @param[in]     array     The array object the iterator will be used on
   */
  ArrayIterator (Array <T> & array);

  ///Destructor
  ~ArrayIterator (void);

  ///Evaluates if the iterator has reached the end of the array
  bool isDone (void);

  ///Advances the iterator to the next object
  void advance (void);

  ///Overloads the * operator for dereferencing what is pointed at
  T & operator * (void);

  ///Overloads the -> operator for dereferencing
  T * operator -> (void);

private: 

  Array <T> & array_; 
  size_t index_;

};

#include "ArrayIterator.cpp"
#endif // !defined _ARRAYITERATOR_H_
