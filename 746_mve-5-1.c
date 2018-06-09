#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node { 
	int key, val;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

Node* add_node_in_tree(int key, int val, Node *parent) {
	Node* tmp = (Node*) malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->key = key;
	tmp->val = val;
	tmp->parent = parent;
	return tmp;
}
void insert(Node *head, int key, int val) {
	Node *tmp = NULL;
	if (head == NULL) {
		head = add_node_in_tree(key, val, NULL);
		return;
	}
	tmp = head;
	while(tmp) {
		if(val > tmp->val) {
			if(tmp->right) {
				tmp = tmp->right;
				continue;
			} else {
				tmp->right = add_node_in_tree(key, val, tmp);
				return;
			}
		} else if(val < tmp->val) {
			if(tmp->left) {
				tmp = tmp->left;
				continue;
			} else {
				tmp->left = add_node_in_tree(key, val, tmp);
				return;
			}
		} else {
			return;
		}
	}
}

Node* get_node_key(Node *head, int key) {
	 if(head) {
		if(head->right) {
			if(head->key == key) {
				return head;
			} else {
				Node *tmp = get_node_key(head->right, key);
				if(tmp) {
					return tmp;
				}
			}
		}
		if(head->left) {
			if(head->key == key) {
				return head;
			} else {
				Node *tmp = get_node_key(head->left, key);
				if(tmp) {
					return tmp;
				}
			}
		}
	}
	return NULL;
}

int get_node_level_key(Node *head, int key, int level) {
	 if(head) {
		if(head->right) {
			if(head->key == key) {
				return level;
			} else {
				int lvl = get_node_level_key(head->right, key, level + 1);
				if(lvl) {
					return lvl;
				}
			}
		}
		if(head->left) {
			if(head->key == key) {
				return level;
			} else {
				int lvl = get_node_level_key(head->left, key, level + 1);
				if(lvl) {
					return lvl;
				}
			}
		}
	}
	return 0;
}

void print_tree(Node *head, const char *dir, int level) {
	if(head) {
		printf("lvl %d %s\t=\t%d(%d)\n", level, dir, head->key, head->val);
		print_tree(head->left, "left", level+1);
		print_tree(head->right, "right", level+1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int key, val;
	scanf("%d%d", &key, &val);
	Node* head = add_node_in_tree(key, val, NULL);
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &key, &val);
		insert(head, key, val);
	}
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(get_node_key(head, a)) {
		printf("%d %d\n", get_node_level_key(head, a, 0), get_node_key(head, a)->val);
	} else {
		printf("-1\n");
	}
	if(get_node_key(head, b)) {
		printf("%d %d\n", get_node_level_key(head, b, 0), get_node_key(head, b)->val);
	} else {
		printf("-1\n");
	}
	if(get_node_key(head, c)) {
		printf("%d %d\n", get_node_level_key(head, c, 0), get_node_key(head, c)->val);
	} else {
		printf("-1\n");
	}
}
