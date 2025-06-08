// Snippet 8: K-means Clustering (Simplified version)
#include <stdlib.h> // For malloc, free, calloc, rand, srand, abs
#include <math.h>   // For fabs
#include <float.h>  // For DBL_MAX
#include <time.h>   // For time

void kmeans_clustering(int n_points, int k_clusters, int max_iters) { // Renamed n, k, iters
    double *data = (double*) malloc(n_points * sizeof(double));
    double *centroids = (double*) malloc(k_clusters * sizeof(double));
    int *assignments = (int*) malloc(n_points * sizeof(int));

    srand(time(NULL));
    // Initialize data points (e.g., 1D data)
    for (int i = 0; i < n_points; i++) {
        data[i] = (double)(rand() % 10000) / 100.0; // Example data
    }

    // Initialize centroids (e.g., randomly pick k data points)
    for (int i = 0; i < k_clusters; i++) {
        centroids[i] = data[rand() % n_points];
    }

    for (int iter = 0; iter < max_iters; iter++) {
        // Assignment step
        for (int j = 0; j < n_points; j++) {
            double min_dist = DBL_MAX;
            assignments[j] = 0;
            for (int l = 0; l < k_clusters; l++) {
                double dist = fabs(data[j] - centroids[l]); // Use fabs for double
                if (dist < min_dist) {
                    min_dist = dist;
                    assignments[j] = l;
                }
            }
        }

        // Update step
        double *new_centroids = (double*) calloc(k_clusters, sizeof(double));
        int *counts = (int*) calloc(k_clusters, sizeof(int));

        for (int j = 0; j < n_points; j++) {
            new_centroids[assignments[j]] += data[j];
            counts[assignments[j]]++;
        }

        for (int l = 0; l < k_clusters; l++) {
            if (counts[l] > 0) {
                centroids[l] = new_centroids[l] / counts[l];
            }
            // Else: handle empty cluster (e.g., re-initialize centroid)
        }
        free(new_centroids);
        free(counts);
    }

    free(data);
    free(centroids);
    free(assignments);
}

int main() {
    // Example usage
    kmeans_clustering(1000, 5, 20); // 1000 points, 5 clusters, 20 iterations
    return 0;
}