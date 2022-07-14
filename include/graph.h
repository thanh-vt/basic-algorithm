#ifndef GRAPH_MODULE_H
#define GRAPH_MODULE_H

#include <common_matrix.h>

void graphModule();

void isTournamentDemo();

int isTournament(int n, arr_int fromV, arr_int toV);

void componentSizeDemo();

int componentSize(matrix_bool matrix, int vertex);

void bfsDistancesUnweightedGraphDemo();

arr_int bfsDistancesUnweightedGraph(matrix_bool matrix, int startVertex);

#endif
