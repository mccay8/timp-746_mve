#include<stdio.h> 
#include<stdlib.h> 

typedef struct _Node { 
    int value; 
    struct _Node *next; 
    struct _Node *prev; 
} Node; 


typedef struct _List { 
    int size; 
    Node *head; 
    Node *tail; 
} List; 

	void push_front(List *list, int val) { 
		Node *new_node = (Node*) malloc(sizeof(Node)); 
    		if (new_node == NULL) { 
        		return; 
    		} 
    		new_node->value = val; 
    		new_node->next = list->head; 
    		new_node->prev = NULL; 
    		if (list->head) { 
        		list->head->prev = new_node; 
    		} 
    		list->head = new_node; 
    		if (list->tail == NULL) { 
        		list->tail = new_node; 
    		} 
    		list->size++; 
	} 

void push_back(List *list, int val) { 
    	Node *new_node = (Node*) malloc(sizeof(Node)); 
    	if (new_node == NULL) { 
        	return; 
    	} 
    	new_node->value = val; 
    	new_node->next = NULL; 
    	new_node->prev = list->tail; 
    	if (list->tail) { 
        	list->tail->next = new_node; 
    	} 
    	list->tail = new_node; 
    	if (list->head == NULL) { 
        	list->head = new_node; 
    	} 
    	list->size++; 
} 

Node* get_element_index(List *list, int index) {
    	Node *tmp = list->head;
    	int i = 0;
    	while (tmp && i < index) {
        	tmp = tmp->next;
        	i++;
    	}
    	return tmp;
}

Node* get_element_content(List *list, int val) {
    	Node *tmp = list->head;
    	while (tmp && tmp->value != val) {
        	tmp = tmp->next;
    	}
    	return tmp;
}

int delete_element_index(List *list, int index) {
    	Node *elm = NULL;
    	int tmp;
    	elm = get_element_index(list, index);
    	if (elm == NULL) {
        	exit(5);
    	}
    	if (elm->prev) {
        	elm->prev->next = elm->next;
    	}
    	if (elm->next) {
        	elm->next->prev = elm->prev;
    	}
    	tmp = elm->value;
    	if (!elm->prev) {
        	list->head = elm->next;
    	}
    	if (!elm->next) {
        	list->tail = elm->prev;
    	}
    	free(elm);
    	list->size--;
    	return tmp;
}

int delete_element_content(List *list, int val) {
    	Node *elm = NULL;
    	int tmp;
    	elm = get_element_content(list, val);
    	if (elm == NULL) {
        	exit(5);
    	}
    	if (elm->prev) {
        	elm->prev->next = elm->next;
    	}
    	if (elm->next) {
        	elm->next->prev = elm->prev;
    	}
    	tmp = elm->value;
    	if (!elm->prev) {
        	list->head = elm->next;
    	}
    	if (!elm->next) {
        	list->tail = elm->prev;
    	}
    	free(elm);
    	list->size--;
    	return tmp;
}

void insert_after_element(List *list, Node* elm, int val) {
    	if (elm == NULL) {
        	return;
    	}
    	if (!elm->next) {
        	push_back(list, val);
        	return;
    	}
    	Node *ins = NULL;
    	ins = (Node*) malloc(sizeof(Node));
    	ins->value = val;
    	ins->next = elm->next;
    	elm->next->prev = ins;
    	ins->prev = elm;
    	elm->next = ins;
    	list->size++;
}	

void insert_before_element(List *list, Node* elm, int val) {
    	if (elm == NULL) {
        	return;
    	}	
    	if (!elm->prev) {
        	push_front(list, val);
        	return;
    	}
    	Node *ins = NULL;
    	ins = (Node*) malloc(sizeof(Node));
    	ins->value = val;
    	ins->prev = elm->prev;
    	elm->prev->next = ins;
    	ins->next = elm;
    	elm->prev = ins;
    	list->size++;
}	

void print(List *list) { 
    	Node *tmp = list->head; 
    	while (tmp) { 
    		printf("%d ", tmp->value); 
        	tmp = tmp->next; 
    	} 	
    	printf("\n"); 
} 	

int main() {
    	List *list = (List*) malloc(sizeof(List));
    	list->size = 0;
    	list->head = list->tail = NULL;
    	int n;
    	scanf("%d", &n);
    	for(int i = 0; i < n; i++) {
    	    	int val;
    	    	scanf ("%d", &val);
    	    	push_back(list, val);
    	}
    	print(list);
    	int k;
    	scanf("%d", &k);
    	delete_element_index(list, k-1);
    	print(list);
    	int m;
    	scanf("%d", &m);
    	delete_element_content(list, m);
    	print(list);
    	int a, b;
    	scanf("%d%d", &a, &b);
    	insert_after_element(list, get_element_index(list, a-1), b);
    	print(list);
    	int c, d;
    	scanf("%d%d", &c, &d);
    	insert_before_element(list, get_element_index(list, c-1), d);
    	print(list);
}	
