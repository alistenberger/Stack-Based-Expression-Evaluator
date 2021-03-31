#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>
#include "Array.h"

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the stack is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::exception (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & queue);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /// Overload for Array assignment operator
  const Array <T> & operator = (const Array <T> & rhs);

  /**
   * Add a new element to the end of the list
   *
   * @param[in]      element       Element to add to the queue
   */
  void enqueue (T element);

  /**
   * Removes the element at the front of the list.
   * If there are not elements in the queue, this method throws empty_exception 
   *
   * @return         T                   The element removed from the queue
   * @exception      empty_exception     The queue is empty
   */
  T dequeue (void);

  /**
   * Test if the queue is empty. 
   *
   * @retval         true         The queue is empty
   * @retval         false        The queue is not empty
   */
  bool is_empty (void) const;


  /**
   * Returns the number of elements in the queue
   *
   * @return         Size of the stack.
   */
  size_t size (void) const;

  /// Returns the max_size_ of arr_
  size_t max_size (void) const;

  /// Removes all the elements in the queue.
  void clear (void);

  /// Returns the element at arr_[index]
  T get (size_t index);

private:
    // COMMENT There is no need to allocate the array on the heap. Always try to
    // allocate on the stack to reduce the complexity of your code.
  
    //SOLUTION removed pointer here and removed allocation of Array member class
  Array <T> arr_;
  size_t current_size_;

};

#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_
