#include <stdio.h>
#include <math.h>
#include <float.h>

#define NUM_NEIGHBORS 3
#define NUM_FEATURES 2
#define NUM_TRAINING_SAMPLES 5

typedef struct {
    double features[NUM_FEATURES];
    int label;
} DataPoint;

double euclidean_distance(double point1[], double point2[], int num_features) {
    double distance = 0.0;
    for (int i = 0; i < num_features; i++) {
        distance += pow(point1[i] - point2[i], 2);
    }
    return sqrt(distance);
}

int classify(DataPoint training_data[], int num_training_samples, double test_point[], int k) {
    double distances[NUM_TRAINING_SAMPLES];
    int labels[NUM_TRAINING_SAMPLES];
    
    for (int i = 0; i < num_training_samples; i++) {
        distances[i] = euclidean_distance(test_point, training_data[i].features, NUM_FEATURES);
        labels[i] = training_data[i].label;
    }

    for (int i = 0; i < num_training_samples - 1; i++) {
        for (int j = i + 1; j < num_training_samples; j++) {
            if (distances[i] > distances[j]) {
                double temp_distance = distances[i];
                distances[i] = distances[j];
                distances[j] = temp_distance;

                int temp_label = labels[i];
                labels[i] = labels[j];
                labels[j] = temp_label;
            }
        }
    }

    int count[2] = {0, 0}; 
    for (int i = 0; i < k; i++) {
        count[labels[i]]++;
    }

    return count[0] > count[1] ? 0 : 1;
}

int main() {
    DataPoint training_data[NUM_TRAINING_SAMPLES] = {
        {{1.0, 1.0}, 0},
        {{2.0, 2.0}, 0},
        {{3.0, 3.0}, 0},
        {{6.0, 6.0}, 1},
        {{7.0, 7.0}, 1}
    };

    double test_point[NUM_FEATURES] = {6.0, 6.0};

    int predicted_label = classify(training_data, NUM_TRAINING_SAMPLES, test_point, NUM_NEIGHBORS);

    printf("Predicted label: %d\n", predicted_label);

    return 0;
}
