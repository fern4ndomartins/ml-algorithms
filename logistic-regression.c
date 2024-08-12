#include <stdio.h>
#include <math.h>

double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

double predict(double x[], double theta[], int n) {
    double z = 0.0;
    for (int i = 0; i < n; i++) {
        z += x[i] * theta[i];
    }
    return sigmoid(z);
}
void train(double X[][2], double y[], double theta[], int m, int n, double alpha, int iterations) {
    for (int iter = 0; iter < iterations; iter++) {
        double gradient[n];
        for (int j = 0; j < n; j++) {
            gradient[j] = 0.0;
            for (int i = 0; i < m; i++) {
                double prediction = predict(X[i], theta, n);
                gradient[j] += (prediction - y[i]) * X[i][j];
            }
            gradient[j] /= m;
        }
        for (int j = 0; j < n; j++) {
            theta[j] -= alpha * gradient[j];
        }
    }
}

int main() {
    double X[4][2] = {
        {1.0, 0.0},
        {1.0, 1.0},
        {1.0, 2.0},
        {1.0, 3.0}
    };
    double y[4] = {0, 0, 1, 1}; 

    int m = 4; 
    int n = 2; 

    double theta[2] = {0.0, 0.0}; 

    double alpha = 0.1; 
    int iterations = 1000; 
    train(X, y, theta, m, n, alpha, iterations);

    
    printf("Learned parameters: \n");
    for (int i = 0; i < n; i++) {
        printf("theta[%d] = %f\n", i, theta[i]);
    }

    
    double test[2] = {1.0, 1.5}; 
    double prob = predict(test, theta, n);
    printf("Predicted probability for x1 = 1.5: %f\n", prob);

    return 0;
}
