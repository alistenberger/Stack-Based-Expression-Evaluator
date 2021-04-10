// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
: arr_ (Array <T> ()),
current_size_ (0)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
: arr_ (Array <T> (stack.arr_.size ())),
current_size_ (stack.arr_.size ())
{
 for (int i = 0; i < stack.arr_.size (); i++) {
    T arrayLocation = stack.arr_.get (i);
    this->arr_.set (i, arrayLocation);
 }
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
  std::cout << "deleting stack" << std::endl;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
  this->arr_.append (element);
  this->current_size_ += 1;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
  if (this->is_empty ()) {
    throw empty_exception ();
  } else {
      // COMMENT There is no need to create a copy of the array just to pop and element
      // from the stack.

      // SOLUTION Copy of the array is no longer created, operation is performed on member array instead.
      
    if (this->current_size_ >= 2) {
      this->current_size_ -= 1;
      this->arr_.resize (this->current_size_);
      this->arr_.shrink ();
      size_t newLastElement = this->current_size_ - 1;
      for (int i = 0; i <= newLastElement; i++) {
        this->arr_.set (i, this->arr_.get (i));
      }
    } else {
      this->current_size_ -= 1;
      this->arr_.resize (this->current_size_);
      this->arr_.shrink ();
    }
  }  
}

//
//is_empty
//
template <typename T>
bool Stack <T>::is_empty (void) const
{
  if (this->current_size_ == 0) {
    return true;
  } else {
    return false;
  }
}

//
// top
//
template <typename T>
T Stack <T>::top (void) const
{
  if (this->is_empty ()) {
    throw empty_exception ();
  } else {
    size_t lastElement = this->current_size_ - 1;
    return this->arr_.get (lastElement);
  }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
  this->current_size_ = rhs.current_size_;
  this->arr_ = rhs.arr_;
  return *this;
}

//
//Overload = to accept Array <T>
//
template <typename T>
const Array <T> & Stack <T>::operator = (const Array <T> & rhs)
{
  this->arr_.resize (rhs.arr_.size ());
  for (int i = 0; i < rhs.arr_.size (); i++) {
    this->arr_.set (i, rhs.arr_.get (i));
  }
  return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    // COMMENT Just reset the variables instead popping each element, which
    // is expensive.

    //SOLUTION Since array is no longer allocated, arr_ is now assigned to an empty array created on the stack
    //and garbage collection takes care of the old one
    
  if (!this->is_empty ()) {
    this->arr_ = Array <T> ();
    this->current_size_ = 0;
  }
}

//
//get
//
template <typename T>
T Stack <T>::get (size_t index)
{
  return this->arr_.get (index);
}

//
//size
//
template <typename T>
size_t Stack <T>::size (void) const {
  return this->arr_.size ();
}

/// Returns the max_size_ of arr_
template <typename T>
size_t Stack <T>::max_size (void) const {
  return this.arr_.max_size ();
}