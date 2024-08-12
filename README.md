# Machine Learning Algorithms in C
## This repository contains my implementations of simple machine learning algorithms in C.

### Files Overview
[**linear regression**](linear-regression.c)  
Algorithm: Linear Regression with gradient descent  
Details: No use of Mean Squared Error (MSE)  
Type: Supervised Learning  
  
[**logistic regression**](logistic-regression.c)  
Algorithm: Logistic Regression  
Details: Gradient descent for optimization, no use of MSE  
Type: Supervised Learning  
  
[**k-nearest neighbor**](knearestneighb.c)  
Algorithm: k-Nearest Neighbors (k-NN)  
Details: Classifies based on nearest neighbors  
Type: Unsupervised Learning  

### compiling
To compile, just dont forget to use the -lm flag to link with the math library
`gcc knn.c -o knn -lm`
