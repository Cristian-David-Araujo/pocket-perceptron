#ifndef POCKET_PERCEPTRON_H
#define POCKET_PERCEPTRON_H

#include <vector>
#include <iostream>
#include <cstdlib> // for rand() and RAND_MAX
#include "matrix.h"

using namespace std;

/**
 * @brief Implementation of the Pocket Perceptron algorithm.
 * 
 */
class PocketPerceptron {

public:

    /**
     * @brief Construct a new Pocket Perceptron object
     * 
     * @param learning_rate The learning rate of the algorithm (recommended range: 0 < learning_rate <= 1).
     */
    PocketPerceptron(double learning_rate);

    /**
     * @brief Trains the perceptron until the specified accuracy is reached or until max_epochs is exceeded.
     * 
     * @param inputs The input data, each row is a sample with size equal to features.
     * @param outputs The output data, a vector of size equal to samples, containing labels for each sample.
     * @param expected_accuracy The expected accuracy of the algorithm.
     * @param max_epochs The maximum number of epochs.
     * @param verbose Whether to print the accuracy of each epoch.
     * 
     */
    void train(vector<vector<double>>& inputs, vector<int>& outputs, double expected_accuracy, int max_epochs, bool verbose);

    /**
     * @brief Predicts the output of the perceptron using the step activation function
     * 
     * @param x The input data, should have the same number of elements as features.
     * @return int The predicted output (typically 0 or 1 for binary classification).
     */
    int predict(vector<double>& x);

    
private:

    /**
     * @brief Updates the weights and bias of the perceptron based on the input and target output.
     * 
     * @param input input data.
     * @param target target output.
     */
    void update_weights(vector<double>& input, int target);

    int features; ///< Number of features, columns of the input data.
    int samples; ///< Number of samples, rows of the input data.
    double learning_rate; ///< Learning rate.
    vector<double> weights; ///< Weights of the perceptron.
    vector<double> best_weights; ///< Best weights found.
    double bias; ///< Bias of the perceptron.
    double best_bias; ///< Best bias found.
    double best_accuracy; ///< Best accuracy found.
};

#endif // POCKET_PERCEPTRON_H