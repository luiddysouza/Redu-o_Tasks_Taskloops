#pragma omp taskloop grain_size(BLOCK_SIZE) collapse(3) shared(x, y, z)
for(i = 0; i < N; i++){
	for (j = 0; j < N; j++){
		for(k = 0; k < M; k++)
			z[i][j] += x[i][k] * y[k][j];
    }
}
