struct symtbl
{	char name[10];
	int type;
	int *binding;
	int size;
	struct symtbl *next;
}*begin=NULL,*end=NULL,*tmp;
struct symtbl* insertsymtbl(char *name,int type,int size);
struct symtbl*  symtbllookup(char *name);
void  traversesymtbl();
struct symtbl * insertsymtbl(char *name,int type,int size)
{ 	tmp=(struct symtbl*)malloc(sizeof(struct symtbl));
	strcpy(tmp->name,name);
	tmp->type=type;
	tmp->size=size;
	tmp->next=NULL;
	int *a;
	a=(int *)malloc(size*sizeof(int));
	tmp->binding=a;
	if(begin==NULL)
	{begin=end=tmp;
	}
	else
	{end->next=tmp;
	end=tmp;
	}
	return tmp;
}

struct symtbl *  symtbllookup(char *name)
{	tmp=begin;
	while(tmp!=NULL)
	{	if(!strcmp(tmp->name,name))
		return tmp;
		tmp=tmp->next;		
	}
	return NULL;
}
void  traversesymtbl()
{	tmp=begin;
	while(tmp!=NULL)
	{	printf("%s\t",tmp->name);
		printf("%d\n",tmp->type);
		printf("%d",*(tmp->binding));
		tmp=tmp->next;		
	}
	
}

