//2018.8.30
//将票房数据二分类，根据min-max分成两部分
//cluster0:34734
//cluster1:220
//这说明大部分电影票房都是0，只有几部票房较好，我好像发现了什么
//绝大多数演员都是在打工，也只有两千里挑一的人能演高票房电影
//centroid0:0.0， centroid1:0.5
//原始数据中没有票房数据的电影10861部，占比0.3107

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "kmeans.h"
#define DIM 1
#define ELES 34954
void kmeans(
  int dim,					// dimension of data
  double *X,					// pointer to data
  int n,					// number of elements
  int k,					// number of clusters
  double *cluster_centroid,			// initial cluster centroids
  int   *cluster_assignment_final		// output
  );

int main(int nargs, char **args) {
  double v[ELES];
  FILE* fp;
  char* line=NULL;
  size_t len = 0;
  ssize_t read;
  size_t index = 0;
  int n=0;
  double min_v=10000.0l;
  double max_v=0.0l;
  double c[2] = {0.0l,1.0l};
  int r[ELES];
  fp = fopen("BoxOffice.dat","r");
  while ((read = getline(&line, &len, fp)) != -1) {
    if (read>0) {
      v[index++] = atof(line);
      if(min_v>v[index-1]) min_v = v[index-1];
      if(max_v<v[index-1]) max_v = v[index-1];
    }
    else
      v[index++] = -1.0l;
  }
  fclose(fp);
  n=index;
	// 归一化0-1
  for(int ii=0; ii < index; ii++) {
    if(v[ii]<0) v[ii] = 0;
    else
      v[ii] = (v[ii] - min_v) / (max_v - min_v);
  }

  kmeans(DIM,
         v,
         n,
         2,
         c,
         r
         );
  printf("cluster result:");
  for (int ii = 0; ii < ELES; ii++)
    printf("%d\n", r[ii]);
  return 0;
}
