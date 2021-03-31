// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
  return (*this)->current_size_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
  if ((*this)->is_empty ()) {
    throw empty_exception ("The stack is empty");
  } else {
    Array <T> array = this->arr_;
    size_t lastElement = array.size () - 1;
    return array.get (lastElement);
  }
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
  if ((*this)->current_size_ == 0) {
    return true;
  } else {
    return false;
  }
}
