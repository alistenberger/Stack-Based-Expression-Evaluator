// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
: Base_Array <T> (),
  max_size_ (1)
{
  //nothing here
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
: Base_Array <T> (length), 
max_size_ (length)
{
 //nothing here
}

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
: Base_Array <T> (length), 
max_size_ (length)
{
  this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
: Base_Array <T> (array.max_size_), 
max_size_ (array.max_size_)
{
  this->cur_size_ = array.cur_size_;
  for (int i = 0; i < array.cur_size_; i++) {
    T *thisLocation = &this->data_[i];
    T *arrayLocation = &array.data_[i];
    *thisLocation = *arrayLocation;
  }
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
  // Base_Array handles deletion
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
  if (&(*this) == &(rhs)) {
    return *this;
  } else {
    this->cur_size_ = rhs.cur_size_; 
    this->max_size_ = rhs.max_size_;    
    for (int i = 0; i < rhs.size (); i++) {
      T thisLocation = this->data_[i];
      T rhsLocation = rhs.data_[i];
      thisLocation = rhsLocation;
    }
  return *this;
  }// end else
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
  if (index > this->max_size_) {
    throw std::out_of_range ("Selected Index is out of range");
  } else {
    return this->data_[index]; 
  }
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
  if (index > this->max_size_) {
    throw std::out_of_range ("Selected Index is out of range");
  } else {
    return this->data_[index]; 
  }
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
  if (new_size >= this->cur_size_) { 
    this->cur_size_ = new_size;
    if (new_size > this->max_size_) {
      this->max_size_ = new_size;
    }
    T * tempData = new T [new_size];
    for (int i = 0; i < this->cur_size_; i++) {
      T * thisLocation = &this->data_[i];
      T * newLocation = &tempData[i];
      *newLocation = *thisLocation;
    }
    delete this->data_;
    this->data_ = tempData;
  } else if (this->cur_size_ > new_size) { 
    this->cur_size_ = new_size; //if cur_size_ is > than new size, current size is made smaller, however as per the requirements, the original contents are preserved
  }
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
  if (&(*this) == &(rhs)) {
    return true;
  } else {
    bool isEqual = true; 
    int i = 0; 
    if (rhs.size () == this->size ()) { //first check for equality. == implies strictness and if the sizes aren't equal, the arrays aren't equal
      while (isEqual == true && i < this->size ()) {
        if (this->data_[i] != rhs.data_[i]) {
          isEqual = false;
        } else {
          i++;
        } //end if/else
      }//end while
    } else {
      isEqual = false; //arrays are not equal
    }
  return isEqual; //the boolean variable for equality is returned
  }// end else
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
  return !(*this == rhs);
}

template <typename T>
void Array <T>::shrink (void)
{
  if (this->cur_size_ < this->max_size_) {
    Array <T> *newArr = new Array <T> (this->size ());
    for (int i = 0; i < this->size (); i++) { 
    T thisLocation = this->data_[i];
    T newArrLocation = newArr->data_[i];
    newArrLocation = thisLocation;
    }//end for
    (*this) = *newArr;
    for (int i = 0; i < this->size (); i++) { 
      T thisLocation = this->data_[i];
      T newArrLocation = newArr->data_[i];
      thisLocation = newArrLocation;
    } //end for transferring values back to original array
    delete newArr;
  } //end if check comparing cur size to max size 
}

template <typename T>
Array <T> Array <T>::slice (size_t begin) const
{
  if (begin > this->cur_size_) {
    throw std::out_of_range ("Begin Index is out of range");
  } else {
    int sizeNewArr = this->size () - begin; //determine length of returned array by subtracting begin from cur_size_  
    Array newArr = Array (sizeNewArr);
    T arrayPtr = this->data_[begin];
    T *newArrayPtr = &(*newArr.data_); 
    for (int i = 0; i < sizeNewArr; i++) { //deep copy of 'kept' values 
      *newArrayPtr = arrayPtr;
      arrayPtr++;
      newArrayPtr++;
    } //end for
    return newArr; 
  }//end else
}

template <typename T>
Array <T> Array <T>::slice (size_t begin, size_t end) const 
{
  if (begin > this->cur_size_ || end > this->cur_size_) {
    throw std::out_of_range ("Beginning or Ending Index is out of range");
  } else {
    int sizeNewArr = (end + 1) - begin; //find the size of the new array by subtracting begin from end +1 to account for 0th index
    Array newArr = Array (sizeNewArr);
    T arrayPtr = this->data_[begin]; 
    T *newArrayPtr = &(*newArr.data_); 
    for (int i = 0; i < sizeNewArr; i++) { //deep copy of 'kept' values
      *newArrayPtr = arrayPtr;
      arrayPtr++;
      newArrayPtr++;
    } //end for
    return newArr; 
  } //end else
}

template <typename T>
void Array <T>::append (T element)
{
  this->resize (this->size () + 1);
  this->set (this->size () - 1, element);
}