// Add 2 numbers defined with reversed digits in a linked list
// https://leetcode.com/problems/add-two-numbers/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 

struct ListNode* convertIntToLinkedList(int n){
    struct ListNode* res = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* tmp = res;

    while (true){
        int digit = n % 10; // extract the last digit
        tmp->val = digit;

        // remove the last digit
        n /= 10;

        if(n == 0){
            tmp->next = NULL;  // Ensure the last node points to NULL
            break;
        }

        // Allocate next node
        tmp->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        tmp = tmp->next;
    }
    return res;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l1Traverser = l1;
    struct ListNode* l2Traverser = l2;

    struct ListNode* res = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* resTraverser = res;

    int carry = 0;
    while(l1Traverser || l2Traverser || carry){
        int sum = 0;
        if(l1Traverser){
            sum += l1Traverser->val;
            l1Traverser = l1Traverser->next;
        }

        if(l2Traverser){
            sum += l2Traverser->val;
            l2Traverser = l2Traverser->next;
        }

        sum += carry;

        if(sum > 9){
            carry = sum / 10; // automatically floored
            sum %= 10;
        } else {
            carry = 0;
        }

        resTraverser->val = sum;
        if(l1Traverser || l2Traverser || carry){
            resTraverser->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            resTraverser = resTraverser->next;
        } else {
            resTraverser->next = NULL;
        }
    }

    return res;
}

void printFreeLinkedList(struct ListNode* list) {
    struct ListNode* tmp = list;
    struct ListNode* next;

    while (tmp != NULL) {
        next = tmp->next;
        printf("%d", tmp->val);
        free(tmp);
        tmp = next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    // Create first linked list: 2 -> 4 -> 3
    struct ListNode* l1 = (struct ListNode*) malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    // Create second linked list: 5 -> 6 -> 4
    struct ListNode* l2 = (struct ListNode*) malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    // Add the two numbers
    struct ListNode* res = addTwoNumbers(l1, l2);

    // Print and free the result linked list
    printFreeLinkedList(res);

    // Free the input linked lists
    printFreeLinkedList(l1);
    printFreeLinkedList(l2);

    return 0;
}

