#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FLAG 1
#define LEN 20

int heap_usage = 0;

struct Names
{
	char * first_name;
	char * last_name;
	char * jedi_name;
};
void jediName (struct Names *name_,char buffer[])
{
	 char *sublastName = malloc(strlen(name_->last_name) + 1);
     strcpy(sublastName, name_->last_name);
     sublastName[3]='\0';
     strcat(buffer, sublastName); 
	 free(sublastName);

	 char *subfirstName = malloc(strlen(name_->first_name) + 1);
     strcpy(subfirstName, name_->first_name);
     subfirstName[2]='\0';
	 strcat(buffer, subfirstName);
	 free(subfirstName);
	 printf("jedi:%s\n", buffer);
}

void addName (char name[])
{
	FILE *fp = fopen("4.txt", "a+");
	 if (fp==0)  printf("can't open file\n");
	 fprintf(fp, "%s\n", name);
	 fclose(fp);
}

void part1 ()
{
	 char buffer[LEN];
	 char name0[LEN];
	 int i=0;
	 struct Names * name = malloc(sizeof(struct Names));
	 name->first_name = malloc(LEN);
	 name->last_name = malloc(LEN);
	 if (FLAG)
	 {
	 	printf("in put a name at the end of the file\n");
	 	scanf("%[^\n]",name0);
	 	addName (name0);
	 	printf("in put finished\n");
	 }
	 FILE *fp;
  	 fp = fopen("4.txt","r");
  	 printf("\tjedi names\n=======================\n");
  	 while (fscanf(fp,"%s %s",name->first_name,name->last_name)!= EOF)
  	 {
  	 	strcpy(buffer,"");
  	 	printf("name:%s %s\n",name->first_name,name->last_name);
  	 	jediName(name,buffer);
  	 }
  	 free(name->first_name);
  	 free(name->last_name);
  	 free(name);
  	 fclose(fp); 	 
}
//========================================part2

void * allocate(unsigned int size)
{
	void *p =malloc(size);
	if(p==NULL)
	{
		size = 0;
		heap_usage = heap_usage+0;
		printf("allocated:%d,used:%d\n",size, heap_usage);
		return p;
	}
	else
	{
		heap_usage =heap_usage +size;
		printf("allocated:%d,used:%d\n",size, heap_usage);

	}
	return p;
}

void *deallocate(void *p, int size)
{
	if(p==NULL)
	{
		size=0;
	}
	else
	{
		free(p);
		heap_usage = heap_usage - size;
		if(heap_usage < 0)
		{
			heap_usage =0;
		}

	}	
	printf("freed:%d,used:%d\n",size, heap_usage);
	
	return NULL;
}

void jediName2 (struct Names *name_,char buffer[])
{
	 char *sublastName = allocate(strlen(name_->last_name) + 1);
     strcpy(sublastName, name_->last_name);
     sublastName[3]='\0';
     strcat(buffer, sublastName); 
	 deallocate(sublastName,strlen(name_->last_name) + 1);

	 char *subfirstName = allocate(strlen(name_->first_name) + 1);
     strcpy(subfirstName, name_->first_name);
     subfirstName[2]='\0';
	 strcat(buffer, subfirstName);
	 deallocate(subfirstName,strlen(name_->first_name) + 1);
	 printf("jedi:%s\n", buffer);
}
void part2 ()
{
	 char buffer[LEN];
	 char name0[LEN];
	 int i=0;
	 struct Names * name = allocate(sizeof(struct Names));
	 name->first_name = allocate(LEN);
	 name->last_name = allocate(LEN);
	 if (FLAG)
	 {
	 	printf("in put a name at the end of the file\n");
	 	scanf("%[^\n]",name0);
	 	addName (name0);
	 	printf("in put finished\n");
	 }
	 FILE *fp;
  	 fp = fopen("4.txt","r");
  	 printf("\tjedi names\n=======================\n");
  	 while (fscanf(fp,"%s %s",name->first_name,name->last_name)!= EOF)
  	 {
  	 	strcpy(buffer,"");
  	 	printf("name:%s %s\n",name->first_name,name->last_name);
  	 	jediName2(name,buffer);
  	 	printf("=================\n" );
  	 }
  	 deallocate(name->first_name,LEN);
  	 deallocate(name->last_name,LEN);
  	 deallocate(name,sizeof(struct Names));
  	 fclose(fp); 	 
}

int main(int argc, char const *argv[])
{
	//part1();
	printf("========Fang Li==========\n");
	part2();
	return 0;
}




