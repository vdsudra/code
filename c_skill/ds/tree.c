
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int value;
    struct node *left;
    struct node *rigth;
}*root = NULL, *temp = NULL, *t2, *t1;

int delete1();
int insert();
int delete();
int inorder(struct node *t);
int create();
int search(struct node *t);
int preorder(struct node *t);
int postorder(struct node *t);
int search1(struct node *t,int data);
int smallest(struct node *t);
int largest(struct node *t);

int flag = 1;
int tree()
{
    int ch;
    printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Delete an element from the tree\n");
    printf("3 - Inorder Traversal\n");
    printf("4 - Preorder Traversal\n");
    printf("5 - Postorder Traversal\n");
    printf("6 - Exit\n");
    while(1)
    {
    	printf("1)Insert\n2)Delete\n3)Inorder Traversal\n"
    			"4)Preorder Traversal\n5)Postorder Traversal\n6)Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            return 0;
        default :
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

/* To insert a node in the tree */
int insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        search(root);
    return 0;
}


/* To create a node */

int create()

{
    int data;
    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp = (struct node *)malloc(1*sizeof(struct node));
    temp->value = data;
    temp->left = temp->rigth = NULL;
    return 0;
}

/* Function to search the appropriate position to insert the new node */

int search(struct node *t)

{

    if ((temp->value > t->value) && (t->rigth != NULL))      /* value more than root node value insert at right */
        search(t->rigth);
    else if ((temp->value > t->value) && (t->rigth == NULL))
        t->rigth = temp;
    else if ((temp->value < t->value) && (t->left != NULL))    /* value less than root node value insert at left */
        search(t->left);
    else if ((temp->value < t->value) && (t->left == NULL))
        t->left = temp;
    return 0;
}



/* recursive function to perform inorder traversal of tree */

int inorder(struct node *t)

{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return 0;
    }
    if (t->left != NULL)
        inorder(t->left);
    printf("%d -> ", t->value);
    if (t->rigth != NULL)
        inorder(t->rigth);
    return 0;

}

/* To check for the deleted node */

int delete()

{
    int data;
    if (root == NULL)
    {
        printf("No elements in a tree to delete");
        return 0;
    }
    printf("Enter the data to be deleted : ");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    search1(root, data);
    return 0;
}


/* To find the preorder traversal */

int preorder(struct node *t)

{

    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return 0;
    }

    printf("%d -> ", t->value);
    if (t->left != NULL)
        preorder(t->left);
    if (t->rigth != NULL)
        preorder(t->rigth);
    return 0;
}

/* To find the postorder traversal */

int postorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return 0;
    }
    if (t->left != NULL)
        postorder(t->left);
    if (t->rigth != NULL)
        postorder(t->rigth);
    printf("%d -> ", t->value);
    return 0;
}



/* Search for the appropriate position to insert the new node */

int search1(struct node *t, int data)
{
    if ((data>t->value))
    {
        t1 = t;
        search1(t->rigth, data);
    }
    else if ((data < t->value))
    {
        t1 = t;
        search1(t->left, data);
    }
    else if ((data==t->value))
    {
        delete1(t);
    }
    return 0;
}


/* To delete a node */

int delete1(struct node *t)
{
    int k;
    /* To delete leaf node */
    if ((t->left == NULL) && (t->rigth == NULL))
    {
        if (t1->left == t)
        {
            t1->left = NULL;
        }
        else
        {
            t1->rigth = NULL;
        }
        t = NULL;
        free(t);
        return 0;
    }

    /* To delete node having one left hand child */

    else if ((t->rigth == NULL))
    {
        if (t1 == t)
        {
            root = t->left;
            t1 = root;
        }
        else if (t1->left == t)
        {
            t1->left = t->left;
        }
        else
        {
            t1->rigth = t->left;
        }
        t = NULL;
        free(t);
        return 0;
    }


    /* To delete node having right hand child */

    else if (t->left == NULL)
    {
        if (t1 == t)
        {
            root = t->rigth;
            t1 = root;
        }
        else if (t1->rigth == t)
            t1->rigth = t->rigth;
        else
            t1->left = t->rigth;
        t == NULL;
        free(t);
        return 0;
    }

    /* To delete node having two child */

    else if ((t->left != NULL) && (t->rigth != NULL))
    {
        t2 = root;
        if (t->rigth != NULL)
        {
            k = smallest(t->rigth);
            flag = 1;
        }
        else
        {
            k =largest(t->left);
            flag = 2;
        }
        search1(root, k);
        t->value = k;
    }
    return 0;
}

/* To find the smallest element in the right sub tree */

int smallest(struct node *t)
{
    t2 = t;
    if (t->left != NULL)
    {
        t2 = t;
        return(smallest(t->left));
    }
    else
        return (t->value);
}

/* To find the largest element in the left sub tree */

int largest(struct node *t)
{
    if (t->rigth != NULL)
    {
        t2 = t;
        return(largest(t->rigth));
    }
    else
        return(t->value);
}
