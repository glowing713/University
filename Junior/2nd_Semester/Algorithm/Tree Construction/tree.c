#include <stdio.h>
#include <stdlib.h>

int rootNumber;

struct _node{
    char RorT;
    int key;
    struct _node * left;
    struct _node * right;
};

struct blank{
    struct _node * addr;
    struct blank* link;
};

void push(struct blank ** head, struct _node * addr)
{
    struct blank* new_element = (struct blank*)malloc(sizeof(struct blank));
    new_element->addr = addr;
    new_element->link = *head;
    *head = new_element;
}

struct _node * pop(struct blank ** head)
{
    struct _node * addr;
    struct blank * temp = *head;
    
    if(*head == NULL) return 0;
    addr = (*head)->addr;
    *head = (*head)->link;
    free(temp);
    return addr;
}

void initStack(struct blank ** head)
{
    *head = NULL;
}

void preord(FILE* out, struct _node * x)
{
    if(x == NULL) return;
    if(x->RorT == 'r') x->key = rootNumber++;
    fprintf(out,"%c%d\n",x->RorT,x->key);
    preord(out,x->left);
    preord(out,x->right);
}

void inord(FILE* out, struct _node * x)
{
    if(x == NULL) return;
    inord(out,x->left);
    fprintf(out,"%c%d\n",x->RorT,x->key);
    inord(out,x->right);
}

int main()
{
    int cycle, num;
    struct _node * x;
    char temp = 0;
    FILE * inp;
    FILE * out;
    struct _node * root = NULL;
    struct blank * head;
    
    
    inp = fopen("tree.inp","rt");
    out = fopen("tree.out","wt");
    
    fscanf(inp,"%d\n",&cycle);
    
    for(int i = 0; i < cycle; i++){
        initStack(&head);
        root=(struct _node *)malloc(sizeof(struct _node));
        root->left = NULL;
        root ->right = NULL;
        push(&head,root);
        rootNumber = 0;
        temp = 0;
        
        
        while(temp != '\n')
        {
            fscanf(inp,"%c",&temp);
            fprintf(out,"%c",temp);
            if(temp == '(')
            {
                x = pop(&head);
                x->right = (struct _node *)malloc(sizeof(struct _node));
                x->left = (struct _node *)malloc(sizeof(struct _node));
                x->right->left = NULL;
                x->right->right = NULL;
                x->left->left = NULL;
                x->left->right = NULL;
                push(&head, x->right);
                push(&head, x->left);
                x->RorT = 'r';
                x->key = 0;
            }
            else if(temp!='\n' && temp!=' ' && temp!=')')
            {
                fscanf(inp,"%d",&num);
                fprintf(out,"%d",num);
                x = pop(&head);
                x->RorT = temp;
                x->key = num;
                x->left = NULL;
                x->right = NULL;
            }
        }
        
        
        
        fprintf(out,"Preorder\n");
        preord(out, root);
        fprintf(out,"Inorder\n");
        inord(out, root);
        
        free(head);
        root = NULL;
    }
    
    
    fclose(inp);
    fclose(out);
    
    return 0;
}
