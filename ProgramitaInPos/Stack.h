#include <string.h>
#include "Elem.h"
typedef struct Nodo{
	Elem dat;
	struct Nodo *sig;
}*Pila;
//Stack
Pila empty(){
	return NULL;
}
Pila push1(Elem e,Pila p){
	Pila p1;
	p1=(Pila)malloc(sizeof(struct Nodo));
	p1->dat=e;
	p1->sig=p;
	return p1;
}
int isEmpty1(Pila p){return p==NULL;}
Elem top1(Pila p){return p->dat;}
Pila pop1(Pila p){return p->sig;}
int isLetter(Elem c){return (c>='a'&&c<='z')||(c>='A'&&c<='Z');}
int isSign(char c){return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');}
int retSign(char c){return (c=='+'||c=='-')?(1):((c=='*'||c=='/')?(2):((c=='^')?(3):(4)));}

int balance(char *pal){
	int i=0,ban=0;
	Pila a=empty();
	while(pal[i]!='\0'){
		if(pal[i]=='('){
			if(isEmpty1(a)){
				a=push1(pal[i],empty());
			}else{
				a=push1(pal[i],a);
			}
		}else if(pal[i]==')'){
			if(isEmpty1(a)){
				printf("No esta balanceada debido a que falta de un o varios parentesis derechos\n");
				exit(1);
				ban=1;
				break;
			}else{
				if(isEmpty1(a)){
					printf("No esta balanceada debido a que falta de un o varios parentesis derechos\n");
					exit(1);
					ban=1;
					break;				
				}else{
					a=pop1(a);
				}
			}
		}
		i++;
	}
	if(ban!=0){
	}else{
		if(isEmpty1(a)){
			printf("Esta balanceada\n");
		}else{
			printf("No esta balanceada debido a que falta uno o más parentesis izquierdos\n");
			exit(1);
		}
	}

}

// Stack type
struct Stack{
    int top;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
struct Stack* createStack( unsigned capacity ){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if (!stack) 
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    if (!stack->array)
        return NULL;
    return stack;
}
int isEmpty(struct Stack* stack){
    return stack->top == -1 ;
}
char peek(struct Stack* stack){
    return stack->array[stack->top];
}
char pop(struct Stack* stack){
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, char op){
    stack->array[++stack->top] = op;
}
// A utility function to check if the given character is operand
int isOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch){
    switch (ch){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
 
 
// The main function that converts given infix expression
// to postfix expression. 
int convert(char* exp){
    int i, k;
 
    // Create a stack of capacity equal to expression size 
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) // See if stack was created successfully 
        return -1 ;
 
    for (i = 0, k = -1; exp[i]; ++i)
    {
        // If the scanned character is an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
         
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);
         
        // If the scanned character is an ‘)’, pop and output from the stack 
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression             
            else
                pop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
 
    }
 
    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack );
 
    exp[++k] = '\0';
    printf( "%s\n", exp );
}
