#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node * next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


Node * findMiddle(Node * head){
    Node * slow = head;
    Node * fast = head->next;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
Node * mergeLL(Node * list1 , Node * list2){
    Node * dummyNode = new Node(-1);
    
    Node * temp = dummyNode;
    
    while(list1 && list2){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1=list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next ;
        }
    }
    
    if(list1){
        temp->next = list1;
    }
    
    if(list2){
        temp->next = list2;
    }
    
    return dummyNode->next;
}
Node * divideLL(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node * middle = findMiddle(head);
    
    Node * left,*right;
    left = head;
    right = middle->next;
    middle->next = NULL;
    
    left = divideLL(left);
    right = divideLL(right);
    
    return mergeLL(left,right);
}

Node* mergeSort(Node* head) {
    // code here
    
    return divideLL(head);
}


int main(){
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = mergeSort(head);

    cout << "Sorted Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}