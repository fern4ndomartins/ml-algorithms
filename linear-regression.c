#include <stdio.h>

void gradient_descent(double *x, double *y, int m, double *theta_0, double *theta_1, double learning_rate, int num_iterations) {
    for (int i = 0; i < num_iterations; i++) {
        double sum_errors0 = 0;
        double sum_errors1 = 0;

        for (int j = 0; j < m; j++) {
            double prediction = (*theta_0) + (*theta_1)*x[j];
            double error = prediction - y[j];
            sum_errors0 += error;
            sum_errors1 += error*x[j];
        }

        *theta_0 -= learning_rate*sum_errors0*(2.0/ m);
        *theta_1 -= learning_rate*sum_errors1*(2.0/ m);
    }
}

int main() {
    double x[] = {};
    double y[] = {};
    int m = sizeof(x) / sizeof(x[0]);

    double theta_0 = 0;
    double theta_1 = 0;
    double learning_rate = 0.00000001;
    int num_iterations = 1000;

    gradient_descent(x, y, m, &theta_0, &theta_1, learning_rate, num_iterations);

    double area = 0;
    double prediction = theta_0 + theta_1*area;
    double correct_price = 1000.0;
    printf("predicted price: %f\ncorrect price: %f\n", prediction, correct_price);

}