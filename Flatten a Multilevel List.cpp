class Solution {
public:
    Node *getTail(Node *head){
        while(head->next){
            head=head->next;
        }
        return head;
    }
    Node* flatten(Node* head) {
        if(!head)return head;
        Node *newHead=head;
        Node *tail=NULL;
        while(head){
            if(head->child){
                tail=getTail(head);
                tail->next=head->child;
                head->child->prev=tail;
                head->child=NULL;
            }
            head=head->next;
        }
        return newHead;
    }
};
