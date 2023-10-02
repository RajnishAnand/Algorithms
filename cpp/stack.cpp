// Stack implimentation

#include <iostream>
#include <string>

using namespace std;
#define MAX 5

class Stack {
  private: 
    string ERROR_OVERFLOW = "\nStack overflow: Stack is already Full";
    string ERROR_UNDERFLOW = "\nStack Underflow: stack is already Empty";
    string ERROR_EMPTY_STACK = "\nEmpty Stack: stack has no elements";
    int stack_arr[MAX];

  public: 
    int top = -1;
    bool isFull(){return top>=(MAX-1); }
    bool isEmpty(){return top<0;}

    void push(int el){
      if(isFull()) throw ERROR_OVERFLOW;
      stack_arr[++top]=el;
    }

    int pop (){
      if(isEmpty()) throw ERROR_UNDERFLOW;
      return stack_arr[top--];
    }

    int getTopElement(){
      if(isEmpty())throw ERROR_EMPTY_STACK;
      return stack_arr[top];
    }

    string displayStack (){
      string stack = "[ ";
      for (int i= 0; i<=top;i++)stack += (to_string(stack_arr[i]) + ", ");
      stack += "]";
      return stack;
    }
};

void displayMenu(string message){
  system("cls");
  cout << "#############################"
    << "\n#   Stack Implimentation    #"
    << "\n#############################"
    << "\n\n  1 : Push an Element to stack"
    << "\n  2 : Pop an Element from stack"
    << "\n  3 : Print Top Element"
    << "\n  4 : Exit\n\n"
    << message 
    << "\nEnter your selection: ";
}

int main(){
  string message = "";
  Stack stack;

  while (true) {
    string stackPreview = "Current Stack: "+stack.displayStack()+"\n";
    displayMenu(stackPreview+message);
    int selection;
    cin >> selection;

    switch (selection){
      case 1: 
        cout << "Enter number: ";
        int el; 
        cin >> el;
        try {
          stack.push(el);
          message = "\nPushed: "+ to_string(el);
        } 
        catch(string err){ message = err; } 
        break;

      case 2: 
        try { message = "\nPopped: " + to_string( stack.pop() ); }
        catch (string err){ message = err; }
        break;

      case 3: 
        try{ message = "Top Element: "+to_string( stack.getTopElement() ); }
        catch(string err){ message = err; }
        break;

      case 4:
        return 0;
    }
  }
}
