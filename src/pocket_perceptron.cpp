#include "pocket_perceptron.h"

using namespace std;

PocketPerceptron::PocketPerceptron(double learning_rate)
{
    // Initialize the perceptron.
    this->learning_rate = learning_rate;  
}

void PocketPerceptron::train(vector<vector<double>>& inputs, vector<int>& outputs, double expected_accuracy, int max_epochs, bool verbose)
{
    if (inputs.empty() || inputs[0].size() == 0) {
        cout << "Error: Input data is empty." << endl;
        return;
    }

    if (outputs.size() != inputs.size()) {
        cout << "Error: Mismatch between number of samples and output size." << endl;
        return;
    }
    

    // Initialize the perceptron.
    features = inputs[0].size();
    samples = inputs.size();
    weights = vector<double>(features, 0);
    best_weights = vector<double>(features, 0);
    bias = (double(rand()) / RAND_MAX) * 0.01; // Small random bias for better convergence
    best_bias = 0;
    best_accuracy = 0;
    
    // Fill out the weights and bias with random values.
    for (int i = 0; i < features; i++)
    {
        weights[i] = (double(rand()) / RAND_MAX) * 0.01; // Small values for better convergence
    }

    // Copy data to best_weights and best_bias
    best_weights = weights;
    best_bias = bias;


  
    // Train the perceptron.
    double actual_accuracy = 0;
    int epoch = 0;

    while ((actual_accuracy < expected_accuracy) && (epoch < max_epochs))
    {
        // Train the perceptron for each sample.
        for (int i = 0; i < samples; i++)
        {
            update_weights(inputs[i], outputs[i]);
        }

        // Calculate the prediction
        vector<int> predictions(samples);
        for (int i = 0; i < samples; i++)
        {
            predictions[i] = predict(inputs[i]);
        }

        // Calculate the actual accuracy
        int correct_predictions = 0;
        for (int i = 0; i < samples; i++)
        {
            if (predictions[i] == outputs[i])
            {
                correct_predictions++;
            }
        }
        actual_accuracy = static_cast<double>(correct_predictions) / samples;

        // Update the best weights and bias if the accuracy is better.
        if (actual_accuracy > best_accuracy)
        {
            best_accuracy = actual_accuracy;
            best_weights = weights;
            best_bias = bias;
        }

        // Print the accuracy of the epoch if verbose is true.
        if (verbose)
        {
            cout << "Epoch: " << epoch << " Accuracy: " << actual_accuracy << endl;
        }

        epoch++;
        
    }

    // Print the results of the training.
    if (actual_accuracy >= expected_accuracy)
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "Training finished successfully." << endl;
        cout << "Accuracy: " << actual_accuracy << endl;
        cout << "Weights: ";
        for (int i = 0; i < features; i++)
        {
            cout << weights[i] << " ";
        }
        cout << endl;
        cout << "Bias: " << bias << endl;
        cout << "Epochs: " << epoch << endl;
        cout << "-----------------------------------------------------------" << endl;

    }

    else
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "Training finished unsuccessfully." << endl;
        cout << "Best Accuracy: " << best_accuracy << endl;
        cout << "Best Weights: ";
        for (int i = 0; i < features; i++)
        {
            cout << best_weights[i] << " ";
        }
        cout << endl;
        cout << "Best Bias: " << best_bias << endl;
        cout << "Max Epochs: " << epoch << endl;
        cout << "Perceptron training partially successful!" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
    

}

int PocketPerceptron::predict(vector<double> &x)
{
    // Calculate the dot product of the input and the weights.
    double result = Matrix::dot(x, weights) + bias;

    // Predict output of perceptron using step activation function sigmoid.
    return result >= 0 ? 1 : 0;
}

void PocketPerceptron::update_weights(vector<double> &input, int target)
{
    // Update the weights and bias of the perceptron.
    int prediction = predict(input);
    double error = target - prediction;
    if (error != 0)
    {
        for (int i = 0; i < features; i++)
        {
            weights[i] += learning_rate * error * input[i];
        }
        bias += learning_rate * error;
    }
}
