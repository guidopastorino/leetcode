#include <iostream>
using namespace std;

/*
  02. ADD TWO NUMBERS
  in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
  You may assume the two numbers do not contain any leading zero, except the number 0 itself.

  - Example:
  l1: 2 -> 4 -> 3
  l1: 5 -> 6 -> 4
  result: 7 -> 0 -> 8

  Explaination: 342 + 465 = 807.

  Time complezity: O(n), because we traverse the list once
  Space complezity: O(n), we create a new linked list to storage the result, which could have n nodes
*/

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {};
};

class Solution{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr){
      int x = (l1 != nullptr) ? l1->val : 0;
      int y = (l2 != nullptr) ? l2->val : 0;
      int sum = x + y + carry;
      carry = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;
      if(l1 != nullptr) l1 = l1->next;
      if(l2 != nullptr) l2 = l2->next;
    }
    if(carry > 0){
      current->next = new ListNode(carry);
    }
    return dummyHead->next;
  }
};

int main(){
  ListNode* l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode* l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  Solution solution;

  ListNode* sum = solution.addTwoNumbers(l1, l2);

  while(sum != nullptr){
    cout << sum->val;
    if(sum->next != nullptr){
      cout << " -> ";
    }
    sum = sum->next;
  }
  cout << endl;

  return 0;
}