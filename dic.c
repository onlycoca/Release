#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define Max_Word_Length 20
#define Max_Mean_Length 200

typedef struct {
	char word[Max_Word_Length];
	char mean[Max_Mean_Length];
} element;

typedef struct treenode {
	element key;
	struct treenode *left;
	struct treenode *right;
} treenode;

treenode * insert_key(treenode *p, element key);
void insert(treenode** root, element key);
void show(treenode* root);
void delete(treenode *root, element key);
treenode* search(treenode*root, element key);
void main() {
	char choice;
	element e;
	treenode *root = NULL;
	treenode *temp = NULL;
	printf("\tū���� �������\n");
	printf("\t1 : ���\n");
	printf("\t2 : �Է�\n");
	printf("\t3 : ����\n");
	printf("\t4 : �˻�\n");
	printf("\t5 : ����\n");

	while ((choice- '0') != 5) {
		printf("\t�޴��� �����ϼ��� : ");
		scanf("%c", &choice);
		switch (choice - '0') {
		case 1:
			printf("\t[������� ���]\n");
			show(root); //���
			printf("[������� ��� ����]\n");
			break;
		case 2:
			printf("\t[���� �ܾ� �Է�]");
			gets(e.word);
			getchar();
			printf("\t[�ܾ� �� �Է�]");
			gets(e.mean);
			getchar();
			insert(&root, e); //����
			break;
		case 3:
			printf("\t[�ܾ� ����]\n");
			gets(e.word);
			delete(root, e); // ����
			break;
		case 4:
			printf("\t[�ܾ� �˻�]\n");
			gets(e.word);
			temp = search(root, e);
			if (temp != NULL) {
				printf("\t�ܾ� �� : %s\n", temp->key.mean);
			}
			else printf("\t���� �ܾ��Դϴ�.\n");
			break;
		}
	}

}

treenode * insert_key(treenode *p, element key) {
	treenode *new;
	int compare;
	if (p == NULL) {
		new = (treenode*)malloc(sizeof(treenode));
		new->key = key;
		new->left = NULL;
		new->right = NULL;
		return new;
	}
	else {
		compare = strcmp(key.word, p->key.word);
		if (compare < 0) {
			p->left = insert_key(p->left, key);
		}
		else if (compare > 0) {
			p->right = insert_key(p->right, key);
		}
		else {
			printf("\t�ߺ� �ܾ��Դϴ�.\n");
		}
		return p;
	}
}

void insert(treenode** root, element key) {
	*root = insert_key(*root, key);
}

void delete(treenode *root, element key) {
	treenode *parent, *p, *succ, *succ_parent;
	treenode *child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (strcmp(p->key.word, key.word) != 0)) {
		parent = p;
		if (strcmp(p->key.word, key.word) < 0) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	if (p = NULL) {
		printf("\t�� �ܾ�� ������ �������� �ʽ��ϴ�.\n");
		return;
	}
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) {
				parent -> left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
		else {
			root = NULL;
		}
	}
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) {
			child = p->left;
			}
		else {
			child= p->right;
		}
		if (parent != NULL) {
			if (parent->left == p) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
		else {
			root = child;
		}
	}
	else {
		succ_parent = p;
		succ = p->right;
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}
		if (succ_parent->left == succ) {
			succ_parent->left = succ->right;
		}
		else {
			succ_parent->right = succ->right;
		}
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

treenode* search(treenode*root, element key) {
	treenode* p;
	int compare;
	p = root;
	while (p != NULL) {
		compare = strcmp(key.word, p->key.word);
		if (compare < 0) {
			p = p->left;
		}
		else if (compare > 0) {
			p = p->right;
		}
		else {
			printf("\tã�� �ܾ�\n\t%s", p->key.word);
			return p;
		}
	}
	return p;
}

void show(treenode* root) {
	if (root) {
		show(root->left);
		printf("\t%s : %s\n", root->key.word, root->key.mean);
		show(root->right);
	}
}