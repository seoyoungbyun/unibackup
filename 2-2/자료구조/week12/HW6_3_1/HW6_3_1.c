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

// 그래프 초기화
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

	// 코드 삽입
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

	// 코드 삽입
	fprintf(fp, "%d\n", g->n);
	for (i = 0; i < g->n; i++)
		for (j = i; j < g->n; j++) {
			if (g->adj_mat[i][j] != INF)
				fprintf(fp, "%d %d %d\n", i, j, g->adj_mat[i][j]);
		}

	if (filename != NULL) fclose(fp);
}
// 인접 행렬이나 인접 리스트에서 간선들을 읽어서 최소 히프에 삽입
// 현재는 예제 그래프(교재 [그림 10-25])의 간선들을 삽입한다.
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
// kruskal 의 최소 비용 신장 트리 프로그램
void kruskal(GraphType *g, GraphType *t)
{
	int edge_accepted = 0; // 현재까지 선택된 간선의 수
	HeapType h; // 최소 히프
	int uset, vset; // 정점 u 와 정점 v 의 집합 번호
	element e; // 히프 요소
	
	
	init(&h); // 히프 초기화
	insert_all_edges(&h, g);
	set_init(g->n); // 집합 초기화
	
	printf("선택된 간선<순서대로>:\n");
	while (edge_accepted < (g->n - 1)) // 간선의 수 < (n-1)
	{
		e = delete_min_heap(&h); // 최소 히프에서 삭제: 가장 key(weight)가 작은 간선
		uset = set_find(e.u); // 정점 u 의 집합 번호
		vset = set_find(e.v); // 정점 v 의 집합 번호
		if (uset != vset) { // 서로 속한 집합이 다르면, 즉 사이클이 생기지 않으면
			printf("<%d,%d> %d \n", e.u, e.v, e.key);
			edge_accepted++;
			set_union(uset, vset); // 두개의 집합을 합친다.
			t->adj_mat[e.u][e.v] = e.key;
		}
	}
	printf("\n");
}

int main(void)
{
	GraphType g, t;		// 입력 그래프, 결과 트리

	graph_init(&g);
	//read_graph(&g, "input1.txt");
	read_graph(&g, "input2.txt");

	graph_init(&t);
	t.n = g.n;

	kruskal(&g, &t);

	printf("파일로 출력:\n");
	write_graph(&t, "output.txt");
	write_graph(&t, NULL);	// to stdout
}