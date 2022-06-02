#include <stdio.h>
#include <stdlib.h>

const int WHITE = 0, YELLOW = 1, GREEN = 2;

typedef struct node_ptr
{
    int v;
    struct node_ptr *next;
} Node;

Node *create_adj_list(int V[], int n)
{
    Node *s_node = (Node *)malloc(sizeof(Node));
    s_node->v = V[0];
    s_node->next = NULL;

    Node *s_temp = s_node;
    for (int i = 1; i < n; i++)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->v = V[i];
        temp->next = NULL;
        s_temp->next = temp;
        s_temp = temp;
    }
    return s_node;
}

int dfs_find_cycle(Node *arr_node[], Node *node, int color[], int pi[])
{
    int u = node->v;
    int index = u - 1;

    color[index] = YELLOW;
    Node *temp = node->next;
    while (temp != NULL)
    {
        int v = temp->v;
        int idx = v - 1;
        if (color[idx] == WHITE)
        {
            pi[idx] = u;
            if (dfs_find_cycle(arr_node, arr_node[idx], color, pi))
                return 1;
        }
        else if (v != pi[index])
        {
            // v đã được thăm và v không phải là được gọi đệ quy ở bước trước của u
            return 1;
        }
        temp = temp->next;
    }
    color[index] = GREEN;
    return 0;
}

void DFS(Node *arr_node[], int n)
{
    int color[n], pi[n]; // pi[i] là đỉnh cha của đỉnh (i+1)
    for (int i = 0; i < n; i++)
    {
        color[i] = WHITE;
        pi[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        Node *node = arr_node[i];
        int u = node->v;
        if (color[u - 1] == WHITE)
        {
            if (dfs_find_cycle(arr_node, node, color, pi))
            {
                printf("Graph contains cycle\n");
                return;
            }
        }
    }
    printf("Graph does not contain cycle\n");
}

int main()
{
    int arr_1[] = {1, 2, 4};
    int arr_2[] = {2, 1, 3, 5};
    int arr_3[] = {3, 2};
    int arr_4[] = {4, 1};
    int arr_5[] = {5, 2}; // Not Cycle

    // int arr_1[] = {1, 2, 4};
    // int arr_2[] = {2, 1, 3, 4, 5};
    // int arr_3[] = {3, 2};
    // int arr_4[] = {4, 1, 2};
    // int arr_5[] = {5, 2};  // Cycle

    // int arr_1[] = {1, 2, 4};
    // int arr_2[] = {2, 1, 3, 5};
    // int arr_3[] = {3, 2, 5};
    // int arr_4[] = {4, 1};
    // int arr_5[] = {5, 2, 3};  // Cycle

    Node *arr_node[5] = {
        create_adj_list(arr_1, sizeof(arr_1) / sizeof(int)),
        create_adj_list(arr_2, sizeof(arr_2) / sizeof(int)),
        create_adj_list(arr_3, sizeof(arr_3) / sizeof(int)),
        create_adj_list(arr_4, sizeof(arr_4) / sizeof(int)),
        create_adj_list(arr_5, sizeof(arr_5) / sizeof(int)),
    };

    for (int i = 0; i < 5; i++)
    {
        Node *n = arr_node[i];
        while (n != NULL)
        {
            printf("%d", n->v);
            n = n->next;
        }
        printf("\n");
    }

    DFS(arr_node, 5);

    return 0;
}
