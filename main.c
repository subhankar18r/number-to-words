#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    int index;
    struct Node *next;
} Node;

const char *words(int n);
char *hWords(int entered_number);
Node *insertAtFirst(Node *head, int data);

int main()
{

    int entered_number;
    printf("enter a number\n");
    scanf("%d", &entered_number);

    if (entered_number > 2147483647)
    {
        printf("please enter a smaller value\n");
        return 0;
    }

    Node *head = (Node *)malloc(sizeof(Node));
    head->index = 0;
    int modulas, i = 0, index = 1;

    while (entered_number > 0)
    {
        modulas = entered_number % 1000;
        head = insertAtFirst(head, modulas);
        head->index = index;
        entered_number /= 1000;
        i++;
        index++;
    }

    char ostr[100];

    while (head != NULL && head->index > 0)
    {
        strcat(ostr, hWords(head->data));
        if (head->index == 1)
        {
            strcat(ostr, "");
        }
        else if (head->index == 2)
        {
            strcat(ostr, "thousand ");
        }
        else if (head->index == 3)
        {
            strcat(ostr, "million ");
        }
        else if (head->index == 4)
        {
            strcat(ostr, "billion ");
        }
        head = head->next;
    }
    puts(ostr);

    return 0;
}
const char *words(int n)
{
    char *uniqueWords[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eightteen", "nineteen"};
    return uniqueWords[n];
}
char *hWords(int entered_number)
{
    static char str[100];
    strcpy(str, "");
    char *tenS[10] = {
        "tewnty ",
        "thirty ",
        "forty ",
        "fifty ",
        "sixty ",
        "seventy ",
        "eighty ",
        "ninety ",
    };

    if (entered_number < 20)
    {
        strcpy(str, (char *)words(entered_number));
    }
    else
    {
        int modulas;
        int numberarr[3];
        int i = 0;

        while (entered_number > 0)
        {
            modulas = entered_number % 10;
            numberarr[i] = modulas;
            entered_number /= 10;
            i++;
        }

        for (int i = 2; i >= 0; i--)
        {
            if (i == 2)
            {
                strcat(str, words(numberarr[i]));
                strcat(str, " hundread ");
            }
            if (i == 1 && numberarr[i] < 2)
            {
                strcat(str, words(numberarr[0] + 10));
                break;
            }
            else
            {
                if (i == 1)
                {

                    strcat(str, tenS[numberarr[i] - 2]);
                }
                if (i == 0)
                {
                    if (numberarr[i] != 0)
                    {
                        strcat(str, words(numberarr[i]));
                    }
                }
            }
        }
    }
    strcat(str, " ");
    return str;
}

Node *insertAtFirst(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
