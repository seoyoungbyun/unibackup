#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	// ������ ����
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void graph_init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
// ���� ���� ����
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.
void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_degree(int degree[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", degree[i]);

	printf("\n");
}

// ���������� �����Ѵ�.
void topo_sort0(GraphType* g) // �������� ���ϴ� �κ��� �Ͻ������� ������
{
	int i;
	GraphNode* node;

	// ��� ������ ���� ������ ���
	int* in_degree = (int*)malloc(g->n * sizeof(int));
	int* out_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++)			// �ʱ�ȭ
		in_degree[i] = 0;
	for (i = 0; i < g->n; i++)			// �ʱ�ȭ
		out_degree[i] = 0;
	for (i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];//���� i���� ������ ������
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	// ���� �ڵ� �ۼ�: out_degree �迭�� ���� ���Ѵ�
	for (i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];//���� i���� ������ ������
		while (node != NULL) {
			out_degree[i]++;
			node = node->link;
		}
	}


		//print_degree(in_degree, g->n); 
		print_degree(out_degree, g->n);
	// ���ϴ� ����
}

int main(void) // �������� ����
{
	GraphType g;
	int u, v;
	int n;

	graph_init(&g);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		insert_vertex(&g, i);

	scanf("%d %d", &u, &v);
	while (u != -1) {
		insert_edge(&g, u, v);
		scanf("%d %d", &u, &v);
	}

	topo_sort0(&g);
	// ���� �޸� ��ȯ �ڵ� ����
	return 0;
}