#ifndef FLO_WAS_HERE
#define FLO_WAS_HERE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NBC 7 // Number of column
#define NBL 6 // Number of line



typedef struct Node{
    float weights[NBL * NBC];
    float bias;
}Node;

void randomizeNode(Node* node);
float evalNode(Node* node);

#endif