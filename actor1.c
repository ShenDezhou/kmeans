//2018.8.30
//将演员根据演片量二分类，根据min-max分成两部分
//cluster0:28490
//cluster1:876
//这说明大部分演员所演电影较少，参演电影较多的是制片人、导演
//看出除了个别演员参演较多电影外，数据中制片人、导演较多
//centroid0:0.0， centroid1:0.2
//高产电影人占整个从艺人数，占比为0.0298
//我们将高票房电影人220与高产电影人876求交，得到183个交集
//说明一个高产电影人中，高票房占比0.2089
//而高票房电影人，高产人占比0.8318
//说明高产人中有1/5概率可以取得高票
//高产人中，有4/5的概率不能成为高票
//而取得高票中，4/5以上的人是高产的
//一个高票，有不到1/5概率是通过偶然机会成为高票

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "kmeans.h"
#define DIM 1
#define ELES 29366
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
  double c[3] = {0.0l,1.0l};
  int r[ELES];
  fp = fopen("moviecount.dat","r");
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
