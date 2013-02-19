struct node
{	int val;
	char op;
	char name[10];
	int flag;
	int type; //0 int 1 bool 2 void
	struct node * left,*center,* right;
	struct symtbl *sym;
}*temp;
struct node* createnodeid(char *name,struct node *n1,struct node *n2);
struct node* createnodenum(int val,struct node *n1,struct node *n2);	
struct node* createnodebool(int val,struct node *n1,struct node *n2);
struct node* createnodevoid(struct node* n1,struct node* n2);
struct node* createnodeop(char op,struct node *n1,struct node *n2);
struct node* createnodearrid(char *name,struct node *n1,struct node *n2,struct node *n3);
struct node* createnodecond(char op,struct node *n1,struct node *n2,struct node *n3);
struct node* createnodefunc(char *name,struct node *n1,struct node *n2)


struct node* createnodeid(char *name,struct node *n1,struct node *n2);
{	
	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->name,name);
	struct symtbl *t;
	t=lsymtbllookup(name);
	if(t==NULL)
	t=gsymtbllookup(name);
	if(t==NULL)
	{	printf("Variable %s used without declaration",name);
		exit(0);
	}
	if(t->size!=1)
	{ printf("Error:Variable %s is an array",name);
	exit(0);
	}
	printf("Matched entry %s",t->name);
	temp->sym=t;
	temp->type=t->type;
	temp->flag=2;
	temp->left=n1;
	temp->right=n2;
	return temp;
}

void createnodefunc(char *name,struct node *n1,struct node *n2);
{	
	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->name,name);
	struct symtbl *t;
	t=gsymtbllookup(name);
	if(t==NULL)
	{	printf("Function %s used without declaration",name);
		exit(0);
	}
	printf("Matched entry %s",t->name);
	temp->sym=t;
	temp->type=t->type;
	temp->flag=5;
	temp->left=n1;
	temp->right=n2;
	return temp;
}
struct node* createnodenum(int val,struct node *n1,struct node *n2)	
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->op='\0';
	temp->type=0;
	temp->flag=0;
	temp->left=n1;
	temp->right=n2;
	return temp;
}
struct node* createnodeop(char op,struct node *n1,struct node *n2)	
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->op=op;
	temp->type=2;
	temp->flag=1;
	temp->left=n1;
	temp->right=n2;
}
struct node* createnodecond(char op,struct node *n1,struct node *n2,struct node *n3)	
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->op=op;
	temp->type=2;
	temp->flag=1;
	temp->left=n1;
	temp->center=n2;
	temp->right=n3;
}
struct node* createnodebool(int val,struct node *n1,struct node *n2)	
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->op='\0';
	temp->type=1;
	temp->flag=0;
	temp->left=n1;
	temp->right=n2;
	return temp;
}
struct node* createnodevoid(struct node* n1,struct node* n2)
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->type=2;
	temp->flag=3;
	temp->left=n1;
	temp->right=n2;
	return temp;
}

struct node* createnodearrid(char *name,struct node *n1,struct node *n2,struct node*n3)
{	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->name,name);
	struct symtbl *t;
	t=gsymtbllookup(name);
	if(t==NULL)
	{	printf("Variable %s used without declaration",name);
		exit(0);
	}
	printf("Matched entry %s",t->name);
	temp->sym=t;
	temp->type=t->type;
	temp->flag=4;
	temp->left=n1;
	temp->right=n2;
	temp->center=n3;
	return temp;
}
void inorder(struct node *n)
{ if(n==NULL)
	return ;
 inorder(n->left);
 printf("node: %d\n%c\n%d\n",n->val,n->op,n->flag);
 inorder(n->right);
}

