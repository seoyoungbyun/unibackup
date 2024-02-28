#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
	int n; // 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES]; /* 방문한 정점 표시 */
int previous[MAX_VERTICES];

void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->weight[i][j] = INF;
		}
	}
}
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}
void read_graph(GraphType* g)
{
	int number, u, v, w;
	/*FILE* fp;
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
		g->weight[u][v] = w;
		g->weight[v][u] = w;
	}

	fclose(fp);*/
	scanf("%d", &number);
	g->n = number;
	scanf("%d %d %d", &u, &v, &w);
	while (u != -1) {
		g->weight[u][v] = w;
		g->weight[v][u] = w;
		scanf("%d %d %d", &u, &v, &w);
	}
}
void print_path(GraphType* g, int start, int end) {
	if (start == end)
		printf("%d", start);
	else {
		print_path(g, start, previous[end]);
		int before = previous[end];
		printf("-<%d>->%d", g->weight[before][end], end);
	}
}
void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
		previous[i] = start;
	}
	found[start] = TRUE; /* 시작 정점 방문 표시 */
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		//print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w]) {
					distance[w] = distance[u] + g->weight[u][w];
					previous[w] = u;
				}
		print_path(g, start, u);
		printf("(%d)\n", distance[u]);
	}
}
int main(void)
{
	GraphType g;

	graph_init(&g);
	read_graph(&g);

	int start;
	scanf("%d", &start);
	shortest_path(&g, start);
}