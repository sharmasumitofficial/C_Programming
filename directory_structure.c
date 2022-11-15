
/*           DIRECTORY STRUCTURE          */

/*Submitted to*/
/* Dr. T Sobha Rani mam*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct directory
{
	struct directory *left;
	char info[MAX];
	struct directory *add;
	struct directory *right;
}direc;

direc *root;
direc *root1;
static int count = 0;

void createemptydirec()
{
	root = NULL;
	root1 = NULL;
}

void insertrootdirectory(char *nam)
{

	if (root == NULL)
	{
		root = (direc *)malloc(sizeof(direc));
		strcpy((root)->info, nam);
		(root)->left = NULL;
		(root)->right = NULL;
		(root)->add = NULL;
	}
}

direc* searchrecursive(direc* node, char * parent)
{

	if ((node) != NULL)
	{
		if ((strcmp((node)->info, parent)) == 0)
		{
			root1 = node;
		}
		searchrecursive(((node)->left), parent);
		searchrecursive(((node)->right), parent);

	}

}

void insertsubdirectory(char *nam, char  *parent)
{


	direc *subdir;
	subdir = (direc *)malloc(sizeof(direc));
	if (subdir == NULL)
		printf("\nmemory  cann't  allocated");
	if (strcmp((root)->info, parent) == 0)
	{
		if (((root)->left) == NULL)
		{
			strcpy((subdir)->info, nam);
			((subdir)->left) = ((subdir)->right) = NULL;
			(subdir)->add = root;
			(root)->left = subdir;
		}
		else
		{
			direc *temp;
			temp = (direc *)malloc(sizeof(direc));
			temp = (root)->left;
			while ((temp)->right != NULL)
				temp = (temp)->right;
			strcpy((subdir)->info, nam);
			((subdir)->left) = ((subdir)->right) = NULL;
			(subdir)->add = root;
			(temp)->right = subdir;
		}
	}

	else
	{
		direc *para, *temp, *subdir;
		subdir = (direc *)malloc(sizeof(direc));
		temp = (root)->left;
		searchrecursive(temp, parent);
		if (root1 != NULL)
			printf("\n %s", (root1)->info);
		if (root1 == NULL)
		{
			printf("\n\t NOT found\n \t Restart again\n");
			exit(0);

		}

		if ((root1)->left == NULL)
		{
			strcpy((subdir)->info, nam);
			((subdir)->left) = ((subdir)->right) = NULL;
			(subdir)->add = root1;
			(root1)->left = subdir;
		}
		else
		{
			direc *temporary;
			temporary = (direc *)malloc(sizeof(direc));
			temporary = (root1)->left;
			while (((temporary)->right) != NULL)
				temporary = (temporary)->right;
			strcpy((subdir)->info, nam);
			((subdir)->left) = ((subdir)->right) = NULL;
			(subdir)->add = root1;
			(temporary)->right = subdir;
		}
	}
	root1 = NULL;

}

void searchdirectory(char* name)
{
	direc *temp1, *foun, *addr;

	if (strcmp(root->info, name) == 0)
		printf("Directory found n its root directory\n");
	else
	{


		temp1 = (root)->left;
		searchrecursive(temp1, name);
		if (root1 == NULL)
		{
			printf("\n\t NOT found\n \t Restart again\n");
			exit(0);
		}
		addr = (root1)->add;
		if (root1 != NULL)
		{
			printf("\n\tFOUND ");
			printf("\n\tParent Directory is ""%s"" ", (addr)->info);


			printf("\n\tPath is  \n");
			printf(" \t%s -->", name);

			while ((addr)->add != NULL)
			{
				printf("%s\t -->", (addr)->info);
				addr = (addr)->add;
			}
			printf(" %s  ", root->info);
			printf("\n\n");


		}
	}
	root1 = NULL;
}

void delete(char* name)
{
	direc *found, *temp1, *parent, *first, *temp2, *prev;
	if (strcmp(root->info, name) == 0)
	{
		printf("\n\tRoot Directory is Deleted \n\tNow, No tree is there");
		root = NULL;
		count = 0;
	}
	else
	{
		temp1 = (root)->left;
		searchrecursive(temp1, name);
		if (root1 == NULL)
		{
			printf("\n\t NOT found\n \t Restart again\n");
			exit(0);
		}
		parent = root1->add;
		temp2 = parent->left;
		first = parent->left;
		while (strcmp(temp2->info, name) != 0)
		{
			prev = temp2;
			temp2 = temp2->right;
		}
		if (strcmp(temp2->info, first->info) == 0)
		{
			parent->left = first->right;
			first = NULL;
			count--;
			printf("\n\tDELETED");
		}
		else
		{
			prev->right = temp2->right;
			temp2 = NULL;
			count--;
			printf("\n\t\tDELETED");
		}

	}
	root1 = NULL;
}

void display(char* name)
{
	direc *temp, *addr;
	if (strcmp(root->info, name) == 0)
	{
		printf("\nDirectory is Root directory");
		if (root->left != NULL)
		{
			temp = root->left;
			printf("\n\tChild are\t");
			while ((temp)->right != NULL)
			{
				printf("%s \t ", (temp)->info);
				temp = (temp)->right;
			}
			printf("%s ", (temp)->info);
		}
	}
	else
	{
		temp = (root)->left;
		searchrecursive(temp, name);
		if (root1 == NULL)
		{
			printf("\n\t NOT found\n \t Restart again\n");
			exit(0);

		}
		addr = (root1)->add;
		printf("\tparent is %s \n", (addr)->info);
		if (root1->left != NULL)
		{
			temp = root1->left;
			printf("\tChilds are ");
			while ((temp)->right != NULL)
			{
				printf("%s \t", (temp)->info);
				temp = (temp)->right;
			}
			printf("%s ", (temp)->info);
			printf("\n\n");
		}
	}
}

int main()
{

	int ch;
	char dir[MAX], par[MAX];
	createemptydirec();
	while (1)
	{
		printf(" \n  DIRECTORY STRUCTURE\n");
		printf("++++++++++++++++++++++++++++++++\n\n");
		printf(" 1. Insert directory\n");
		printf(" 2. Search Directory\n");
		printf(" 3. Display Directory\n");
		printf(" 4. Delete Directory\n");
		printf(" 0. Exit\n");
		printf("enter the choice\n\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			if (count == 0)
			{
				printf("Enter the Root Directory\n");
				scanf("%s", dir);
				count++;
				insertrootdirectory(dir);
				printf("Total no of Directory is  %d\n", count);
			}

			else
			{
				printf("enter the Superdirectory or parent directory\n");
				scanf("%s", par);
				printf("enter the Directory u want to insert\n");
				scanf("%s", dir);
				insertsubdirectory(dir, par);
				count++;
				printf("\nTotal no of Directory is  %d\n", count);
			}

			break;

		case 2:
			if (count == 0)
			{
				printf("Directory list is empty\n");
				exit(0);
			}
			else
				printf("Enter the Directory u want to search\n");
			scanf("%s", dir);
			searchdirectory(dir);
			break;
		case 3:
			if (count == 0)
			{
				printf("Directory list is empty\n");
				exit(0);
			}
			printf("\nenter the directory which u want to see\n");
			scanf("%s", dir);
			display(dir);
			break;
		case 4:
			if (count == 0)
			{
				printf("Directory list is empty\n");
				exit(0);
			}
			printf("enter the Directory u want to delete\n");
			scanf("%s", dir);
			delete(dir);
			break;
		case 0:
			printf("THANKS FOR USING\n");
			exit(0);
		default:
			printf("you entered wrong choice\n\n");

		}


	}
}
