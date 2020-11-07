#include<iostream>
#include<stdlib.h>

using namespace std;

class Node {
  public:
  int indx;     // index or key value
  int data;     // data stored in pointer
  Node * next;  // address of next pointer

  //Constructor
  Node() {
    indx = 0;
    data = 0;
    next = NULL;
  }
  Node(int i, int d) {
    indx = i;
    data = d;
  }
};

class SLinkedList {
  public:
    Node * head;

  SLinkedList() {
    head = NULL;
  }
  SLinkedList(Node * n) {
    head = n;
  }

  // 1. Checks if node exists with index value
  Node * Exits(int i) {
    Node * temp = NULL;

    Node * ptr = head;
    while (ptr != NULL) {
      if (ptr -> indx == i) {
        temp = ptr;
      }
      ptr = ptr -> next;

    }
    return temp;
  }

  // 2. Append
  void append(Node * n) {
    if (Exits(n -> indx) != NULL) {
      cout << "Node already exist." << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Appended" << endl;
      } else {
        Node * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        cout << "Node Appended" << endl;
      }
    }
  }

  // 3. Prepend Node
  void prepend(Node * n) {
    if (Exits(n -> indx) != NULL) {
      cout << "Node already exists." << endl;
    } else {
      n -> next = head;
      head = n;
      cout << "Node Prepended" << endl;
    }
  }

  // 4. Insert a Node after particular index
  void insertat(int i, Node * n) {
    Node * ptr = Exits(i);
    if (ptr == NULL) {
      cout << "No node exists with index value: " << i << endl;
    } else {
      if (Exits(n -> indx) != NULL) {
        cout << "Node already exists." << endl;
      }
      else {
        n -> next = ptr -> next;
        ptr -> next = n;
        cout << "Node Inserted" << endl;
      }
    }
  }

  // 5. Delete node by index
  void deleteindx(int i) {
    if (head == NULL) {
      cout << "Singly Linked List already Empty. Cant delete" << endl;
    } else if (head != NULL) {
      if (head -> indx == i) {
        head = head -> next;
        cout << "Node UNLINKED with indxs value : " << i << endl;
      } else {
        Node * temp = NULL;
        Node * prevptr = head;
        Node * currentptr = head -> next;
        while (currentptr != NULL) {
          if (currentptr -> indx == i) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }
        if (temp != NULL) {
          prevptr -> next = temp -> next;
          cout << "Node UNLINKED with indxs value : " << i << endl;
        } else {
          cout << "Node Doesn't exist with indx value : " << i << endl;
        }
      }
    }

  }
  // 6. update node
  void updateNode(int i, int d) {

    Node * ptr = Exits(i);
    if (ptr != NULL) {
      ptr -> data = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with indx value : " << i << endl;
    }

  }

  // 7. printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List";
    } else {
      cout << endl << "Singly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp -> indx << "," << temp -> data << ") --> ";
        temp = temp -> next;
      }
    }

  }

};

int main() {

  SLinkedList s;
  int option;
  int indx1, i1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. append()" << endl;
    cout << "2. prepend()" << endl;
    cout << "3. insertat()" << endl;
    cout << "4. deleteindx()" << endl;
    cout << "5. updateNode()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter indx & data of the Node to be Appended" << endl;
      cin >> indx1;
      cin >> data1;
      n1 -> indx = indx1;
      n1 -> data = data1;
      s.append(n1);
      //cout<<n1.indx<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter indx & data of the Node to be Prepended" << endl;
      cin >> indx1;
      cin >> data1;
      n1 -> indx = indx1;
      n1 -> data = data1;
      s.prepend(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter indx of existing Node after which you want to Insert this New node: " << endl;
      cin >> i1;
      cout << "Enter indx & data of the New Node first: " << endl;
      cin >> indx1;
      cin >> data1;
      n1 -> indx = indx1;
      n1 -> data = data1;

      s.insertat(i1, n1);
      break;

    case 4:

      cout << "Delete Node By indx Operation - \nEnter indx of the Node to be deleted: " << endl;
      cin >> i1;
      s.deleteindx(i1);

      break;
    case 5:
      cout << "Update Node By indx Operation - \nEnter indx & NEW data to be updated" << endl;
      cin >> indx1;
      cin >> data1;
      s.updateNode(indx1, data1);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
