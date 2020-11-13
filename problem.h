#include <vector>
#include <iostream>
#include <algorithm>

// Definition of Node
struct Node {
  Node(int value_in) : value{value_in}, left{nullptr}, right{nullptr} {}

  int value;
  Node* left;
  Node* right;
};


// YOU DO NOT NEED TO UNDERSTAND ANYTHING BELOW THIS LINE TO COMPLETE YOUR IMPLEMENTATION!

// Source: EECS281 lab8 Starter Code
// note: this function is really complicated
// don't worry about how it works
// TODO: support 3+ digit numbers
void print_diagram(Node* root) {
    struct pos {
        int depth;
        int parent_dir;
    };
    std::vector<std::pair<int, pos>> points;
    std::function<void(Node*, pos p)> traverse_depth = [&](Node* n, pos p) {
        if (n == nullptr) {
            return;
        }
        traverse_depth(n->left, { p.depth + 1, 1 });
        points.push_back(std::pair<int, pos>({ n->value, p }));
        traverse_depth(n->right, { p.depth + 1, -1 });
    };
    traverse_depth(root, { 0, 0 });
    // points is now filled
    int width = 2 * (int)points.size();
    int height = 0;
    for (int i = 0; i < (int)points.size(); i++) {
        height = std::max(height, points[i].second.depth);
    }
    height *= 2;
    height++;
    // now, we can build the buffer:
    std::vector<std::vector<char>> buffer(width, std::vector<char>(height, ' '));
    // add the numbers
    for (int i = 0; i < (int)points.size(); i++) {
        int n = points[i].first;
        int d = points[i].second.depth;
        buffer[2 * i + 1][d * 2] = char((n % 10) + '0');
        if (n >= 10) {
            // note: will truncate 3+ digit numbers to their last 2 digits
            buffer[2 * i + 0][d * 2] = char((n / 10) % 10 + '0');
        }
    }
    // add the corner edges
    for (int i = 0; i < (int)points.size(); i++) {
        int d = points[i].second.depth;
        int dir = points[i].second.parent_dir;
        if (dir == 0) {
            continue; // root
        }
        if (points[i + dir].second.depth == d - 1) {
            // adjacent parent
            buffer[2 * i + (dir > 0 ? 2 : 0)][d * 2 - 1] = (dir > 0 ? '/' : '\\');
        }
        else {
            int c = 2 * i + (dir > 0 ? 2 : -1);
            buffer[c][d * 2 - 1] = (dir > 0 ? '/' : '\\');
            buffer[c + dir][d * 2 - 2] = '-';
            for (int j = i + 2 * dir; points[j].second.depth != d - 1; j += dir) {
                buffer[2 * j][d * 2 - 2] = '-';
                buffer[2 * j + 1][d * 2 - 2] = '-';
            }

        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << buffer[x][y];
        }
        std::cout << std::endl;
    }
}


Node* constructBinaryTreeFromLevelOrder(const std::vector<int>& data, Node* root, int i) {
  auto leftChild = [&](auto index) {
    return index*2 + 1;
  };

  auto rightChild = [&](auto index) {
    return index*2 + 2;
  };

  if(i < data.size()) {
    Node* temp = new Node(data[i]);
    root = temp;

    root->left =
        constructBinaryTreeFromLevelOrder(data, root->left, leftChild(i));
    root->right =
        constructBinaryTreeFromLevelOrder(data, root->right, rightChild(i));

  }

  return root;
}
