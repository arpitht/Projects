int in=1;
struct gsymtbl
{	char name[10];
	int type;
	int *binding;
	int size;
	int index;
	struct symtbl *next;
}*gbegin=NULL,*gend=NULL,*gtmp;
struct lsymtbl
{	char name[10];
	int type;
	int *binding;
	int index;
	struct symtbl *next;
}*lbegin=NULL,*lend=NULL,*ltmp;
struct argstruct
{	char name[10];
	int type;
	int size;
	int value;
	struct argstruct *next;
}*abegin,*aend,*atmp;
struct gsymtbl* insertgsymtbl(char *name,int type,int s);
struct gsymtbl*  gsymtbllookup(char *name);
void  traversegsymtbl();
struct lsymtbl* insertlsymtbl(char *name,int type,int s);
struct lsymtbl*  lsymtbllookup(char *name);
void  traverselsymtbl();
struct argstruct * insertargstruct(char *name,int type,int s);
struct argstruct * argstructlookup(char *name);
struct gsymtbl * insertgsymtbl(char *name,int type,int s)
{ 	gtmp=gsymtbllookup(name);
	if(gtmp!=NULL)
	{printf("ERROR:MULTIPLE DECLARATION");
	exit(0);
	}
	gtmp=(struct gsymtbl*)malloc(sizeof(struct gsymtbl));
	strcpy(gtmp->name,name);
	gtmp->type=type;
	gtmp->size=s;
	gtmp->next=NULL;
	gtmp->index=in;
	in+=s;
	if(gbegin==NULL)
	{gbegin=gend=gtmp;
	}
	else
	{gend->next=tmp;
	gend=gtmp;
	}
	return gtmp;
}

struct gsymtbl *  gsymtbllookup(char *name)
{	gtmp=gbegin;
	while(gtmp!=NULL)
	{	if(!strcmp(gtmp->name,name))
		return gtmp;
		gtmp=gtmp->next;		
	}
	return NULL;
}
void traversegsymtbl()
{	gtmp=gbegin;
	while(gtmp!=NULL)
	{	printf("%s\t",gtmp->name);
		printf("%d\n",gtmp->type);
		printf("%d",gtmp->size);
		gtmp=tmp->next;		
	}
	
}
struct lsymtbl * insertlsymtbl(char *name,int type,int index)
{ 	ltmp=lsymtbllookup(name);
	if(ltmp!=NULL)
	{printf("ERROR:MULTIPLE DECLARATION");
	exit(0);
	}
	ltmp=(struct lsymtbl*)malloc(sizeof(struct lsymtbl));
	strcpy(ltmp->name,name);
	ltmp->type=type;
	ltmp->next=NULL;
	ltmp->index=index;
	if(lbegin==NULL)
	{lbegin=lend=ltmp;
	}
	else
	{lend->next=tmp;
	lend=ltmp;
	}
	return ltmp;
}

struct lsymtbl *  lsymtbllookup(char *name)
{	ltmp=lbegin;
	while(ltmp!=NULL)
	{	if(!strcmp(ltmp->name,name))
		return ltmp;
		ltmp=ltmp->next;		
	}
	return NULL;
}
void traverselsymtbl()
{	ltmp=lbegin;
	while(ltmp!=NULL)
	{	printf("%s\t",ltmp->name);
		printf("%d\n",ltmp->type);
		ltmp=tmp->next;		
	}
	
}
struct argstruct * insertargstruct(char *name,int type,int s)
{ 	atmp=argstructlookup(name);
	if(atmp!=NULL)
	{printf("ERROR:MULTIPLE ARGUMENT DECLARATION");
	exit(0);
	}
	atmp=(struct argstruct*)malloc(s*sizeof(struct argstruct));
	strcpy(atmp->name,name);
	atmp->type=type;
	atmp->size=s;
	atmp->next=NULL;
	if(abegin==NULL)
	{abegin=aend=atmp;
	}
	else
	{aend->next=atmp;
	aend=atmp;
	}
	return atmp;
}

struct argstruct * argstructlookup(char *name)
{	atmp=abegin;
	while(atmp!=NULL)
	{	if(!strcmp(atmp->name,name))
		return atmp;
		atmp=atmp->next;		
	}
	return NULL;
}
