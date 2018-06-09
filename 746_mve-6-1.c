#include <stdio.h>
#include <stdlib.h>

typedef struct node_tree
{
        int key;
        int value;
        struct node_tree *left;
        struct node_tree *right;
} node_tree;

typedef struct tree
{
        unsigned int tr_size;
        node_tree *root;
} tree;

int init (tree *tr) // инициализация дерева
{
        tr->root = NULL;
        return 1;
}

int isEmpty(tree *tr) // проверка дерева на пустоту
{
        if (tr->root)
                return 0;
        return 1;
}

int insert (tree *tr, int key, int value) //вставка элемента в дерево
{ 
        if (isEmpty(tr))
        {
                node_tree *tmp = malloc (sizeof(node_tree));
                tmp->key = key;
                tmp->value = value;
                tr->root = tmp;
                tmp->left = NULL;
                tmp->right = NULL;
                return 1;
        }
        else
        {
                node_tree *crnt = tr->root;
                node_tree *prev = crnt;
                while (crnt)
                {
                        if (crnt->key == key)
                        {
                                crnt->value = value;
                                return 1;
                        }
                        prev = crnt;
                        if (key < crnt->key)
                                crnt = crnt->left;
                        else
                                crnt = crnt->right;
                }
                node_tree *tmp = malloc (sizeof(node_tree));
                tmp->key = key;
                tmp->value = value;
                tmp->left = NULL;
                tmp->right = NULL;
                if (key < prev->key)
                        prev->left = tmp;
                else
                        prev->right = tmp;
                tr->tr_size++;
                return 1;
        }
        return 0;
}

node_tree *search (tree *tr, int key) // поиск элемента в дереве
{
        node_tree *crnt = tr->root;
        while (crnt)
        {
                if (crnt->key == key)                        
                        return crnt;

                if (key < crnt->key)
                        crnt = crnt->left;
                else
                        crnt = crnt->right;
        }
        return NULL;
}

typedef struct q_node
{
        int value;
        struct q_node *next;
        struct q_node *prev;
} q_node;

typedef struct queue
{
    q_node *head;
    q_node *tail;    
}queue;

int init_q(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

int QisEmpty(queue *q)
{
        if (q->head == NULL && q->tail == NULL)
                return 1;
        return 0;
}

int pop (queue *q)
{
        if (QisEmpty(q))
        {
                return 0;
        }
        q_node *crnt = q->head;
        int value = crnt->value;
        if (crnt == q->tail)
        {
                q->head = NULL;
                q->tail = NULL;
                free(crnt);
                return value;
        }
        crnt->next->prev = NULL;
        q->head = crnt->next;
        free(crnt);
        return value;
}

void push (queue *q, int value)
{
        if (QisEmpty(q))
        {
                q_node *tmp = malloc (sizeof(q_node));
                tmp->value = value;
                q->head = tmp;
                q->tail = tmp;
                tmp->next = NULL;
                tmp->prev = NULL;
        }
        else
        {
                q_node *tmp = malloc (sizeof(q_node));
                tmp->value = value;
                tmp->next = NULL;
                tmp->prev = q->tail;
                q->tail->next = tmp;
                q->tail = tmp;
        }
}

int bfs (tree *tr)
{
    if (isEmpty(tr))
        return 0;

    queue lmnts;        //очередь из элементов
    init_q (&lmnts);
    int key;

    node_tree *crnt = tr->root;
    push(&lmnts, crnt->key);

    while (!QisEmpty(&lmnts))
    {
        key = pop(&lmnts);
        crnt = search(tr, key);
        if (crnt->left)
            push(&lmnts, crnt->left->key);
        if (crnt->right)
            push(&lmnts, crnt->right->key);
        if (!QisEmpty(&lmnts))
            printf ("%d ", crnt->value);
        else
            printf ("%d", crnt->value);        
    }
    printf ("\n");
    return 1;
}

int main ()
{
    tree ourtree;
    init (&ourtree);
    int n, key, value;
        scanf ("%d", &n);
        for (int i=0; i<n; i++)
        {
                scanf("%d", &key);
                scanf("%d", &value);
                insert (&ourtree, key, value);
        }
    bfs (&ourtree);
    return 0;
}
