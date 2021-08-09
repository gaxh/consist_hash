#include <stdio.h>

#include "consist_hash.h"

int main()
{
    consist_hash<int, std::hash<int>> hash;

    for(int i = 0; i < 5; ++i)
    {
        hash.insert_node( i*2 );
    }

    printf("--- after init all nodes\n");

    for(int i = 0; i < 10; ++i)
    {
        int node;
        bool found = hash.find_node( i, node );

        printf("found node for hash %d: %d\n", i, found ? node : -1);
    }

    hash.insert_node(3);

    printf("--- after insert new node\n");

    for(int i = 0; i < 10; ++i)
    {
        int node;
        bool found = hash.find_node( i, node );

        printf("found node for hash %d: %d\n", i, found ? node : -1);
    }

    hash.delete_node(3);

    printf("--- after delete new node\n");

    for(int i = 0; i < 10; ++i)
    {
        int node;
        bool found = hash.find_node( i, node );

        printf("found node for hash %d: %d\n", i, found ? node : -1);
    }

    hash.delete_node(2);
    
    printf("--- after delete old node\n");

    for(int i = 0; i < 10; ++i)
    {
        int node;
        bool found = hash.find_node( i, node );

        printf("found node for hash %d: %d\n", i, found ? node : -1);
    }

    hash.insert_node(2);

    printf("--- after resume old node\n");

    for(int i = 0; i < 10; ++i)
    {
        int node;
        bool found = hash.find_node( i, node );

        printf("found node for hash %d: %d\n", i, found ? node : -1);
    }

    return 0;
}

