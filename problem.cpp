#include "problem.h"
#include <iostream>
using namespace std;

/*
See README.md for a full problem statement, sample input and output, and hints.

For your reference, the definition of node is pasted from problem.h below:

struct Node {
  Node(int value_in) : value{value_in}, left{nullptr}, right{nullptr} {}

  int value;
  Node* left;
  Node* right;
};

*/

/*
  REQUIRES: nothing. root may be null
  MODIFIES: nothing
  EFFECTS: see the problem statement. this is the function you are implementing
  to return the sum of nodes with even-valued grandparents.
*/
int sumOfEvenGrandparents(Node *root) {
  // TODO: COMPLETE YOUR IMPLEMENTATION
  // Feel free to add helper functions as needed. Do not alter the definition of
  // Node.

  return 0; // this line is included in the starter code for compilation
            // purposes. feel free to remove it!
}

// Driver code to test your solution
int main() {
  // Create and print the tree from the sample input
  vector<int> data = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6};
  Node *root = constructBinaryTreeFromLevelOrder(data, root, 0);
  print_diagram(root);

  cout << "Your answer: " << sumOfEvenGrandparents(root) << '\n';
  cout << "Correct answer: 18\n";
}
