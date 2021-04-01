#include <iostream>
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Array.h"
#include "Base_Array.h"
#include <assert.h>

void test_array ()
{
  Array <char> a1;
  a1.resize (5);
  a1.set (0, 'a');
  a1.set (1, 'b');
  a1.set (2, 'c');
  a1.set (3, 'd');
  a1.set (4, 'e');
  assert (a1.size () == 5);
  assert (a1.get (2) == 'c');
  a1.reverse ();
  assert (a1.get (0) == 'e');
  Array <char> newArr = a1.slice (1, 2);
  assert (newArr.get (0) == 'd');
  assert (a1 != newArr);
  Array <char> a2 = Array <char> (a1);
  assert (a1 == a2);
}

void test_queue ()
{  
  Queue <char> q1;
  q1.enqueue ('w'); 
  assert (q1.get (0) == 'w');
  assert (q1.dequeue () == 'w');
  assert (q1.is_empty ());
  q1.enqueue ('x');
  q1.enqueue ('y');
  Queue <char> q2 = Queue <char> (q1);
  Queue <char> q3 = q2;
  assert (q1.dequeue () == 'x');
  assert (q1.dequeue () == 'y');
  assert (q1.is_empty ());
  assert (q2.dequeue () == 'x');
  assert (q2.dequeue () == 'y');
  assert (q2.is_empty ());
  assert (q3.dequeue () == 'x');
  assert (q3.dequeue () == 'y');
  assert (q3.is_empty ());
}

void test_stack ()
{
  Stack <int> s1;
  s1.push (7);
  assert (s1.get (0) == 7);
  s1.push (5);
  assert (s1.top () == 5);
  Stack <int> s2 = Stack <int> (s1);
  Stack <int> s3 = s2;
  assert (s3.top () == 5);
  assert (s2.top () == 5);
  s1.pop ();
  s2.pop ();
  s3.pop ();
  assert (s1.top () == 7);
  assert (s2.top () == 7);
  assert (s3.top () == 7);
  s1.pop ();
  s2.pop ();
  s3.pop ();
  assert (s1.is_empty ());
  assert (s2.is_empty ());
  assert (s3.is_empty ());
}

void test_fixed_array () {
  Fixed_Array <char, 7> f1;
  f1.fill ('a');
  assert (f1.get (2) == 'a');
  assert (f1[4] == 'a');
  f1.set (1, 'b');
  f1.set (2, 'c');
  f1.set (3, 'd');
  f1.set (4, 'e');
  f1.set (5, 'f');
  f1.set (6, 'g');
  assert (f1.find ('c') == 2);
  assert (f1.find ('f', 6) == -1);
  Fixed_Array <char, 7> f2 = Fixed_Array <char, 7> (f1);
  assert (f1 == f2);
  Fixed_Array <char, 7> f3 = Fixed_Array <char, 7> ('g');
  assert (f2 != f3);
}

int main (int argc, char * argv []) {
  std::cout << "Compiled successfully" << std::endl;
  test_queue ();
  std::cout << "Queue test successful" << std::endl;
  test_stack ();
  std::cout << "Stack test successful" << std::endl;
  test_fixed_array ();
  std::cout << "Fixed array test successful" << std::endl;
  test_array ();
  std::cout << "Array test successful" << std::endl;
  return (0);
}