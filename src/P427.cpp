/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   14 November 2020 16:58
 * @brief  
 */
#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
      val = false;
      isLeaf = false;
      topLeft = NULL;
      topRight = NULL;
      bottomLeft = NULL;
      bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
      val = _val;
      isLeaf = _isLeaf;
      topLeft = NULL;
      topRight = NULL;
      bottomLeft = NULL;
      bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
      val = _val;
      isLeaf = _isLeaf;
      topLeft = _topLeft;
      topRight = _topRight;
      bottomLeft = _bottomLeft;
      bottomRight = _bottomRight;
  }
};

class Solution {
 public:
  Node *construct(vector<vector<int>> &grid) {
      return _construct(grid, 0, 0, grid[0].size());
  }
  Node *_construct(vector<vector<int>> &grid, int row, int col, int stride) {
      auto node = new Node(grid[row][col], false);
      if (1 == stride) {
          node->isLeaf = true;
          return node;
      }
      int stride2 = stride / 2;
      auto tl = _construct(grid, row, col, stride2);
      auto tr = _construct(grid, row, col + stride2, stride2);
      auto bl = _construct(grid, row + stride2, col, stride2);
      auto br = _construct(grid, row + stride2, col + stride2, stride2);

      if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf
          && tl->val == tr->val
          && tl->val == bl->val
          && tl->val == br->val) {
          node->isLeaf = true;
      } else {
          node->isLeaf = false;
          node->topLeft = tl;
          node->topRight = tr;
          node->bottomLeft = bl;
          node->bottomRight = br;
      }
      return node;
  }
};
int main() {
    return 0;
}