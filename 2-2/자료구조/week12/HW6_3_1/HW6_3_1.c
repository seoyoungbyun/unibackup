#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "minheap.h"
#include "unionfind.h"

#define MAX_VERTICES 100
#define INF 9999

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// �׷��� �ʱ�ȭ
void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->adj_mat[i][j] = INF;
		}
	}
}
void read_graph(GraphType* g, char* filename)
{
	int number, u, v, w;
	FILE* fp;
	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("file %s open error!\n", filename);
		return;
	}

	// �ڵ� ����
	fscanf(fp, "%d", &number);
	g->n = number;
	while (EOF != fscanf(fp, "%d %d %d", &u, &v, &w)) {
		g->adj_mat[u][v] = w;
		g->adj_mat[v][u] = w;
	}

	fclose(fp);
}
void write_graph(GraphType* g, char* filename)
{
	int i, j;
	FILE* fp;

	if (filename == NULL) fp = stdout;
	else {
		fp = fopen(filename, "wt");
		if (fp == NULL)
		{
			printf("file %s open error!\n", filename);
			return;
		}
	}

	// �ڵ� ����
	fprintf(fp, "%d\n", g->n);
	for (i = 0; i < g->n; i++)
		for (j = i; j < g->n; j++) {
			if (g->adj_mat[i][j] != INF)
				fprintf(fp, "%d %d %d\n", i, j, g->adj_mat[i][j]);
		}

	if (filename != NULL) fclose(fp);
}
// ���� ����̳� ���� ����Ʈ���� �������� �о �ּ� ������ ����
// ����� ���� �׷���(���� [�׸� 10-25])�� �������� �����Ѵ�.
void insert_all_edges(HeapType* h, GraphType *g)
{
	for (int i = 0; i < g->n; i++)
		for (int j = i + 1; j < g->n; j++) {
			if (g->adj_mat[i][j] != INF) {
				element e;
				e.u = i;
				e.v = j;
				e.key = g->adj_mat[i][j];
				insert_min_heap(h, e);
			}
		}
}
// kruskal �� �ּ� ��� ���� Ʈ�� ���α׷�
void kruskal(GraphType *g, GraphType *t)
{
	int edge_accepted = 0; // ������� ���õ� ������ ��
	HeapType h; // �ּ� ����
	int uset, vset; // ���� u �� ���� v �� ���� ��ȣ
	element e; // ���� ���
	
	
	init(&h); // ���� �ʱ�ȭ
	insert_all_edges(&h, g);
	set_init(g->n); // ���� �ʱ�ȭ
	
	printf("���õ� ����<�������>:\n");
	while (edge_accepted < (g->n - 1)) // ������ �� < (n-1)
	{
		e = delete_min_heap(&h); // �ּ� �������� ����: ���� key(weight)�� ���� ����
		uset = set_find(e.u); // ���� u �� ���� ��ȣ
		vset = set_find(e.v); // ���� v �� ���� ��ȣ
		if (uset != vset) { // ���� ���� ������ �ٸ���, �� ����Ŭ�� ������ ������
			printf("<%d,%d> %d \n", e.u, e.v, e.key);
			edge_accepted++;
			set_union(uset, vset); // �ΰ��� ������ ��ģ��.
			t->adj_mat[e.u][e.v] = e.key;
		}
	}
	printf("\n");
}

int main(void)
{
	GraphType g, t;		// �Է� �׷���, ��� Ʈ��

	graph_init(&g);
	//read_graph(&g, "input1.txt");
	read_graph(&g, "input2.txt");

	graph_init(&t);
	t.n = g.n;

	kruskal(&g, &t);

	printf("���Ϸ� ���:\n");
	write_graph(&t, "output.txt");
	write_graph(&t, NULL);	// to stdout
}