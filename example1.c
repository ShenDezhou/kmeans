#include <math.h>
#include <stdio.h>

#include "kmeans.h"

void kmeans(
            int  dim,		                     // dimension of data

            double *X,                        // pointer to data
            int   n,                         // number of elements

            int   k,                         // number of clusters
            double *cluster_centroid,         // initial cluster centroids
            int   *cluster_assignment_final  // output
           );
int main(int nargs, char **args) {
	double v[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
	double c[2] = {2.0, 5.0};
  int r[10];
  
  kmeans(1,
    v,
    10,
    2,
    c,
    r
  );

  printf("cluster result:");
  for (int ii = 0; ii < 10; ii++)
    printf("%d,", r[ii]);
	return 0;
}
