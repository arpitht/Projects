#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include <sys/stat.h>
struct node
{
char c;
int valid;
struct node *left;
struct node *right;
}*root,*tmp,*l,*n,*r;
int j=0,nos;
struct fnode
{
char c;
int valid;
};
int top=0;
struct node *stack[1024];
struct node* createnewnode(char c,int i);
void push(struct node *n);
struct node* pop();
void decode(FILE *fp,FILE *out);
void inorder(struct node *a);
int main(int argc,char *argv[])
{	if(argc==3){
	struct stat statbuf;
	lstat(argv[1],&statbuf);
	if(S_ISDIR(statbuf.st_mode))
	{ printf("Argument 1 is not a file");
	exit(0);
	}
	lstat(argv[2],&statbuf);
	if(!S_ISDIR(statbuf.st_mode)) 
	{ printf("Argument 2 is not a directory");
	exit(0);
	}
	FILE *fp;
	struct fnode read;
	fp=fopen(argv[1],"r");
	fscanf(fp,"%d ",&nos);
	//printf("nos = %d\n",nos);
	int i=12;
	do{
		fread(&read,sizeof(struct fnode),1,fp);
		//printf("%c",read.c);
		if(read.c==')' && read.valid==0)		
		{	r=pop();
			n=pop();
			l=pop();
			pop();
			if(l->valid!=0)
			n->left=l;
			if(r->valid!=0)
			n->right=r;
			push(n);	
			
		}
		else
		{	tmp=createnewnode(read.c,read.valid);		
			push(tmp);
		}
		i--;
	}while(top>0 && stack[0]->c=='(');
root=stack[0];
//printf("\n Tree is : \n");
inorder(root);
//printf("\n");
FILE *out;
char ch[100],*f;
strcpy(ch,argv[2]);
strcat(ch,"/");
strcat(ch,argv[1]);
f=strrchr(ch,'.');
*f='\0';
out=fopen(ch,"w");
//printf("\nDecode function outout \n");
decode(fp,out);}
else if(argc==2){ printf(" NO Output Directory is given ");}
	else { printf(" NO File input is given ");}
return 0;

}
void decode(FILE *fp,FILE *out)
{	char c;
	tmp=root;
	int nbits,bit,a;
	while(!feof(fp))
	{	c=getc(fp);
		nbits=8;
		while(nbits>0)
		{	if(nbits==8) 
			a=128;
			bit=((int )c & a) >> (nbits -1) ;
			////printf("%d",bit);
			nbits--;
			a=a/2;
			if(tmp->left==NULL && tmp->right==NULL)
			{	//printf("%c",tmp->c);
				fwrite(&tmp->c,sizeof(char),1,out);
				tmp=root; 
			}
			if(bit==0)
			tmp=tmp->left;
			else
			tmp=tmp->right;
		
			
		
		}
	}
}
void inorder(struct node *a)	
{ if(a!=NULL)
	{ inorder(a->left);
	//printf(" %c, ",a->c);
	inorder(a->right);
	}
}
struct node* createnewnode(char c,int i)
{	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->c=c;
	tmp->valid=i;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;	
}
void push(struct node *n)
{	stack[top]=n;	
	top++;

}
struct node* pop()
{ 
	top--;
	return stack[top];
}
