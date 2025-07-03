#include "Header.h"
#include "functions.h"


//confirms what's in the stack
void what_is_in_the_stack(const vector<int>& stack) {
    if (stack.empty()) {
        cout << "The stack is empty.\n";
    }
    else {
        cout << "The stack contains:\n";
        for (int value : stack) {
            cout << value << " ";
        }
        cout << endl;
    }
}
//function that takes in integer values from the useer and adds them to a vector stack
void add_to_stack(vector<int>& stack) {
    string line;
    cout << "Enter integers to add to the stack:\n";

    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line.empty()) break; // Stop on empty input

        stringstream ss(line);
        string token;
        while (ss >> token) {
            try {
                int value = stoi(token);   // Attempt to convert to int
                stack.push_back(value);    // Valid int, push to stack
            }
            catch (invalid_argument&) { // If conversion fails, catch the exception
                cout << "Warning: '" << token << "' is not a valid integer and was skipped.\n";
            }
        }
    }
}

	//finds the average of the integers in the stack
	void find_average(const vector<int>&stack) {
		if (stack.empty()) {
			cout << "The stack is empty, cannot calculate average.\n";
			return;
		}
		double sum = 0;
		for (int value : stack) {
			sum += value;
		}
		double average = sum / stack.size();
		cout << "The average of the stack elements is: " << average << "\n";
	}

