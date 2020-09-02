#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next;
    int value;
} Node;

Node* create_Node(){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->value = 0;
    return new_node;
}

typedef struct linked_list{
    struct Node* Root;
} Linked_list;

Linked_list* create_linked_list(){
    Linked_list* new_list = (Linked_list*)malloc(sizeof(Linked_list));
    new_list->Root = create_Node();
    return new_list;
}

void print_list(Linked_list* list){
    int index = 0;
    Node* head = list->Root;
    while (head->next != NULL){
        head = head->next;
        printf("The element at index %d has value %d.\n", index++, head->value);
    }
    puts("");
}

Node* get_element_at_index(int index, Node* root){
    Node* head = root;
    for(int i=0;i<index;i++){
        if(head->next == NULL)
            return NULL;
        head = head->next;
    }

    return head;

}

void insert_node(int index, int value, Linked_list* list){

    Node* root = list->Root;

    Node* previous = get_element_at_index(index, root);
    if(previous == NULL)
        return;

    Node* cur = create_Node();
    cur->value = value;
    cur->next = previous->next;
    previous->next = cur;

}

void delete_node(int value, Linked_list* list){

    Node* root = list->Root;
    while (root->next != NULL){
        if(root->next->value == value){
            root->next = root->next->next;
            Node* deleted = root->next;
            free(deleted);
            return;
        }
        root = root->next;
    }
    printf("The element %d is not in the list.\n", value);
}

int main() {
    Linked_list* list = create_linked_list();
    insert_node(0, 5, list);
    insert_node(1, 10, list);
    print_list(list);

    insert_node(0, 6, list);
    print_list(list);

    insert_node(2, 11, list);
    print_list(list);

    delete_node(5, list);
    print_list(list);

    delete_node(6, list);
    print_list(list);

    delete_node(10, list);
    print_list(list);

    delete_node(11, list);
    print_list(list);

    delete_node(13, list);
    print_list(list);
}
