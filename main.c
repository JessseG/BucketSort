#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMBUCKS 8

struct Node{
    char* string;
    struct Node* next;
};

struct Bucket{
    int minInitial;
    int maxInitial;
    int numWords;
    struct Node* head;
};

/* Initializes the lists of buckets with their particular ASCII codes.
    Also initializes the head Node pointer to NULL for later use*/
struct Bucket list[NUMBUCKS] = {
    'a', 'b', 0, NULL,
    'c', 'c', 0, NULL,
    'd', 'f', 0, NULL,
    'g', 'k', 0, NULL,
    'l', 'o', 0, NULL,
    'p', 'r', 0, NULL,
    's', 's', 0, NULL,
    't', 'z', 0, NULL
};

int main() {
    
    int i;
    char word[50];
    printf("\n");    
       
    while(1) {
        
        printf("Enter a word or enter 'stop' to print the nodes:");                     
        scanf("%s", word);                                                          // new word input

        if(strcmp(word, "stop") == 0) {                                             // check for 'stop' to terminate input loop
            break;
        }                                                                           // list[i].head =
        
        for(i=0; i< NUMBUCKS; i++) {                                                // loops through the Bucket list
            
            if(word[0] >= list[i].minInitial && word[0] <= list[i].maxInitial) {    // if the |word| starts with char between min & max initial

                struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));         // allocates memory to/for (newNode)
                newNode->string = (char*)malloc(sizeof(char));                            // allocates memory to/for [newNode->string]
                newNode->next = NULL;                                                     // assigns [newNode->next] with NULL
                strcpy(newNode->string, word);                                            // copies |word| to [newNode->string] 

                if(list[i].head == NULL) {                                          // if: the bucket's head Node is null(empty bucket),
                    list[i].head = newNode;                                                       // then assign the bucket's head Node with newNode.
                }
                else if (list[i].head != NULL) {                                    // else if: the buckets head Node already exists, then
                    struct Node *currentNode;                                                         // then declare currentNode as a pointer to a Node
                    currentNode = list[i].head;                                                       // tells currentNode to point to the bucket's head Node(1st Node)
                    //currentNode->next->next = NULL;

                    if(strcmp(word, currentNode->string) <= 0) {                                          // if: |word| comes before [currentNode->string] OR is equal to [currentNode->string],
                        newNode->next = currentNode;                                                                  // then newNode->next Node is assigned with currentNode and
                        list[i].head = newNode;                                                                       // tells the bucket's head Node ptr to point to newNode
                    }
                    else {                                                                                  // else if: |word| comes after [currentNode->string] alphabetically,

                        if(currentNode->next == NULL) {                                                         // if: second node is NULL, then add the new Node after the head Node
                            currentNode->next = newNode;
                        }
                        else if(strcmp(word, currentNode->next->string) <= 0) {                                 // else if: |word| is less than OR equal to 2nd Node's string, then
                            newNode->next = currentNode->next;                                                              // place new Node between the headNode and the second Node
                            currentNode->next = newNode;                                                                    // (readjust pointers to & from newNode)
                        }
                        else {                                                                                              // If the 1st and 2nd nodes are taken, then do the following
                            while(currentNode->next->next != NULL && strcmp(word, currentNode->next->string) > 0) {             // while: head.next.next node is not null AND string: |word| is greater than head.next.string,
                                currentNode = currentNode->next;                                                                        // then use currentNode to iterate through nodes until it reaches the correct slot for
                            }                                                                                                           // placing the new node (alphabetically) 
                            if(currentNode->next->next == NULL) {                                                           // If the next->next Node is NULL,
                                currentNode->next->next = newNode;                                                                // then assign the newNode to that NULL spot
                            }
                            else if(strcmp(word, currentNode->next->string) <= 0) {                                         // else if: |word| is less than OR equal to currentNode->next->string,
                                newNode->next = currentNode->next;                                                                        // then place the newNode right BEFORE currentNode->next & AFTER currentNode
                                currentNode->next = newNode;                                                                              // (readjust pointers to & from newNode)
                            }
                        }
                    }
                }
            }
        }
    }

    
    for(int j=0; j<NUMBUCKS; j++) {                                 // Iterates through the list of buckets(0-7)

        while(list[j].head == NULL){                                // Skips through empty buckets
            j++;
            if(j == 7) {                                            // Stops skipping at 7 since there's only 8 buckets
                break;
            }
        }
        
        struct Node *currNode = list[j].head;

        while(currNode != NULL) {                               // Iterates through the nodes in each bucket
            printf("%s -> ", currNode->string);                         // Print out the string value in each node
            currNode = currNode->next;                                  // reassigns the current Node pointer to the next Node for iterating through nodes
        }                                                               // until the current Node is NULL(empty)

    }
    printf("\n");

    return 0;
}