// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
: Base_Array <T> (N)
{
  //nothing here
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
: Base_Array <T> (arr.size ())
{
 for (int i = 0; i < arr.cur_size_; i++) {
    T *thisLocation = &this->data_[i];
    T *arrayLocation = &arr.data_[i];
    *thisLocation = *arrayLocation;
  }
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
: Base_Array <T> (N)
{
  this->fill (fill);
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
  //deletion handled by base array
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
  if (&(*this) != &rhs) {
    return *this;
  } else {
    if (this->cur_size_ = rhs.cur_size_) {   
      for (int i = 0; i < rhs.size (); i++) {
        T thisLocation = this->data_[i];
        T rhsLocation = rhs.data_[i];
        thisLocation = rhsLocation;
      }
      return *this;
    }
  return *this;
  }// end else
}

//
// operator []
//
template <typename T, size_t N>
T & Fixed_Array <T, N>::operator [] (size_t index)
{
  if (index > this->cur_size_) {
    throw std::out_of_range ("Selected Index is out of range");
  } else {
    return this->data_[index]; 
  }
}

//
// operator [] 
//
template <typename T, size_t N>
const T & Fixed_Array <T, N>::operator [] (size_t index) const
{
  if (index > this->cur_size_) {
    throw std::out_of_range ("Selected Index is out of range");
  } else {
    return this->data_[index]; 
  }
}

//
// operator ==
//
template <typename T, size_t N>
bool Fixed_Array <T, N>::operator == (const Fixed_Array <T, N> & rhs) const
{
  if (&(*this) == &(rhs)) {
    return true;
  } else {
    bool isEqual = true; 
    int i = 0; 
    if (rhs.size () == this->cur_size_) { //first check for equality. == implies strictness and if the sizes aren't equal, the arrays aren't equal
      while (isEqual == true && i < this->cur_size_) {
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
template <typename T, size_t N>
bool Fixed_Array <T, N>::operator != (const Fixed_Array <T, N> & rhs) const
{
  return (!(*this == rhs));
}

