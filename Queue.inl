//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
  return this->current_size_;
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
  if (this->size () == 0) {
    return true;
  } else {
    return false;
  }
}