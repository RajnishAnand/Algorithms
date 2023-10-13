#include <iostream>
#include <string>
#define MAX 5
using namespace std;

class Queue {
  private:
    int arr[MAX];
    int front = -1;
    int rear = -1;

    string ERROR_OVERFLOW = "Queue Overflow";
    string ERROR_UNDERFLOW = "Queue Underflow";
    string ERROR_EMPTY = "Empty Queue";
    
  public:
    bool isEmpty(){ return ((rear == -1) || (front == rear + 1)); }
    bool isFull(){return ( rear == MAX-1);}

    void enqueue(int num){
      if(isFull()) throw ERROR_OVERFLOW;
      arr[++rear] = num;
    }

    int dequeue(){
      if(isEmpty())throw ERROR_UNDERFLOW;
      return arr[front++];
    }

    int peek (){
      if(isEmpty())throw ERROR_EMPTY;
      return arr[front];
    }

    string print(){
      if(isEmpty())throw ERROR_EMPTY;
      string str = "[ ";
      for (int i = front; i< rear; i++) str += to_string(i) + ", ";
      str+= "]";
      return str;
    }

};

void displayMenu(string message){
  system("clear");
  cout << "###########################"
    << "\n#  Queue Implimentation   #"
    << "\n###########################"
    << "\n\n  1: Enqueue: add element to queue"
    << "\n  2: Dequeue: delete an element from queue"
    << "\n  3: Seek: display front element from queue"
    << "\n  4: Exit\n\n"
    << message
    << "\nEnter your selection: "

  ;
}

int main (int argc, char *argv[]) {
  displayMenu("message: heeheh");
  return 0;
}
