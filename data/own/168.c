// Snippet 8: K-means Clustering (Simplified version)
void kmeans_clustering() {
    int n = 10000, k = 10;  // Number of points and clusters
    double *data = (double*) malloc(n * sizeof(double));
    double *centroids = (double*) malloc(k * sizeof(double));
    int *labels = (int*) malloc(n * sizeof(int));

    // Initialize centroids randomly
    for (int i = 0; i < k; i++) {
        centroids[i] = rand() % 10000;
    }

    // K-means clustering (simplified)
    for (int i = 0; i < 100; i++) {  // Iterate for a number of steps
        // Assign points to nearest centroid
        for (int j = 0; j < n; j++) {
            double min_dist = 1000000;
            for (int l = 0; l < k; l++) {
                double dist = abs(data[j] - centroids[l]);
                if (dist < min_dist) {
                    min_dist = dist;
                    labels[j] = l;
                }
            }
        }
        // Recalculate centroids
        double *new_centroids = (double*) calloc(k, sizeof(double));
        int *count = (int*) calloc(k, sizeof(int));

        for (int j = 0; j < n; j++) {
            new_centroids[labels[j]] += data[j];
            count[labels[j]]++;
        }

        for (int l = 0; l < k; l++) {
            if (count[l] > 0) centroids[l] = new_centroids[l] / count[l];
        }

        free(new_centroids);
        free(count);
    }

    free(data);
    free(centroids);
    free(labels);
}