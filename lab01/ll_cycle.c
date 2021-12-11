#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    if (head == NULL) {
        return 0;
    }

// Start with two pointers at the head of the list. We’ll call the first one tortoise and the second one hare.
// Advance hare by two nodes. If this is not possible because of a null pointer, we have found the end of the list, and therefore the list is acyclic.
// Advance tortoise by one node. (A null pointer check is unnecessary. Why?)
// If tortoise and hare point to the same node, the list is cyclic. Otherwise, go back to step 2.


    // 快慢指针，都是node * 
    node *slow, *fast;
    slow = fast = head;

    while (1) 
    {
        fast = fast->next;
        if (fast == NULL) return 0;
        fast = fast->next;
        if (fast == NULL) return 0;
        slow = slow ->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
    


    // while (1) {
    //     fast = fast->next;
    //     if (fast == NULL) {
    //         return 0;
    //     }
    //     fast = fast->next;
    // 	if (fast == NULL) return 0;
    //     slow = slow->next;
    //     if (fast == slow) {
    //         return 1;
    //     }
    // }
    // return 0;


}