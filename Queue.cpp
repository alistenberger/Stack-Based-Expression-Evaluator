//
// Queue
//
template <typename T>
Queue <T>::Queue (void)
: arr_ (Array <T> ()),
current_size_ (0)
{

}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue <T> & queue)
: arr_ (Array <T> (queue.arr_.size ())),
current_size_ (queue.arr_.size ())
{
 for (int i = 0; i < queue.arr_.size (); i++) {
    T arrayLocation = queue.arr_.get (i);
    this->arr_.set (i, arrayLocation);
 }
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
  //Nothing allocated
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
  this->current_size_ = rhs.current_size_;
  this->arr_ = rhs.arr_;
  return *this;
}

//
//Overload = to accept Array <T>
//
template <typename T>
const Array <T> & Queue <T>::operator = (const Array <T> & rhs)
{
  this->arr_.resize (rhs.arr_.size ());
  for (int i = 0; i < rhs.arr_.size (); i++) {
    this->arr_.set (i, rhs.arr_.get (i));
  }
  return *this;
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
  this->arr_.resize ((this->current_size_ + 1));
  this->current_size_ += 1;
  this->arr_.set ((this->current_size_ - 1), element);
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
    // COMMENT This design is OK, but it is not the best design. This will be
    // a very expensive array to use if you are dequeing a lot of elements. This
    // is because you are copying N elements each time you dequeue 1 element.
    // Instead, you only want to copy element when necessary. Come up with a better
    // design that is not as expensive for the client to use.

    // SOLUTION Refactored my design for this method to reverse the Array, resize it
    // to remove the last element, and then reversing it back so it is again in the correct order
    // The array is then shrinked to remove unused elements on the end
    
  if (this->is_empty ()) {
    throw empty_exception ();
  } else {
    T returnElement = this->get (0);
    if (this->current_size_ > 1) {
      this->current_size_ -= 1;
      this->arr_.reverse ();
      this->arr_.resize (this->current_size_);
      this->arr_.reverse ();
      this->arr_.shrink ();
    } else {
      this->clear ();
    }
    return returnElement;
  }
}

//
// is_empty
//
template <typename T>
bool Queue <T>::is_empty (void) const
{
  if (this->current_size_ == 0) {
    return true;
  } else {
    return false;
  }
}

//
// size
//
template <typename T>
size_t Queue <T>::size (void) const
{
  return this->arr_.size ();
}

//
//max_size
//
template <typename T>
size_t Queue <T>::max_size (void) const
{
  return this->arr_.max_size ();
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    // COMMENT This works, but is a very expensive operation. You should find a
    // way to just reset the state without having to dequeue every element.

    // SOLUTION clear method now simply assigns arr_ to an empty array on the stack and lets garbage collection
    // handle the old one since it is no longer allocated
    
  if (!((*this).is_empty ())) {
    this->arr_ = Array <T> ();
    this->current_size_ = 0;
  }
}

template <typename T>
T Queue <T>::get (size_t index)
{
  return this->arr_.get (index);
}
