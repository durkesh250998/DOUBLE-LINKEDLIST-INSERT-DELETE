#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void specified();
void begin();
void end();
void delete_b();
void delete_e();
void delete_s();
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *next=NULL;
struct node *prev=NULL;
struct node *new=NULL;
struct node *head=NULL;
struct node *tail=NULL;
struct node *temp=NULL;
int main(){
    create();
    display();
    specified();
    begin();
    end();
    delete_b();
    delete_e();
    delete_s();
}
void create(){
    int n;
    printf("enter the total number of nodes :" );
    scanf("%d",&n);
    
    
    
    for(int i=0;i<n;i++){
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        
        new->prev=NULL;
        new->next=NULL;
        if(head==NULL){
                     head=new;
                     tail=new;
                    
    }
        else{
                    tail->next=new;
                    new->prev=tail;
                    tail=new;
                    
    }
    }
}
void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;

    }
}
void specified(){
    int p=0;
    printf("enter position to add node");
    scanf("%d",&p);
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter element");
    scanf("%d",&new->data);
    temp=head;
    for(int i=0;i<p-2;i++){
                      temp=temp->next;  
    }  
    new->next=temp->next;
    temp->next->prev=new;
    temp->next=new;
    new->prev=temp;
    display();
}
void begin(){
    temp=head;
    new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    new->prev=NULL;
    new->next=temp;
    temp->prev=new;
    head=new;
    display();
}
void end(){
    new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    tail->next=new;
    new->prev=tail;
    new->next=NULL;
    tail=new;
    display();

}
void delete_b(){
    temp=head;
    head=head->next;
    temp->next=NULL;
    head->prev=NULL;
    printf("node deleted at beginning");
    display();
}
void delete_e(){
    temp=tail;
    tail=tail->prev;
    temp->prev=NULL;
    tail->next=NULL;
    printf("node deleted at end");
    display();
}
void delete_s(){
    int p=0;
    temp=head;
    printf("enter position to delete");
    scanf("%d",&p);
    for(int i=0;i<p-2;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp->next->prev=temp;
    display();

}