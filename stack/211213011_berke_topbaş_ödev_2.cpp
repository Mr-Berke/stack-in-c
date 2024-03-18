#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct node {
    char harf;
    struct node* next;
    struct node* prev;    
};

struct node *top = NULL, *next = NULL, *prev = NULL;

void ekle(char harf) {
    struct node* yeni = (struct node*)malloc(sizeof(struct node));

    if (top == NULL) {
        yeni->harf = harf;
        yeni->next = NULL;
        yeni->prev = NULL;
        top = yeni;
    }
    else {
    	yeni->harf=harf;
    	top->next=yeni;
    	yeni->prev=top;
    	yeni->next=NULL;
    	top=yeni;        
    }
}

int cikar() 
{
    if (top == NULL) 
	{
        printf("stack bos\n");
        return -1;
    }

    struct node* temp = top;
    char data = temp->harf;

    if (top->prev == NULL) 
	{
        free(temp);
        top = NULL;
    }
    else 
	{
        top = top->prev;
        top->next = NULL;
        free(temp);
    }
    return data;
}

int main() {
    srand(time(NULL));
    char dizi[10];

    char sesli[5] = {'a','e','u','o','i'};
    char sessiz[20] = {'w','r','t','y','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};

    for (int i = 0; i < 10; i++) 
	{
		if(i%2==0)
		{
			dizi[i] = sesli[rand() % 5];
		}
		else
		{
			dizi[i] = sessiz[rand() % 20];
		}
	}
	    
    for (int i = 0; i < 6; i++) 
	{
        printf("eklenen harf:%c\n", dizi[i]);
        ekle(dizi[i]);
    }

    while (top != NULL) 
	{
        int k = cikar();
        if (k != -1) 
		{
            printf("cikarilan harf:%c\n", k);
        }
    }

    return 0;
}

