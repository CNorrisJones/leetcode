#include <cstddef>
#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
    ListNode* markerNode = NULL;
    ListNode* mergedNodes = NULL;

    while (l1 || l2) {
        if (l1==NULL) {
            if (mergedNodes==NULL) {
                mergedNodes = l2;
                l2 = NULL;
            } else {
                markerNode->next = l2;
                l2 = NULL;
            }
        } else if (l2==NULL) {
            if (mergedNodes==NULL) {
                mergedNodes = l1;
                l1 = NULL;
            } else {
                markerNode->next = l1;
                l1 = NULL;
            }
        } else if (l1->val <= l2->val) {
            if (mergedNodes == NULL) {
                mergedNodes = l1;
                markerNode = l1;
                l1 = l1->next;
            } else {
                markerNode->next = l1;
                markerNode = markerNode->next;
                l1 = l1->next;
            }
        } else {
            if (mergedNodes == NULL) {
                mergedNodes = l2;
                markerNode = l2;
                l2 = l2->next;
            } else {
                markerNode->next = l2;
                markerNode = markerNode->next;
                l2 = l2->next;
            }
        }
    }
    return mergedNodes;
}

int main() {
     ListNode list1 = ListNode(1);
     ListNode list2 = ListNode(3);
     ListNode list3 = ListNode(4);
     ListNode list4 = ListNode(1);
     ListNode list5 = ListNode(2);
     ListNode list6 = ListNode(3);

     list1.next = &list2;
     list2.next = &list3;

     list4.next = &list5;
     list5.next = &list6;

     std::cout << "Test Working" << std::endl;
     ListNode* mergedNodes = mergeTwoList(&list1, &list4);
}