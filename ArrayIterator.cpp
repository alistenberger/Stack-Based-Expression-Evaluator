//
//Initializing constructor
//
template <typename T> 
ArrayIterator <T>::ArrayIterator (Array <T> & array) 
: array_ (array), 
index_ (0) 
{
//Nothing here
} 

//
//Destructor
//
template <typename T> 
ArrayIterator <T>::~ArrayIterator (void)
{
//Nothing allocated
}

//
//Method to check if iteration has reached end
//
template <typename T> 
bool ArrayIterator <T>::isDone (void) 
{ 
  return this->index_ >= this->array_.size (); 
}

//
//Method to advance iterator to next element in Array
//
template <typename T> 
void ArrayIterator <T>::advance (void) 
{
  if (!this->isDone ()) { 
    ++ this->index_;
  } 
} 

//
//Overload for * Operator
//
template <typename T> 
T & ArrayIterator <T>::operator * (void) 
{ 
  return this->array_[this->index_];
}

//
//Overload for -> operator
//
template <typename T> 
T * ArrayIterator <T>::operator -> (void) 
{ 
  return &this->array_.data_[this->index_]; 
} 