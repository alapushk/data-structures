/* File: char_stack.h

  Header file for a very basic array-based implementation of a stack.

*/
class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop(); 
    char top();
    bool empty();
    int size();
    //void print();

  private:
    static const int capacity = 1000;   //array size
    char A[capacity];   //the array for stack
    int top_index;
};
