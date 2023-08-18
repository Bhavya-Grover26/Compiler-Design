#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 200

struct node
{
    char lexeme[MAX];
    char token[MAX];
    struct node *next;
};
struct node *head = NULL;

void insertbeg(char *str1 , char *str2)
{

    //create a link
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   strcpy(lk->lexeme, str1);
   strcpy(lk->token, str2);

   // point it to old first node
   lk->next = head;

   //point first to new first node
   head = lk;
}

// display the list
void printList(){
   struct node *p = head;
   //start from the beginning
   while(p != NULL) {
      printf(" %s  ->",p->lexeme);
      printf(" %s \n",p->token);
      p = p->next;
   }
}

void insertatend(char *str1, char *str2)
{

   //create a link
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   strcpy(lk->lexeme, str1);
   strcpy(lk->token, str2);
   struct node *linkedlist = head;

   // point it to old first node
   while(linkedlist->next != NULL)
      linkedlist = linkedlist->next;

   //point first to new first node
   linkedlist->next = lk;
}

int searchlist(char *key)
{
   struct node *temp = head;
   while(temp != NULL) {
      if (!strcmp(temp->lexeme,key)) {
         return 1;
      }
      temp=temp->next;
   }
   return 0;
}

bool isKeyword(char* str)
{
 if (!strcmp(str, "auto") || !strcmp(str, "default")
 || !strcmp(str, "signed") || !strcmp(str, "enum")
 ||!strcmp(str, "extern") || !strcmp(str, "for")
 || !strcmp(str, "register") || !strcmp(str, "if")
 || !strcmp(str, "else") || !strcmp(str, "int")
 || !strcmp(str, "while") || !strcmp(str, "do")
 || !strcmp(str, "break") || !strcmp(str, "continue")
 || !strcmp(str, "double") || !strcmp(str, "float")
 || !strcmp(str, "return") || !strcmp(str, "char")
 || !strcmp(str, "case") || !strcmp(str, "const")
 || !strcmp(str, "sizeof") || !strcmp(str, "long")
 || !strcmp(str, "short") || !strcmp(str, "typedef")
 || !strcmp(str, "switch") || !strcmp(str, "unsigned")
 || !strcmp(str, "void") || !strcmp(str, "static")
 || !strcmp(str, "struct") || !strcmp(str, "goto")
 || !strcmp(str, "union") || !strcmp(str, "volatile"))
 return (true);
 return (false);
}
bool isConstant(char* str)
{
 if (isdigit(str[0]) != 0)
 return(true);
 return(false);
}
bool isOperator(char* str)
{
 if (!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") ||
 !strcmp(str, "/") || !strcmp(str, ">")|| !strcmp(str, "<") ||
 !strcmp(str, "="))
 return (true);
 return (false);
}
bool isIdentifier(char* str)
{
 if (isalpha(str[0]) != 0)
 return (true);
 return (false);
}
bool isSpecial(char* str)
{
 for (int i = 0; i < strlen(str); ++i)
 {
 if(str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$'
 || str[i] == '%' || str[i] == '^' || str[i] == '&' || str[i] == '*'
 || str[i] == '(' || str[i] == ')' || str[i] == '-' || str[i] == '{'
 || str[i] == '}' || str[i] == '[' || str[i] == ']' || str[i] == ':'
 || str[i] == ';' || str[i] == '"' || str[i] == '\'' || str[i] == '<'
 || str[i] == '>' || str[i] == '.' || str[i] == '/' || str[i] == '?'
 || str[i] == '~' || str[i] == '`' )
 {
 return true;
 }
 }
 return false;
}
bool isDelimiter(char* str)
{
 if(!strcmp(str, ";"))
 return true;
 else
 return false;
}
int main()
{
     char str[MAX];
     printf("Enter a expression with whitespaces (enter a space at end also): ");
     fgets(str,200,stdin);
     char *token = strtok(str , " ");
     insertbeg("Token", "Lexeme");
     while(token!=NULL)
     {
        if(isKeyword(token))
        {
         insertatend(token, "Keyword");
        }
        else if(isOperator(token))
         {
             insertatend(token, "Operator");
         }
         else if(isConstant(token))
         {
             insertatend(token, "Constant");
         }
         else if(isIdentifier(token))
         {
         if(!isSpecial(token))
         insertatend(token, "Identifier");
         else
         printf(" \n Incorrect Identifier are: %s",token);
         }
         else if(isDelimiter(token))
         {
         insertatend(token, "Delimiter");
         }
         token = strtok(NULL, " ");
     }
     printList();
     char search[MAX];
   int k;
   printf("Enter a lexeme to be searched : ");
   scanf("%s",search);
    k = searchlist(search);
   if (k == 1)
      printf("\nElement is found");
   else
      printf("\nElement is not present in the list");

     return 0;
}
