#include <iostream>
#include <map>

using namespace std;

class Node {
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

Node *removeDuplicates(Node *head) {
  if (head == NULL) {
    return head; // Handle empty list case
  }

  map<int, bool> visited; // Use map with data (int) as key
  Node *prev = head, *curr = head;
  

  while (curr != NULL) {
    int data = curr->data; // Extract data for efficient comparison

    if (!visited.count(data)) {        // Check if data is not seen before (using count)
      visited[data] = true; // Mark data as seen
      prev = curr;          // Update prev for next iteration
    } else {
      Node *deleteNode = curr;
      prev->next = curr->next;
      delete deleteNode;
    }
	prev = curr;
    curr = curr->next; // Move to the next node
  }

  return head;
}

void InsertAtTail(Node* &h, Node* &t, int data) {
  if (!h) {
    h = new Node(data);
    t = h;
    return;
  }
  Node* temp = new Node(data);
  t->next = temp;
  t = temp;
}

void print(Node* head) {
  if (head == nullptr) {
    cout << "List is empty." << endl;
    return;
  }

  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Node* head = nullptr, *tail = nullptr;

  InsertAtTail(head, tail, 3);
  InsertAtTail(head, tail, 2);
  InsertAtTail(head, tail, 3);
  InsertAtTail(head, tail, 4);
  InsertAtTail(head, tail, 2);
  InsertAtTail(head, tail, 3);
  InsertAtTail(head, tail, -1);

  cout << "Linked List before removing duplicates:";
  print(head);

  cout << "Linked List after removing duplicates:";
  head = removeDuplicates(head);
  print(head);

  return 0;
}
