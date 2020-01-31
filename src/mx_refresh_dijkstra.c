#include "pathfinder.h"

void mx_refresh_dijkstra(int ***dijkstra, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= n; i++) {
            if (dijkstra[j][0][i] == -2147483648)
                dijkstra[j][0][i] = 0;
        }
    }
}
