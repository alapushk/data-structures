
//  Test Program 1 for Dynamic Int Queue Class
//
#include <iostream>   // for I/O facilities
#include "queue.h" //  basic_int_queue declarations
using namespace std;

int main (int argc, char * const argv[]) {
        
   bool OK = true ;
   Queue q1 ;
    cout << "queue q1 created" << endl;
   if( ! q1.empty() ) OK = false ;
   q1.enqueue(1);
    cout << "enqueue 1: ";
    q1.print();

   if( q1.empty() ) OK = false ;
   q1.enqueue(2);
    cout << "enqueue 2: ";
    q1.print();

    q1.enqueue(3);
    cout << "enqueue 3: ";
    q1.print();

   q1.enqueue(4);
    cout << "enqueue 4: ";
    q1.print();
    
    q1.enqueue(2);
    cout << "enqueue 2 again: ";
    q1.print();
    
    
cout << "Create a deep copy q2 of q1:";
   Queue q2(q1);
   q2.print();


   q2.enqueue(5);
    cout << endl << "enqueue 5 to q2: " << endl;
    cout<<"q2: ";
    q2.print();
    cout<<"q1: ";
    q1.print();

   q1.enqueue(6);
    cout << endl << "enqueue 6 to q1: " << endl;
    cout<<"q1: ";
    q1.print();
    cout<<"q2: ";
    q2.print();
    
//checking the new function:
    cout << endl << "Checking makeUnique function: " << endl;
   int num = q1.makeUnique(2);
   if( num == 1 ){
	cout << "removed " << num << " instances of 2 from q1 - GOOD!" << endl;
   }
   if( num != 1 ){
	cout << "removed " << num << " instances of 1 from q1 - BAD..." << endl;
   }
    cout << "q1: ";
   q1.print();
    cout <<"q2: ";
    q2.print();

    if( q1.front() != 1 )  {OK = false ; cout << "OK1 ";}
   q1.dequeue();
    cout << endl << "dequeue: ";
    q1.print();
   q1.dequeue();
    cout << "dequeue: ";
    q1.print();
   q1.dequeue();
    cout << "dequeue: ";
    q1.print();
   q1.dequeue();
    cout << "dequeue: ";
    q1.print();
    //q1.dequeue();
    //cout << "dequeue: ";
    //q1.print();

cout << "front_p->data is " << q1.front() << endl;

   if( q1.front() != 6 )  {OK = false ; cout << "OK2 ";}
   if( q1.dequeue() != 6 ) {OK = false ; cout << "OK3 ";}
   if( ! q1.empty() ) {OK = false ; cout << "OK4 ";}
    cout << "q1 now is";
    q1.print();
    cout << "current size of q1: " << q1.size() << endl;
    
   if( OK ){
      cout << "GOOD" << endl ;
      return 0 ;
   }else{
      cout << "BAD" << endl ;
      return -1 ;
   }
}

/*
//
//  Test Program 1 for Dynamic Int Queue Class
//
#include <iostream>   // for I/O facilities
#include "queue.h" //  basic_int_queue declarations
using namespace std;

int main (int argc, char * const argv[]) {
        
   bool OK = true ;
   Queue q1 ;
   if( ! q1.empty() ) OK = false ;
   q1.enqueue(1);
   if( q1.empty() ) OK = false ;
   q1.enqueue(2);
   q1.enqueue(3);
   q1.enqueue(4);
   if( q1.front() != 1 )  OK = false ;
   q1.dequeue();
   q1.dequeue();
   q1.dequeue();
   if( q1.front() != 4 )  OK = false ;
   if( q1.dequeue() != 4 ) OK = false ;
   if( ! q1.empty() ) OK = false ;

   if( OK ){
      cout << "GOOD" << endl ;
      return 0 ;
   }else{
      cout << "BAD" << endl ;
      return -1 ;
   }
}
*/
