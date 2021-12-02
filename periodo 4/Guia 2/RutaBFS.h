#ifndef RUTA_BFS_H
#define RUTA_BFS_H
#include <limits>
#include <list>
#include <iterator>

#include "Digrafo.h"

using std::list;

class RutaBFS{
	private:
		const int INFINITO = std::numeric_limits<int>::max();
		int vertices;
		bool *marcado;
		int *aristaHacia;
		int *distanciaHacia;
		void bfs(const Digrafo &G, int s);
	public:
		RutaBFS(const Digrafo &G, int s);
		RutaBFS(const RutaBFS &otra);
		~RutaBFS();
};
