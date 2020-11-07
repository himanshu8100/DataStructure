#include<iostream>
#include <stdlib.h>
#include<string>

using namespace std;

class Stack {
  private:
    int vac;                //check if stack is vacant or not
    int arr[5];

  public:
    Stack() {
      vac = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }

  bool isEmpty() {
    if (vac == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (vac == 4)
      return true;
    else
      return false;
  }

  void push(int in) {
    if (isFull()) {
      cout << "stack overflow" << endl;
    } else {
      vac++;
      arr[vac] = in;
    }
  }

  int pop() {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      int popValue = arr[vac];
      arr[vac] = 0;
      vac--;
      return popValue;
    }
  }

  int count() {
    return (vac + 1);
  }

  int peek(int pos) {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      return arr[pos];
    }
  }

  void change(int pos, int in) {
    arr[pos] = in;
    cout << "change index " << pos << endl;
  }

  void display() {
    cout << "Values are " << endl;
    for (int i = 4; i >= 0; i--) {
      cout << arr[i] << endl;
    }
  }
};

int main() {
  Stack s1;
  int option, postion, value;

  do {
    cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Push()" << endl;
    cout << "2. Pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. peek()" << endl;
    cout << "6. count()" << endl;
    cout << "7. change()" << endl;
    cout << "8. display()" << endl;
    cout << "9. Clear Screen" << endl << endl;

    cin >> option;
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Push value" << endl;
      cin >> value;
      s1.push(value);
      break;
    case 2:
      cout << " Poped Value: " << s1.pop() << endl;
      break;
    case 3:
      if (s1.isEmpty())
        cout << "Empty stack" << endl;
      else
        cout << "Stack is not Empty" << endl;
      break;
    case 4:
      if (s1.isFull())
        cout << "Full Stack" << endl;
      else
        cout << "Stack is not Full" << endl;
      break;
    case 5:
      cout << "Enter position to peek: " << endl;
      cin >> postion;
      cout << "Value at position " << postion << " is " << s1.peek(postion) << endl;
      break;
    case 6:
      cout << "Number of Items in the Stack are: " << s1.count() << endl;
      break;
    case 7:
      cout << "Enter position of item to change : ";
      cin >> postion;
      cout << endl;
      cout << "Enter value of item to change : ";
      cin >> value;
      s1.change(postion, value);
      break;
    case 8:
      cout << "Displaying elements - " << endl;
      s1.display();
      break;
    case 9:
      system("cls");
      break;
    default:
      cout << "Enter valid number " << endl;
    }

  } while (option != 0);

  return 0;
}
