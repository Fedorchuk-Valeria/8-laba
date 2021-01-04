///1 индивидуальное, 11 вариант

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct bill
{
    char name[20];
    char surname[20];
    char patronymic[20];
    char address [20];
    int math;
    int rus;
    int ph;
    float overall_score;
};

void filling_the_arr (bill* array_of_struct, int n);
void output_the_arr (bill* array_of_struct, int n);
void array_padding(bill *&array_of_struct,int &size1);
void item_search (bill *&array_of_struct, int &size1);
void delete_srtuct (bill *&array_of_struct, int &size1);
void change_struct (bill* array_of_struct, int size1);
void sortquick (bill* array_of_struct, int left, int right);

int main()
{
    int N;
    printf("Enter number of entrants: ");
    scanf ("%d",&N);

    bill* array_of_struct = new bill[N];


    filling_the_arr (array_of_struct, N);

    printf("\n");

    //delete_srtuct (array_of_struct, N);
    //change_struct (array_of_struct, N);
    //array_padding(array_of_struct, N);
    item_search (array_of_struct, N);

    int left = 0;
    int right = N-1;
    sortquick (array_of_struct, left, right);

    printf("\n");
    printf("Bill:\n");
    output_the_arr (array_of_struct, N);

    delete [] array_of_struct;
    array_of_struct = nullptr;
    return 0;
}


void filling_the_arr (bill* array_of_struct, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Name: ");
        scanf("%s",array_of_struct[i].name);

        printf("Surname: ");
        scanf("%s",array_of_struct[i].surname);

        printf("Patronymic: ");
        scanf("%s",array_of_struct[i].patronymic);

        printf("Address: ");
        scanf("%s",array_of_struct[i].address);

        printf("Math score: ");
        scanf("%d",&array_of_struct[i].math);

        printf("Rus score: ");
        scanf("%d",&array_of_struct[i].rus);

        printf("Physics score: ");
        scanf("%d",&array_of_struct[i].ph);

        printf("Overall score: ");
        array_of_struct[i].overall_score = (array_of_struct[i].math + array_of_struct[i].rus + array_of_struct[i].ph) / 3.0;
        printf("%.3f", array_of_struct[i].overall_score);
        printf("\n");
        printf("\n");
    }

}


void output_the_arr (bill* array_of_struct, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Name: ");
        printf("%s",array_of_struct[i].name);
        printf("\n");

        printf("Surname: ");
        printf("%s",array_of_struct[i].surname);
        printf("\n");

        printf("Patronymic: ");
        printf("%s",array_of_struct[i].patronymic);
        printf("\n");

        printf("Address: ");
        printf("%s",array_of_struct[i].address);
        printf("\n");

        printf("Math score: ");
        printf("%d",array_of_struct[i].math);
        printf("\n");

        printf("Rus score: ");
        printf("%d",array_of_struct[i].rus);
        printf("\n");

        printf("Physics score: ");
        printf("%d",array_of_struct[i].ph);
        printf("\n");

        printf("Overall score: ");
        printf("%.3f",array_of_struct[i].overall_score);
        printf("\n");
        printf("\n");
    }
}

void array_padding(bill *&array_of_struct,int &size1)
{
    int k;
    printf("How many new entrants? ");
    scanf("%d",&k);

    bill* arrdop_or_struct = new bill[k];
    printf("\n");
    filling_the_arr(arrdop_or_struct, k);

    bill* newarr_or_struct = new bill[size1 + k];

    int i;
    for (i = 0; i < size1; i++)
    {
        newarr_or_struct[i] = array_of_struct[i];
    }


    int m;
    for(i = size1, m = 0; i < size1+k, m < k; i++, m++)
    {
        newarr_or_struct[i] = arrdop_or_struct[m];
    }
    size1 += k;
    delete [] array_of_struct;
    array_of_struct = newarr_or_struct;
    delete [] arrdop_or_struct;
    arrdop_or_struct = nullptr;

}



void item_search (bill *&array_of_struct, int &size1)
{
    printf("City? ");
    char city[10];
    scanf("%s", city);
    int count_struct = 0;
    for (int i = 0; i < size1; i++)
    {
        if(array_of_struct[i].address[0] == city[0] && array_of_struct[i].address[1] == city[1] && array_of_struct[i].address[2] == city[2])
            {
               count_struct++;
            }

    }

    bill* newarr_or_struct = new bill[count_struct];
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        if(array_of_struct[i].address[0] == city[0] && array_of_struct[i].address[1] == city[1] && array_of_struct[i].address[2] == city[2])
            {
               newarr_or_struct[k] = array_of_struct[i];
               k++;
            }

    }
    size1 = count_struct;
    delete [] array_of_struct;
    array_of_struct = newarr_or_struct;
}


void delete_srtuct (bill *&array_of_struct, int &size1)
{
    printf("How many applicants took the documents? ");
    int del;
    scanf("%d",&del);
    int* array_numb = new int [del];
    printf("\n");
    printf("Their numbers on the list: ");
    printf("\n");
    for(int i = 0; i < del; i++)
    {
        scanf("%d",&array_numb[i]);
    }

    bill* newarr_or_struct = new bill[size1 - del];

    int k = 0;
    int s = 0;
    int l = 0;
    while (s < size1)
    {
        if (s == array_numb[l]-1)
        {
            s++;
            l++;
        } else
        {
            newarr_or_struct[k] = array_of_struct[s];
            k++;
            s++;
        }
    }

    size1 = size1 - del;

    delete [] array_of_struct;
    array_of_struct = newarr_or_struct;
    delete [] array_numb;
    array_numb = nullptr;
}


void change_struct (bill* array_of_struct, int size1)
{
    printf("How many statements do you want to change? ");
    int change;
    scanf("%d",&change);
    int* array_numb = new int [change];
    printf("\n");
    printf("Their numbers on the list: ");
    printf("\n");
    for(int i = 0; i < change; i++)
    {
        scanf("%d",&array_numb[i]);
    }

    bill* newarr_or_struct = new bill[change];

    printf("Make changes: ");
    printf("\n");
    filling_the_arr (newarr_or_struct, change);

    int l = 0;
    int k = 0;
    for(int i = 0; i < size1; i++)
    {
        if (i == array_numb[l]-1)
        {
            array_of_struct[i] = newarr_or_struct[k];
            l++;
            k++;
        }
    }

    delete [] newarr_or_struct;
    newarr_or_struct = nullptr;
    delete [] array_numb;
    array_numb = nullptr;
}

void sortquick (bill* array_of_struct, int left, int right)
{

    int l = left;
    int r = right;
    bill main_element = array_of_struct[left];

    while(left < right)
    {
         while ((array_of_struct[right].overall_score <= main_element.overall_score) && left < right)
         {
             right--;
         }
         if (left != right)
         {
             array_of_struct[left] = array_of_struct[right];
             left++;
         }
         while ((array_of_struct[left].overall_score >= main_element.overall_score) && (left < right))
         {
             left++;
         }
         if (left != right)
         {
             array_of_struct[right] = array_of_struct[left];
             right--;
         }
    }

    array_of_struct[left] = main_element;
    int p = left;
    left = l;
    right = r;

    if (left < p)
    {
       sortquick(array_of_struct, left, p - 1);
    }
    if (right > p)
    {
       sortquick(array_of_struct, p + 1, right);
    }
}
