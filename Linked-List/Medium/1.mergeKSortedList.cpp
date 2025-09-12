#include<iostream>
using namespace std;
#include<queue>

struct Node {
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
priority_queue<int, vector<int>, greater<int>> minHeap;


   Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if(arr.size()==1)return arr[0];
        
        priority_queue<pair<int,Node *>,vector<pair<int,Node *>>,greater<pair<int,Node *>> >q;
       
        for(int i=0; i<arr.size(); i++)
        {
            Node *temp = arr[i];
            while(temp)
            {
                q.push({temp->data,temp});
                temp = temp->next;
            }
        }
        Node * head = NULL;
        Node * curr= NULL;
        while(!q.empty())
        {
           if(head==NULL)
           {
               head = curr = q.top().second;
               q.pop();
           }
           else
           {
               curr->next = q.top().second;
               q.pop();
               curr = curr->next;
           }
        }
        return head;
    }
int main(){
    vector<Node*> arr;
    // Create sample linked lists and add them to the vector
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);
    arr.push_back(list1);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);
    arr.push_back(list2);

    Node* list3 = new Node(2);
    list3->next = new Node(6);
    arr.push_back(list3);

    Node* mergedList = mergeKLists(arr);
    // Print the merged linked list
    Node* curr = mergedList;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}