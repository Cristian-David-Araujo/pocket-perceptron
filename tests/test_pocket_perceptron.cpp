#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "pocket_perceptron.h"
#include "matrix.h"

using namespace std;

/**
 * @brief Reads data from a CSV file and returns inputs and outputs.
 * 
 * @param filename The name of the CSV file.
 * @param inputs The output vector for input features.
 * @param outputs The output vector for labels.
 * @return true if data was read successfully, false otherwise.
 */
bool read_csv(const string& filename, vector<vector<double>>& inputs, vector<int>& outputs) {

    ifstream file(filename);
    string line;

    // Check if file is open
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }

    // Skip header
    getline(file, line);

    while (getline(file, line)) {
        // cout << line << endl;
        stringstream ss(line);
        string value;

        vector<double> input_row;

        // Read feature values
        for (int i = 0; i < 2; ++i) { // Assuming 2 features
            getline(ss, value, ',');
            input_row.push_back(stod(value)); // Convert string to double
        }

        // Read label
        getline(ss, value, ',');
        int label = stoi(value); // Convert string to int

        // Add to the input and output vectors
        inputs.push_back(input_row);
        outputs.push_back(label);
    }

    file.close();
    return true;
}

int main() {
    // Read data from CSV
    vector<vector<double>> inputs;
    vector<int> outputs;

    // Inform about the expected path for the CSV file
    cout << "Expected path for the CSV file: ../tests/classification_data.csv" << endl;

    // Read the CSV file
    if (!read_csv("classification_data.csv", inputs, outputs)) {
        cout << "Error reading data!" << endl;
        return 1;
    }

    cout << "Data read successfully!" << endl;
    // Matrix::print(inputs);
    
    // Print the outputs
    // cout << "Outputs:" << endl;
    // cout << "Size: " << outputs.size() << endl;
    // for (size_t i = 0; i < outputs.size(); ++i) {
    //     cout << outputs[i] << endl;
    // }

    // Initialize the Pocket Perceptron
    double learning_rate = 0.01; // Set learning rate
    PocketPerceptron perceptron(learning_rate);

    // Train the perceptron
    double expected_accuracy = 0.98; // Desired accuracy
    int max_epochs = 1000; // Maximum number of epochs
    bool verbose = true; // Set verbosity for output

    // Only use the 70% of the data for training
    int training_size = 0.7 * inputs.size();
    vector<vector<double>> training_inputs(inputs.begin(), inputs.begin() + training_size);
    vector<int> training_outputs(outputs.begin(), outputs.begin() + training_size);

    // Train the perceptron
    perceptron.train(training_inputs, training_outputs, expected_accuracy, max_epochs, verbose);
    

    return 0;
}
