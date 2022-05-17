#include <stdio.h>
#include <stdlib.h>

 struct Node{
    struct{
        int value;
    }private;
    struct Node* next;
};

struct Node* CreateNode(void* ptr, int value, void* next_ptr){
    if(ptr==NULL){
        ptr = malloc(sizeof(struct Node));
        if(ptr==NULL) {
            printf("Can not create Node\n");
            return NULL;
        }
    }
    struct Node* newNode = (struct Node*) ptr;
    newNode->next = (struct Node*) next_ptr;
    newNode->private.value = value;
    return newNode;
}

struct List{
    struct{
        struct Node* head;
        struct Node* tail;
        int size;
    }private;
    int (*empty)(struct List* this);
    int (*getSize)(struct List* this);
    void (*addHead)(struct List* this ,int value);
    void (*addTail)(struct List* this ,int value);
    void (*addPosition)(struct List* this ,int value, int pos);
    void (*deletePosition) (struct List* this, int pos);
    void (*clear)(struct List* this);
    void (*display)(struct List* this);
};

int empty(struct List* this){
    return (this->private.size == 0)? 1 : 0;
}

int getSize(struct List* this){
    return this->private.size;
}

void addHead(struct List* this, int value){
    if(this->empty(this)){
        this->private.head = this->private.tail = CreateNode(NULL, value, NULL);
    }else{
        this->private.head = CreateNode(NULL, value, this->private.head);
    }
    this->private.size++;
}

void addTail(struct List* this, int value){
    if(this->empty(this)){
        this->private.head = this->private.tail = CreateNode(NULL, value, NULL);
    }else{
        this->private.tail->next = CreateNode(NULL, value, NULL);
        this->private.tail = this->private.tail->next;
    }
    this->private.size++;
}

void addPosition(struct List* this, int value, int pos){
    if(this->getSize(this) < pos){
        printf("Can not add new element (ERROR: OUT OF RANGE!!!)\n");
        return;
    }else if(!pos){
        this->addHead(this, value);
    }else if(this->getSize(this) == pos){
        this->addTail(this, value);
    }else{
        int index = 0;
        struct Node* curr = this->private.head;
        struct Node* prev = NULL;
        while(index != pos){
            index++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = CreateNode(NULL, value, curr);
        this->private.size++;
    }
}

void deletePosition(struct List* this, int pos){
    if(this->getSize(this) < pos){
        printf("Can not delete element (ERROR: OUT OF RANGE!!!)\n");
        return;
    }else if(!pos){
        struct Node* curr = this->private.head;
        this->private.head = this->private.head->next;
        free(curr);
    }else{
        int index = 0;
        struct Node* curr = this->private.head;
        struct Node* prev = NULL;
        while(index != pos){
            index++;
            prev = curr;
            curr = curr->next;
        }
        if(pos == this->getSize(this) - 1){
            this->private.tail = prev;
        }
        prev->next = curr->next;
        free(curr);
    }
    this->private.size--;
}

void clear(struct List* this){
    printf("Clearing...\n");
    if(this->empty(this)){
        printf("Done!!!\n");
    }else{
        struct Node* temp = this->private.head;
        this->private.tail = NULL;
        free(this->private.tail);
        while(this->private.size){
            this->private.size--;
            this->private.head = this->private.head->next;
            free(temp);
            temp = this->private.head;
        }
        free(this->private.head);
        printf("Done!!!\n");
    }
}

void display(struct List* this){
    if(this->empty(this)){
        printf("Nothing to print, List is empty\n");
    }else{
        printf("Size of List: %d \n", this->private.size);
        struct Node* curr = this->private.head;
        while(curr != NULL){
            printf("%d", curr->private.value);
            printf("->");
            curr = curr->next;
        }
        printf("End List\n");
    }
}

struct List* CreateList(void* ptr){
    if(ptr==NULL){
        ptr = malloc(sizeof(struct List));
        if(ptr==NULL) {
            printf("Can not create List\n");
            return NULL;
        }
    }
    struct List* newList = (struct List*) ptr;
    newList->private.head = (struct Node*) NULL;
    newList->private.tail = newList->private.head;
    newList->private.size = 0;
    newList->empty = &empty;
    newList->getSize = &getSize;
    newList->addHead = &addHead;
    newList->addTail = &addTail;
    newList->addPosition = &addPosition;
    newList->deletePosition = &deletePosition;
    newList->clear = &clear;
    newList->display = &display;
    return newList;
}


int main() {
    struct List *l;
    l = (struct List*) CreateList(NULL);
    l->display(l);
    l->addPosition(l,4, 0);
    l->addPosition(l,3, 0);
    l->addHead(l,2);
    l->addHead(l,1);
    l->addHead(l,0);
    l->display(l);
    l->addTail(l, 5);
    l->addTail(l, 7);
    l->addPosition(l,6, 6);
    l->addPosition(l,8, 8);
    l->display(l);
    l->addPosition(l,10, 3);
    l->display(l);
    l->deletePosition(l, 3);
    l->deletePosition(l, 8);
    l->display(l);
    l->deletePosition(l, 0);
    l->display(l);
    l->addTail(l, 5);
    l->display(l);
    l->clear(l);
    return 0;
}
