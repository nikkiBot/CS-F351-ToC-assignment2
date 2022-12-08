#include "main.h"

#define MAX_TOKENS (1000000)
#define MAX_LINE_LENGTH (1000000)
#define EXIT_SUCCESS 0

char tokens[MAX_TOKENS];
int num_tokens;


/**
 * @brief Reads the passed input file line by line.
 * Removes all space type characters from the lines, including \n (Carriage Return).
 * Modifies the global tokens and num_tokens variables.
 * @param filename The name of the file to read.
 * @return void
 */
void tokenize(char* filename) {

    FILE* in_file = fopen(filename, "r");

    char line[MAX_TOKENS];
    while (fgets(line, MAX_LINE_LENGTH, in_file)) {
        for (int i = 0; i < strlen(line); ++i) {
            if (line[i] == ' ' || line[i] == '\t' || line[i] == 10 /* ASCII 10 = Line Feed */ || line[i] == '\n') continue;

            tokens[num_tokens] = line[i];
            num_tokens++;
        }
    }
}

/**
 * @brief Creates a new node with the passed value.
 * @param value The value to be stored in the node.
 * @return A pointer to the newly created node.
 */
Node* create_node(char* value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief Prints the syntax tree
 * @param node any node of the syntax tree
 * @param depth the depth of the node in the syntax tree
 * @return void 
 */
void print_syntax_tree(Node* node, int depth) {
    if (node == NULL) return;
    for(int i = 0 ; i < depth; i++)
        printf(" ");
    printf(" %s\n", node->value);
    print_syntax_tree(node->left, depth + 1);
    print_syntax_tree(node->right, depth + 1);
}

int main(int argc, char** argv) {

    if (argc < 2) {
        perror("Pass the name of the input file as the first parameter. e.g.: ./simulator input.txt");
        exit(EXIT_FAILURE);
    }

    tokenize(argv[1]);

    return EXIT_SUCCESS;
}