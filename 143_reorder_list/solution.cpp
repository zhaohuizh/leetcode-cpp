#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  void reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL){
      return;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast->next){
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode* start = slow;
    ListNode* last = start;
    ListNode* next = NULL;
    while(last->next) {
      next = last->next;
      last->next = next->next;
      next->next = start;
      start = next;
    }

    fast = head;
    while(start != slow) {
      next = fast->next;
      fast->next = start;
      fast = next;
      next = start->next;
      start->next = fast;
      start = next;
    }
  }
};
