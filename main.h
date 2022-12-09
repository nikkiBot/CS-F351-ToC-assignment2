#ifndef MAIN_H_     // Include guard
#define MAIN_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//structure to hold a node in syntax tree
typedef struct Node {
    char* value;
    struct Node* left;
    struct Node* right;
} Node ;

//Function prototypes
void tokenize(char* filename) ;
Node* create_node(char* value);
void print_syntax_tree(Node* node, int depth);
Node* parse(char* program, int num_tokens);
void checkFile(FILE* in_file);


#endif
