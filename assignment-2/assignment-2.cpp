#include "Header.h"
#include "functions.h"

int main() {
	//creates a vector of integers
	vector<int> stack;
	//confirms that stack is empty
	what_is_in_the_stack(stack);
	//adds integers to the stack
	add_to_stack(stack);
	//confirms what integers have been added to the stack
	what_is_in_the_stack(stack);
	//removes an element from the stack
	if (!stack.empty()) {
		cout << "Removing the last element from the stack("<< stack.back()<<")\n";
		stack.pop_back(); // Remove the last element
		cout << "The last element has been removed from the stack.\n";
		//confirms what integers are left in the stack
		what_is_in_the_stack(stack);
	}
	else {
		cout << "The stack is already empty, nothing to remove.\n";
	}
	//Finds the top of the stack
	if (!stack.empty()) {
		cout << "The top of the stack is: " << stack.back() << "\n";
	}
	else {
		cout << "The stack is empty, no top element.\n";
	}
	//Finds the average value of the stack elements
	find_average(stack);
}