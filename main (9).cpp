/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};
//insert
void insertAtBeginning(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  new_node->data = new_data;
  new_node->next = (*head_ref);

  (*head_ref) = new_node;
}

//delete
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }

  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  
  if (temp == NULL) return;

  prev->next = temp->next;

  free(temp);
}


//search
bool searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;

  while (current != NULL) {
  if (current->data == key) return true;
  current = current->next;
  }
  return false;
}

//sort
void sortLinkedList(struct Node** head_ref) {
  struct Node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
  return;
  } else {
  while (current != NULL) {
    
    index = current->next;

    while (index != NULL) {
    if (current->data > index->data) {
      temp = current->data;
      current->data = index->data;
      index->data = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
}

//print
void printList(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}


int main()
{
    struct Node* head = NULL;
    
    int ch;
    cout<<"enter your choice"<<endl;
    cin>>ch;
    
    /*do{
    
    switch (ch){
        
        case 1:
        int n;
        int b;
        cout<<"enter the number of elements to be added "<<endl;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>b;
            insertAtBeginning(&head, b);
        }
        cout<<"elements added"<<endl;
        printList(head);
        cout<<endl;
            break;
        
        case 2:
    
        int a;
        cout<<"enter element to be deleted from the linked list "<<endl;
        cin>>a;
        deleteNode(&head, a);
        cout<<"elements deleted"<<endl;
        printList(head);
        cout<<endl;
            break;
        
        case 3:
    
        sortLinkedList(&head);
        cout<<"sorted linked list"<<endl;
        printList(head);
        cout<<endl;
    
            break;
        
        case 4:
    
        int m;
        cout<<"enter element to search "<<endl;
        cin>>m;
    
        int item_to_find = m;
        if (searchNode(&head, item_to_find))
        {
        cout<<item_to_find<<"element found";
        } 
        else 
        {
        cout<<item_to_find<<"element not found";
        }
    
            break;
        
        //case 5:
        //cout<<"exit"<<endl;
        //break;
    
    }
    } while(ch!=4);
    */
    
    do{
    int x = 2;
    switch (x) {
    case 1:
        int n;
        int b;
        cout<<"enter the number of elements to be added "<<endl;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>b;
            insertAtBeginning(&head, b);
        }
        cout<<"elements added"<<endl;
        printList(head);
        cout<<endl;
        
        break;
    case 2:
        int a;
        cout<<"enter element to be deleted from the linked list "<<endl;
        cin>>a;
        deleteNode(&head, a);
        cout<<"elements deleted"<<endl;
        printList(head);
        cout<<endl;
        break;
    case 3:
        sortLinkedList(&head);
        cout<<"sorted linked list"<<endl;
        printList(head);
        cout<<endl;
        break;
    case 4:
                int m;
        cout<<"enter element to search "<<endl;
        cin>>m;
    
        int item_to_find = m;
        if (searchNode(&head, item_to_find))
        {
        cout<<item_to_find<<"element found";
        } 
        else 
        {
        cout<<item_to_find<<"element not found";
        }
    case 5:
        cout<<"exit";
        break;
    }
    } while(ch!=5);
    return 0;
}
