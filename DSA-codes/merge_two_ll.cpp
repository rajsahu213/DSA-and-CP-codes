struct node{
    int data;
    node *next;
};

node *start1=NULL;
node *start2=NULL;

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    node *tempA =(node*) head1;
    node *tempB =(node*) head2;
    int countA = 0;
    int countB = 0;
        // finding the longer linked list.
    while (tempA->next != nullptr) {
        tempA = tempA->next;
        countA++;
    }
    while (tempB->next != nullptr) {
        tempB = tempB->next;
        countB++;
    }
    node *temp1 = nullptr;
    node *temp2 = nullptr;
    node *temp = nullptr;
        // connect the tail of the longer linked list to the head of the longer link list.
    if (countA > countB) {
        tempA->next =(node*) head1;
        temp1 =(node*) head2;
        temp2 =(node*) head2;
        temp =(node*) head2;
    } else {
        tempB->next =(node*) head2;
        temp1 = (node*)head1;
        temp2 =(node*)head1;
        temp = (node*)head1;
    }
        
        // start two pointers from the head of the shorter linked list to find where they meet in the cycle
    do {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    } while (temp1 != temp2);

        // reset one of the pointers to the head of the shorter linked list and move both the pointers one step at a time.
    while (temp != temp1) {
        temp = temp->next;
        temp1 = temp1->next;
    }
        // return the new node where both the pointers meet now.
    return temp1->data;
}