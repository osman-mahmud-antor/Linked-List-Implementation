#include <stdio.h>
#include <string.h>

typedef struct node Node;
struct node{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node==NULL){
        printf("Error!Couldn't create a new node\n");
        exit(1);
    }
    new_node->data=item;
    new_node->next=next;

    return new_node;
}

Node *prepend(Node *head,int item){
    Node *new_node = create_node(item,head);
    return new_node;
}

Node *append(Node *head,int item){
    Node *new_node = create_node(item,NULL);
    if(head==NULL){
        return new_node;
    }
    Node *current_node = head;
    while(current_node->next!=NULL){
        current_node=current_node->next;
    }
    current_node->next=new_node;

    return head;
}

void print_linked_list(Node *head,int target){
    Node *current_node = head;
    int number_of_nodes = 0;
    int flag = 0;
    while(current_node!=NULL){
        printf("%d ",current_node->data);
        if(current_node->data==target){
            printf("Found!\n");
            flag=1;//return;
        }
        number_of_nodes++;
        current_node=current_node->next;
    }
    printf("\n");
    printf("Number of Nodes: %d\n",number_of_nodes);
    if(flag==0){
        printf("Not Found!\n");
    }
}

/*void search_for_target(Node *head,int target){
    Node *current_node = head;
    while(current_node!=NULL){
        if(current_node->data==target){
            printf("Found!\n");
            return;
        }
    }
    printf("Not Found!\n");
}*/

int main()
{
    int target;

    printf("Enter the target: ");
    scanf("%d",&target);

    Node *n1,*n2,*head,*n3;
    n1 = create_node(10,NULL);
    head = n1;
    print_linked_list(head,target);
    head = prepend(head,20);
    print_linked_list(head,target);
    head = append(head,30);
    print_linked_list(head,target);

    //search_for_target(head,target);

   return 0;
}
