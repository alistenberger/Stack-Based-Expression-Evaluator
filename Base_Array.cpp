#include <stdexcept>         // for std::out_of_bounds exception

//
// Base_Array
//
template <typename T>
Base_Array <T>::Base_Array (void)
: data_ (new T [1]),
  cur_size_ (0)
{
  //nothing here
}

//
// Base_Array (size_t)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length)
: data_ (new T [length]), 
cur_size_ (length)
{
 //nothing here
}

//
// Base_Array (size_t, T)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill)
: data_ (new T [length]), 
cur_size_ (length)
{
  this->fill(fill);
}

//
// Base_Array (const Base_Array &)
//
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & array)
: data_ (new T [array.size ()]), 
cur_size_ (array.cur_size_)
{
 for (int i = 0; i < array.cur_size_; i++) {
    T *thisLocation = &this->data_[i];
    T *arrayLocation = &array.data_[i];
    *thisLocation = *arrayLocation;
  }
}

//
// ~Base_Array
//
template <typename T>
Base_Array <T>::~Base_Array (void)
{
  delete [] data_;
}

//
// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
  if (&(*this) == &(rhs)) {
    return *this;
  } else {
    this->cur_size_ = rhs.cur_size_;   
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
T & Base_Array <T>::operator [] (size_t index)
{
  if (index > this-> cur_size_) {
    throw std::out_of_range ("Selected Index is out of range");
  } else {
    return data_[index]; 
  }
}

//
// operator [] 
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
  if (index > this-> cur_size_) {
    throw std::out_of_range ("Selected Index is out of range");
  } else {
    return data_[index]; 
  }
}

//
// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const
{
  if (index > this->cur_size_) {
    throw std::out_of_range ("Selected Index is out of range");
  } else {
    T *location = &(*this->data_) + index; 
    return *(location); 
  } //end else
}

//
// set
//
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
  if (index > this-> cur_size_) {
    throw std::out_of_range ("Selected Index is out of range");
  } else {
    T *location = &(*this->data_) + index; 
    T *replaceValue = location; 
    *replaceValue = value; 
  }
}

//
// find (T)
//
template  <typename T>
int Base_Array <T>::find (T value) const
{
  return this->find (value, 0);
}

//
// find (val, size_t) 
//
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
  if (start > this->cur_size_) {
    throw std::out_of_range ("Start Index is out of range");
  } else {
    size_t indexCtr = start; 
    bool valFound = false;
    T *location = &(*this->data_) + start;
    while (valFound == false && indexCtr != this->size () - 1) {
      if (val != *location) { 
        indexCtr ++; 
        location ++;
      } else if (val == *location) { 
        valFound = true;
      } //end conditionals
    }//end while
    if (valFound != true) {
     indexCtr = -1;
    }//end if
  return indexCtr;
  }// end else
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
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
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
  return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
  for (int i = 0; i < this->size (); i++) { 
    T *arrPtr = &this->data_[i];
    *arrPtr = value; 
  }//end for
}

template <typename T>
void Base_Array <T>::reverse (void)
{
  size_t arrSize = this->size (); 
  size_t lastIndex = arrSize - 1; //establishes a location for the last value in the array 
  T *lastPosition = nullptr; // establish a pointer which will point to the end of the array and iterate backwards
  T *firstPosition = nullptr;  //establish a pointer that will point to the beginning of the array and iterate forwards
  firstPosition = &(*this->data_); 
  lastPosition = &(*this->data_) + lastIndex; 
  for (int i = 0; i < arrSize/2; i++) {//reverse what value each pointer points to (ex. index at 0 becomes value at -1, vice versa)
    T temp = *firstPosition; 
    *firstPosition = *lastPosition; 
    *lastPosition = temp; 
    firstPosition ++; 
    --lastPosition; 
  } //end for
}