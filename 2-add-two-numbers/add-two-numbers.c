/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l1_parcours = l1;
    struct ListNode* l2_parcours = l2;
    struct ListNode* output = NULL;
    struct ListNode* Construct = NULL;
    int cost_next = 0;

    while (l1_parcours != NULL || l2_parcours != NULL || cost_next != 0){
        
        // Creation of the new node and assigning it's values and advance the reding of the lists 
        struct ListNode* new_node=malloc(sizeof(struct ListNode));
        new_node->next = NULL;
        if (l1_parcours == NULL && l2_parcours == NULL){
            new_node->val = 1;
            cost_next = 0;
        }
        else if (l1_parcours == NULL){
            new_node->val = l2_parcours->val + cost_next;
            cost_next = 0;
            l2_parcours = l2_parcours->next;
        }
        else if (l2_parcours == NULL){
            new_node->val = l1_parcours->val + cost_next;
            cost_next = 0;
            l1_parcours = l1_parcours->next;
        }
        else{
            new_node->val = l1_parcours->val + l2_parcours->val + cost_next;
            cost_next = 0;
            l1_parcours = l1_parcours->next;
            l2_parcours = l2_parcours->next;
        }

        // The value in the node should not exceed 10
        // Add the rest to the next node 
        if (new_node->val >= 10){
            cost_next = 1;
            new_node->val = (new_node->val) - 10;
        }

        //Add the new node to the liked list: output
        if (output == NULL){
            output = new_node;
            Construct = output;
        }
        else {
            Construct->next = new_node;
            Construct = Construct->next;
        }

    }

    return output;
}