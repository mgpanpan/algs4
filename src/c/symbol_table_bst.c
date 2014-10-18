#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    char* value;
    struct node *left;
    struct node *right;
};

typedef struct node node;

static node* root = NULL;

void put(int key, char* value);
char* get(int key);
int contains(int key);
int is_empty();
int size();

node* create_node(int key, char* value);
node* put_node(node* n, int key, char* value);
char* get_node(node* n, int key);
void print();
void print_node(node* n);
int contains_node(node* n, int key);
int size_node(node* n);

int main()
{
    put(1, "aaa");
    put(3, "bbb");
    put(2, "ccc");
    put(2, "222");
    put(4, "mmm");

    printf("%s\n", get(2));
    printf("%d\n", contains(1));
    printf("%d\n", contains(5));

    printf("%d\n", is_empty());
    printf("%d\n", size()); 

    print();
    return 0;
}

int size()
{
    return size_node(root);
}

int size_node(node* n)
{ 
    if(n == NULL) return 0;
    else return 1 + size_node(n->left) + size_node(n->right);
}

int is_empty()
{
    return root == NULL;
}

int contains(int key)
{
    contains_node(root, key);
}

int contains_node(node* n, int key)
{
    if(!n) return 0;
    if(key > n->key) return contains_node(n->right, key);
    else if(key < n->key) return contains_node(n->left, key);
    else return 1; 
}

void print()
{ 
    print_node(root);
}

void print_node(node* n)
{
    if(!n) return;
    else
    {
        printf("key: %d, value: %s\n", n->key, n->value);
        print_node(n->left);
        print_node(n->right);
    }
}

char* get(int key)
{ 
    return get_node(root, key);
}

char* get_node(node* n, int key)
{
    if(!n) return NULL;

    if(key == n->key) return n->value;
    else if(key > n->key) return get_node(n->right, key);
    else return get_node(n->left, key); 
}

void put(int key, char* value)
{
    root = put_node(root, key, value);
}

node* put_node(node* n, int key, char* value)
{
    if(!n)  
        return create_node(key, value);
    else if(key > n->key) n->right = put_node(n->right, key, value);
    else if(key < n->key) n->left = put_node(n->left, key, value);
    else n->value = value;

    return n;
}

node* create_node(int key, char* value)
{
    node* n = malloc(sizeof(node));
    n->key = key;
    n->value = value;

    return n;
}