%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int t,rc=0,l=0,in=1,sf,s,v;
char fname[10];
struct node
{	int val;
	char op;
	char name[10];
	int flag;
	int type; //0 int 1 bool 2 void
	struct node * left,*center,* right;
	struct symtbl *sym;
}*temp;
struct symtbl
{	char name[10];
	int type;
	int *binding;
	int size;
	int index;
	struct symtbl *next;
	struct argstruct *arglist;
}*gbegin=NULL,*gend=NULL,*gtmp,*lbegin=NULL,*lend=NULL,*ltmp;
struct argstruct
{	char name[10];
	int type;
	struct node *arg;
	struct argstruct *next,*prev;
}*abegin,*aend,*atmp;
struct symtbl* insertgsymtbl(char *name,int type,int s);
struct symtbl*  gsymtbllookup(char *name);
void  traversegsymtbl();
struct symtbl* insertlsymtbl(char *name,int type,int s);
struct symtbl*  lsymtbllookup(char *name);
void  traverselsymtbl();
struct argstruct * insertargstruct(char *name,int type);
struct argstruct * argstructlookup(char *name);
struct node* createnodeid(char *name,struct node *n1,struct node *n2);
struct node* createnodenum(int val,struct node *n1,struct node *n2);	
struct node* createnodebool(int val,struct node *n1,struct node *n2);
struct node* createnodevoid(struct node* n1,struct node* n2);
struct node* createnodeop(char op,struct node *n1,struct node *n2);
struct node* createnodearrid(char *name,struct node *n1,struct node *n2,struct node *n3);
struct node* createnodecond(char op,struct node *n1,struct node *n2,struct node *n3);
struct node* createnodefunc(char *name,struct node *n1,struct node *n2);
void inorder(struct node *n);
void icg(struct node *n);
FILE *fp;
%}

%union	{ 	int num; 
		char ch[10];
		struct node *ptr;
	}
%left '>' '<' EQ LE GE NE 
%left '+' '-'
%left '*' '/'
%token NUM DECL ENDDECL BEGN END ID INTEGER BOOLEAN READ WRITE TRUE FALSE AND NOT OR IF THEN ELSE ENDIF WHILE ENDWHILE LE EQ NE GE MAIN RETN
%type <ptr>expr IDS stmt slist body fcall
%type <ch> ID
%% 
pgm: DECL gdlist ENDDECL {traversegsymtbl();} flist {traverselsymtbl();}
	| DECL ENDDECL {traversegsymtbl();} flist 
gdlist:gdlist gdecl
	|gdecl 
gdecl: type gIDlist ';'
	| type {if(t=0) v=0; else v=1; } ID '(' { abegin=NULL; aend=NULL; sf=0; } pdlist ')' ';' { gtmp=insertgsymtbl($3,v,1);
					gtmp->arglist=abegin; gtmp->size=sf;
				} 
	| type ID '(' { abegin=NULL; aend=NULL; }  ')' ';' { gtmp=insertgsymtbl($3,v,1);
					gtmp->arglist=NULL; gtmp->size=0;
				} 
type:INTEGER{t=0;}
	|BOOLEAN{t=1;}
gIDlist: ID { insertgsymtbl(yylval.ch,t,1); 
				}
		|gIDlist ',' ID { insertgsymtbl(yylval.ch,t,1); 
			
				}
		|ID '[' NUM ']' {insertgsymtbl($1,t,yylval.num); 
				}
		|gIDlist ',' ID '[' NUM ']' { insertgsymtbl($3,t,yylval.num); 
				
				}

pdlist:type ID { insertargstruct(yylval.ch,t); 		
				sf++;}
		|pdlist ','type ID { 	
					insertargstruct(yylval.ch,t); sf++;
				}
		
flist: flist func
	|func 
func:type ID '(' {	strcpy(fname,$2);
			abegin=aend=NULL; 
			lbegin=lend=NULL; 	rc=0;	
		} pdlist {gtmp=gsymtbllookup($2);
			if(gtmp==NULL)
			{printf("Error:Function %s not declared",$2);
			exit(0);
			}
			if(gtmp->type!=t)
			{printf("Error:Return type don't match",$2);
			exit(0);
			}
			atmp=gtmp->arglist;
			struct argstruct *t;
			t=abegin;
			int index=-1;
 			while(atmp!=NULL)
			{if(t!=NULL)
			{	if(t->type==atmp->type&&!strcmp(atmp->name,t->name))
				{	atmp=atmp->next;
					insertlsymtbl(t->name,t->type,index);
					index--;
					t=t->next;						
				}
				else
				{	printf("Error:Function paramters don't match"); 
					exit(0);
				}
			}
			else
			{	printf("Number of parameters don't match"); exit(0);}
			}
			if(t!=NULL)
			{printf("\nNumber of parameters don't match"); exit(0);}
			
			} 
		')' '{' body '}'{ 
					fprintf(fp,"%s:\n",$2);
					
					icg($9);
					fprintf(fp,"MOV R%d,BP\n",0);
					fprintf(fp,"MOV SP,R%d\n",0);
					fprintf(fp,"RET\n",0);
					}
	|type ID '(' {abegin=aend=NULL; lbegin=lend=NULL; gtmp=gsymtbllookup($2);
					if(gtmp==NULL)
					{printf("Error:Function %s not declared",$2);
					exit(0);
					}
					if(gtmp->type!=t)
					{printf("Error:Return type don't match",$2);
					exit(0);
					}
					atmp=gtmp->arglist;
 					if(atmp!=NULL)
					{ printf("Parameters donot match"); exit(0);
					}} ')' '{' body '}'{ 
					fprintf(fp,"%s:\n",gtmp->name);
					icg($7);
					fprintf(fp,"MOV R%d,BP\n",0);
					fprintf(fp,"MOV SP,R%d\n",0);
					fprintf(fp,"RET\n",0);
					}
	|INTEGER MAIN '(' ')' '{' {lbegin=lend=NULL;} body '}'{fprintf(fp,"START\n"); fprintf(fp,"MOV SP,%d\n",in); fprintf(fp,"MOV BP,%d\n",in); icg($7); fprintf(fp,"HALT\n");}
body: DECL dlist ENDDECL BEGN slist END{inorder($5);  $$=$5;} 
	| DECL ENDDECL BEGN slist END{inorder($4);  $$=$4;}
dlist: dlist decl
	|decl 
decl: type IDlist ';' 
IDlist: ID { s=1; insertlsymtbl(yylval.ch,t,s); s++;
		}
		|IDlist ',' ID { insertlsymtbl(yylval.ch,t,s); 
				s++;
				}

slist: slist stmt {$$=createnodevoid($1,$2);}
	|stmt{$$=$1;}
stmt: READ '(' IDS ')' ';'{$$=createnodeop('r',NULL,$3); $$->type=$3->type;}
	|WRITE '(' expr ')' ';'{if($3->type!=0)
				{printf("Error:Write does not support boolean operators\n"); exit(0);}
				$$=createnodeop('w',NULL,$3); $$->type=$3->type;}
	|IDS '=' expr ';' { if($1->type!=$3->type) 
					{	printf("Type Error");
						exit(0);
					}
					$$=createnodeop('=',$1,$3); 
					$$->type=$1->type;
					}
	|IDS '=' fcall { if($1->type!=$3->type) 
				{	printf("Type Error");
					exit(0);
				}
				$$=createnodeop('=',$1,$3); 
				$$->type=$1->type;
			}
	|IF '(' expr ')' THEN slist ENDIF{$$=createnodeop('c',$3,$6);}
	|IF '(' expr ')' THEN slist ELSE slist ENDIF {$$=createnodecond('d',$3,$6,$8);}
	|WHILE '(' expr ')' slist ENDWHILE {$$=createnodeop('i',$3,$5);}
	|fcall{$$=$1;}
	|RETN expr ';' {temp=createnodefunc(fname,NULL,NULL); $$=createnodeop('v',temp,$2); }
fcall:ID '(' { gtmp=gsymtbllookup($1); if(gtmp==NULL){printf("\nFunction does not exist"); exit(0);}atmp=gtmp->arglist;}arglist ')' ';' {	$$=createnodefunc($1,NULL,NULL);}
arglist:arg
	| {if(atmp!=NULL)
		{	printf("Function call expects parameters"); 
			exit(0);
		} };
arg:ID { 	if(atmp==NULL)
		{	printf("Too many parameters in function call"); 
			exit(0);
		} 
		ltmp=lsymtbllookup($1);
		if(ltmp==NULL)
		ltmp=gsymtbllookup($1);
		if(ltmp==NULL)
		{	printf("Variable used without declaration\n"); 
			exit(0);
		}
		if(ltmp->type!=atmp->type)
		{	printf("Function paramter list type mismatch\n"); 
			exit(0);
		}
		atmp->arg=createnodeid($1,NULL,NULL);
		atmp=atmp->next;			
	    }
	|arglist ',' ID { 	if(atmp==NULL)
				{	printf("Too many parameters in function call"); 
					exit(0);
				} 
				ltmp=lsymtbllookup($3);
				if(ltmp==NULL)
				ltmp=gsymtbllookup($3);
				if(ltmp==NULL)
				{	printf("Variable used without declaration\n"); 
					exit(0);
				}
				if(ltmp->type!=atmp->type)
				{	printf("Function paramter list type mismatch\n"); 
					exit(0);
				}
				atmp->arg=createnodeid($3,NULL,NULL);
				atmp=atmp->next;	        
				}
	|ID '[' NUM ']' { 	if(atmp==NULL)
		{	printf("Too many parameters in function call"); 
			exit(0);
		} 
		ltmp=lsymtbllookup($1);
		if(ltmp==NULL)
		ltmp=gsymtbllookup($1);
		if(ltmp==NULL)
		{	printf("Variable used without declaration\n"); 
			exit(0);
		}
		if(ltmp->type!=atmp->type)
		{	printf("Function paramter list type mismatch\n"); 
			exit(0);
		}
		temp=createnodenum(yylval.num,NULL,NULL);
		atmp->arg=createnodearrid($1,NULL,NULL,temp);
		atmp=atmp->next;			
	    }
	|arglist ',' ID '[' NUM ']' { 	if(atmp==NULL)
				{	printf("Too many parameters in function call"); 
					exit(0);
				} 
				ltmp=lsymtbllookup($3);
				if(ltmp==NULL)
				ltmp=gsymtbllookup($3);
				if(ltmp==NULL)
				{	printf("Variable used without declaration\n"); 
					exit(0);
				}
				if(ltmp->type!=atmp->type)
				{	printf("Function paramter list type mismatch\n"); 
					exit(0);
				}
				temp=createnodenum(yylval.num,NULL,NULL);
				atmp->arg=createnodearrid($3,NULL,NULL,temp);
				atmp=atmp->next;	        
				}
	|ID '[' ID ']' { 	if(atmp==NULL)
		{	printf("Too many parameters in function call"); 
			exit(0);
		} 
		ltmp=lsymtbllookup($1);
		if(ltmp==NULL)
		ltmp=gsymtbllookup($1);
		if(ltmp==NULL)
		{	printf("Variable used without declaration\n"); 
			exit(0);
		}
		if(ltmp->type!=atmp->type)
		{	printf("Function paramter list type mismatch\n"); 
			exit(0);
		}
		temp=createnodeid($3,NULL,NULL);
		atmp->arg=createnodearrid($1,NULL,NULL,temp);
		atmp=atmp->next;			
	    }
	|arglist ',' ID '[' ID ']' { 	if(atmp==NULL)
				{	printf("Too many parameters in function call"); 
					exit(0);
				} 
				ltmp=lsymtbllookup($3);
				if(ltmp==NULL)
				ltmp=gsymtbllookup($3);
				if(ltmp==NULL)
				{	printf("Variable used without declaration\n"); 
					exit(0);
				}
				if(ltmp->type!=atmp->type)
				{	printf("Function paramter list type mismatch\n"); 
					exit(0);
				}
				temp=createnodeid($5,NULL,NULL);
				atmp->arg=createnodearrid($3,NULL,NULL,temp);
				atmp=atmp->next;	        
				}
	|NUM { 	if(atmp==NULL)
		{	printf("Too many parameters in function call"); 
			exit(0);
		}
		atmp->arg=createnodenum(yylval.num,NULL,NULL); 
		atmp=atmp->next;
		}
	|arglist ',' NUM  { 	if(atmp==NULL)
				{	printf("Too many parameters in function call"); 
					exit(0);
				}
				atmp->arg=createnodenum(yylval.num,NULL,NULL); 
				atmp=atmp->next;
			}							

expr: expr '+' expr {
				if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('+',$1,$3); 
						$$->type=$1->type;}
      |expr '-' expr {	if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('-',$1,$3); 
						$$->type=$1->type;
					}
	|expr '*' expr {		if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('*',$1,$3); 
						$$->type=$1->type;
				}
	| expr '/' expr {	if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('/',$1,$3); 
						$$->type=$1->type;
			}
	| '(' expr ')' {	$$=$2 ;		}
	| expr '>' expr { if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('>',$1,$3); 
						$$->type=1;
						}
	| expr '<' expr { if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('<',$1,$3); 
						$$->type=1;
						}
	| expr EQ expr { if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('e',$1,$3); 
						$$->type=1;
						}	
	| expr LE expr { if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('l',$1,$3); 
						$$->type=1;
						}		
	| expr GE expr { if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('g',$1,$3); 
						$$->type=1;
						}
	| expr NE expr { if($1->type!=0 && $3->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						$$=createnodeop('f',$1,$3); 
						$$->type=1;
						}
	
	|TRUE{	$$=createnodebool(1,NULL,NULL);	}
	|FALSE{	$$=createnodebool(0,NULL,NULL);	}
	|NUM {	$$=createnodenum(yylval.num,NULL,NULL);		}
	|'-' NUM{ int a; 
		a=yylval.num-2*yylval.num;
		$$=createnodenum(a,NULL,NULL);
		}
	|IDS 
	
IDS:ID{	$$=createnodeid($1,NULL,NULL); } 
	|ID '[' NUM ']' {	temp=createnodenum(yylval.num,NULL,NULL);
				$$=createnodearrid($1,NULL,NULL,temp);
					}
	|ID '[' ID ']' {	temp=createnodeid($3,NULL,NULL);
				$$=createnodearrid($1,NULL,NULL,temp);
					}	
%%
int main()
{extern FILE* yyin;
fp=fopen("output.sim","w+"); 
yyin=fopen("input.txt","r+");
yyparse();
}
yyerror(char *s)
{	 printf("%s",s);
}



void icg(struct node *n)
{		int l1,l2; 
	if(n==NULL)
	return ;
	if(n->flag==0)
	{ 	fprintf(fp,"MOV R%d,%d\n",rc,n->val);
		rc++;
		return ;
	}
	if(n->flag==2)
	{	gtmp=gsymtbllookup(n->name);
		if(gtmp==NULL) 	
		{	fprintf(fp,"MOV R%d,%d\n",rc,n->sym->index);
			fprintf(fp,"MOV R%d,BP\n",rc+1);
			fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
			fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
			rc++;
		}
		else	
		{fprintf(fp,"MOV R%d,[%d]\n",rc,n->sym->index);
		rc++;
		}
		return;	
	}
	if(n->flag==3)
	{
	icg(n->left);
	icg(n->right);
	return ;
	}
	if(n->flag==5)
	{	//INITIALIZE SP
		fprintf(fp,"MOV R%d,SP\n",rc);
		fprintf(fp,"MOV R%d,%d\n",rc+1,s-1);
		fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
		fprintf(fp,"MOV SP,R%d\n",rc);
		int i;
		for(i=0;i<rc;i++)
		{	fprintf(fp,"PUSH R%d\n",i);
		}
		atmp=n->sym->arglist;
		fprintf(fp,"MOV R%d,BP\n",rc);
		fprintf(fp,"PUSH R%d\n",rc);
		if(atmp!=NULL)
		while(atmp->next!=NULL)
		{	atmp=atmp->next;
		}
		while(atmp!=NULL)
		{	if(atmp->arg->flag==2)		
			{	gtmp=gsymtbllookup(atmp->arg->name);
				if(gtmp!=NULL)
				 {	fprintf(fp,"MOV R%d,[%d]\n",rc,atmp->arg->sym->index);
				}
				else
				{	fprintf(fp,"MOV R%d,%d\n",rc,atmp->arg->sym->index);
					fprintf(fp,"MOV R%d,BP\n",rc+1);
					fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
					fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
				}
			}
			if(atmp->arg->flag==4)
			{	if(atmp->arg->center->flag==0) 
				{
					fprintf(fp,"MOV R%d,[%d]\n",rc,atmp->arg->sym->index+atmp->arg->center->val);
					
				}
				else
				{	gtmp=gsymtbllookup(atmp->arg->center->name);
					if(gtmp!=NULL)
					{	fprintf(fp,"MOV R%d,[%d]\n",rc,atmp->arg->center->sym->index);
				
						fprintf(fp,"MOV R%d,%d\n",rc+1,atmp->arg->sym->index);
				
  						fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
				
						fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
					}
					else
					{	fprintf(fp,"MOV R%d,%d\n",rc,atmp->arg->center->sym->index);
						fprintf(fp,"MOV R%d,BP\n",rc+1);
						fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
						fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
						fprintf(fp,"MOV R%d,%d\n",rc+1,atmp->arg->sym->index);
				
  						fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
				
						fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
					}
				}
			}
		
			if(atmp->arg->flag==0)
			fprintf(fp,"MOV R%d,%d\n",rc,atmp->arg->val);
			fprintf(fp,"PUSH R%d\n",rc);
			atmp=atmp->prev;
		}
		
		fprintf(fp,"MOV R%d,SP\n",rc);
		fprintf(fp,"MOV R%d,1\n",rc+1);
		fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
		fprintf(fp,"MOV BP,R%d\n",rc);		  
		fprintf(fp,"CALL %s\n",n->sym->name);
		fprintf(fp,"POP R%d\n",rc);
		fprintf(fp,"MOV R%d,SP\n",rc);
		fprintf(fp,"MOV R%d,%d\n",rc+1,n->sym->size);
		fprintf(fp,"SUB R%d,R%d\n",rc,rc+1);	
		fprintf(fp,"MOV R%d,SP\n",rc);
		fprintf(fp,"MOV BP,[R%d]\n",rc);
		fprintf(fp,"POP R%d\n",rc);
		for(i=rc-1;i>=0;i--)
		fprintf(fp,"POP R%d\n",i);
	}
	if(n->flag==4)
	{	if(n->center->flag==0) 
		{
		fprintf(fp,"MOV R%d,[%d]\n",rc,n->sym->index+n->center->val);
		rc++;
		}
		else
		{	gtmp=gsymtbllookup(n->center->name);
			if(gtmp!=NULL)
			{	fprintf(fp,"MOV R%d,[%d]\n",rc,n->center->sym->index);
				rc++;
				fprintf(fp,"MOV R%d,%d\n",rc,n->sym->index);
				rc++;
  				fprintf(fp,"ADD R%d,R%d\n",rc-2,rc-1);
				rc--;
				fprintf(fp,"MOV R%d,[R%d]\n",rc-1,rc-1);
			}
			else
			{	fprintf(fp,"MOV R%d,%d\n",rc,n->center->sym->index);
				fprintf(fp,"MOV R%d,BP\n",rc+1);
				fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
				fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
				fprintf(fp,"MOV R%d,%d\n",rc+1,n->sym->index);
				
  				fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
				
				fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
				rc++;
			}
		}
	}
	if(n->flag==1)
	{ 	switch(n->op)
		{	case '+': 	icg(n->left);
						icg(n->right);
						fprintf(fp,"ADD R%d,R%d\n",rc-2,rc-1);
						rc--;
						break ;
			case '-': 	icg(n->left);
						icg(n->right);
						fprintf(fp,"SUB R%d,R%d\n",rc-2,rc-1);
						rc--;
						break ;
			case '*': 	icg(n->left);
						icg(n->right);
						fprintf(fp,"MUL R%d,R%d\n",rc-2,rc-1);
						rc--;
						break ;
			case '/': 	icg(n->left);
						icg(n->right);
						fprintf(fp,"DIV R%d,R%d\n",rc-2,rc-1);
						rc--;
						break ;
			case '=': 		
					icg(n->right);	
						gtmp=gsymtbllookup(n->left->name);
						if(gtmp==NULL)
						{		fprintf(fp,"MOV R%d,%d\n",rc,n->left->sym->index);
								fprintf(fp,"MOV R%d,BP\n",rc+1);
								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
								if(n->right->flag==5)
								{gtmp=gsymtbllookup(n->right->name);
								fprintf(fp,"MOV [R%d],[%d]\n",rc,gtmp->index);
								}
								else
								{fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1); rc--;}
						}			
						else
						{		
								if(n->right->flag==5)
								{gtmp=gsymtbllookup(n->right->name);
								fprintf(fp,"MOV [%d],[%d]\n",n->left->sym->index,gtmp->index);
								}
								else if(n->left->flag==4)
								{	if(n->left->center->flag==0) 
									{
								fprintf(fp,"MOV [%d],R%d\n",n->left->sym->index+n->left->center->val,rc-1);
								
									rc--;
									}
									else
									{	gtmp=gsymtbllookup(n->left->center->name);
										if(gtmp!=NULL)
										{fprintf(fp,"MOV R%d,[%d]\n",rc,n->left->center->sym->index);
							
										fprintf(fp,"MOV R%d,%d\n",rc+1,n->left->sym->index);
							
  										fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
								
										fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
								
										rc--;
										}
										else
										{	fprintf(fp,"MOV R%d,%d\n",rc,n->left->center->sym->index);
											fprintf(fp,"MOV R%d,BP\n",rc+1);
											fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
											fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
											fprintf(fp,"MOV R%d,%d\n",rc+1,n->left->sym->index);
							
  											fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
							
											fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
											rc--;
										}
							
									}
								}
								else
								{fprintf(fp,"MOV [%d],R%d\n",n->left->sym->index,rc-1); rc--;}

						}
						
						break;
			case 'r': 	
						fprintf(fp,"IN R%d\n",rc);
						rc++;
						if(n->right->flag==2)
						{	gtmp=gsymtbllookup(n->name);
							if(gtmp==NULL)
							{	fprintf(fp,"MOV R%d,%d\n",rc,n->right->sym->index);
								fprintf(fp,"MOV R%d,BP\n",rc+1);
								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
								fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
								rc--;
							}
							else
							{fprintf(fp,"MOV [%d],R%d\n",n->right->sym->index,rc-1);
							rc-=1;}
						}	
						if(n->right->flag==4)
						{	if(n->right->center->flag==0) 
							{
								fprintf(fp,"MOV [%d],R%d\n",n->right->sym->index+n->right->center->val,rc-1);
								rc--;
							}
							else
							{	gtmp=gsymtbllookup(n->right->center->name);
								if(gtmp!=NULL)
								{fprintf(fp,"MOV R%d,[%d]\n",rc,n->right->center->sym->index);
							
								fprintf(fp,"MOV R%d,%d\n",rc+1,n->right->sym->index);
							
  								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
							
								fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
								rc--;
								}
								else
								{fprintf(fp,"MOV R%d,%d\n",rc,n->right->center->sym->index);
								fprintf(fp,"MOV R%d,BP\n",rc+1);
								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
								fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
								fprintf(fp,"MOV R%d,%d\n",rc+1,n->right->sym->index);
							
  								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
							
								fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
								rc--;
								}
							}
						}
											
						break;
			case 'w': 		icg(n->right);
						fprintf(fp,"OUT R%d\n",rc-1);
						rc--;
						break;

			case 'e': 		icg(n->left); icg(n->right);
						fprintf(fp,"EQ R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case 'l':		icg(n->left); icg(n->right);
						fprintf(fp,"LE R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case 'g':		icg(n->left); icg(n->right);
						fprintf(fp,"GE R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case '>':		icg(n->left); icg(n->right);
						fprintf(fp,"GT R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case '<':		icg(n->left); icg(n->right);
						fprintf(fp,"LT R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case 'f':		icg(n->left); icg(n->right);
						fprintf(fp,"NE R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;

			case 'c': 		l1=l; l++;
						icg(n->left);
						fprintf(fp,"JZ R%d,L%d\n",rc-1,l1);
						rc--;						
						icg(n->right);
						fprintf(fp,"L%d:\n",l1);
						break;
			case 'd': 		l1=l; l2=l+1; l+=2;
						icg(n->left);
						fprintf(fp,"JZ R%d,L%d\n",rc-1,l1);
						rc--;
						icg(n->center);
						fprintf(fp,"JMP L%d\n",l2);
						fprintf(fp,"L%d:\n",l1);
						l++;
						icg(n->right);
						fprintf(fp,"L%d:\n",l2);
						l++;
						break;
			case 'i':   	
					
						l1=l;
						l2=l+1;
						l=l+2;
						fprintf(fp,"L%d:\n",l1);
						icg(n->left);
						fprintf(fp,"JZ R%d,L%d\n",rc-1,l2);
						rc--;
						icg(n->right);
						fprintf(fp,"JMP L%d\n",l1);
						fprintf(fp,"L%d:\n",l2);
						l++;
						break;
			case 'v': 		icg(n->right);				
						gtmp=gsymtbllookup(n->left->name);
						fprintf(fp,"MOV [%d],R%d\n",gtmp->index,rc-1);
						fprintf(fp,"MOV R%d,BP\n",rc);
						fprintf(fp,"MOV SP,R%d\n",rc);
						fprintf(fp,"RET\n");
						rc--;
						break;
		}
	}
}


struct node* createnodeid(char *name,struct node *n1,struct node *n2)
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

struct node* createnodefunc(char *name,struct node *n1,struct node *n2)
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

struct symtbl * insertgsymtbl(char *name,int type,int s)
{ 	gtmp=gsymtbllookup(name);
	if(gtmp!=NULL)
	{printf("ERROR:MULTIPLE DECLARATION");
	exit(0);
	}
	gtmp=(struct symtbl*)malloc(sizeof(struct symtbl));
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
	{gend->next=gtmp;
	gend=gtmp;
	}
	return gtmp;
}

struct symtbl *  gsymtbllookup(char *name)
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
		gtmp=gtmp->next;		
	}
	
}
struct symtbl * insertlsymtbl(char *name,int type,int index)
{ 	ltmp=lsymtbllookup(name);
	if(ltmp!=NULL)
	{printf("ERROR:MULTIPLE DECLARATION");
	exit(0);
	}
	ltmp=(struct symtbl*)malloc(sizeof(struct symtbl));
	strcpy(ltmp->name,name);
	ltmp->type=type;
	ltmp->next=NULL;
	ltmp->size=1;
	ltmp->index=index;
	if(lbegin==NULL)
	{lbegin=lend=ltmp;
	}
	else
	{lend->next=ltmp;
	lend=ltmp;
	}
	return ltmp;
}

struct symtbl *  lsymtbllookup(char *name)
{	ltmp=lbegin;
	while(ltmp!=NULL)
	{	if(!strcmp(ltmp->name,name))
		return ltmp;
		ltmp=ltmp->next;		
	}
	return NULL;
}
void traverselsymtbl()
{	
	ltmp=lbegin;
	while(ltmp!=NULL)
	{	printf("%s\t",ltmp->name);
		printf("%d\n",ltmp->type);
		ltmp=ltmp->next;		
	}
	
}
struct argstruct * insertargstruct(char *name,int type)
{ 	atmp=argstructlookup(name);
	if(atmp!=NULL)
	{printf("ERROR:MULTIPLE ARGUMENT DECLARATION");
	exit(0);
	}
	atmp=(struct argstruct*)malloc(sizeof(struct argstruct));
	strcpy(atmp->name,name);
	atmp->type=type;
	atmp->next=NULL;
	atmp->prev=NULL;
	if(abegin==NULL)
	{abegin=aend=atmp; 
	}
	else
	{aend->next=atmp;
	atmp->prev=aend;
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
