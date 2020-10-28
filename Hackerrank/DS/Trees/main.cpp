#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
// HashTable in C++
// unordered_map
#include <unordered_map>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Tree
{
  // height of tree = max(height of left subtree from root, height of right subtree from root)
  int treeHeight(Node *root)
  {
    if (root == NULL)
      return 0;
    int left = treeHeight(root->left);
    int right = treeHeight(root->right);
    if (right > left)
      return right + 1;
    return left + 1;
  }

public:
  Node *insert(Node *root, int data)
  {
    if (root == NULL)
    {
      return new Node(data);
    }
    else
    {
      Node *cur;
      if (data <= root->data)
      {
        cur = insert(root->left, data);
        root->left = cur;
      }
      else
      {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }

  void inOrder(Node *root)
  {
    if (root)
    {
      inOrder(root->left);
      cout << root->data << " ";
      inOrder(root->right);
    }
  }

  // Level Order
  // 1. NQ
  // while(!Q.isEmpty()):
  //       2. DQ and print
  //       3. NQ left and right child of the node DQed
  void levelOrder(Node *root)
  {
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
      Node *dq = Q.front();
      Q.pop();
      cout << dq->data << " ";
      if (dq->left)
      {
        Q.push(dq->left);
      }
      if (dq->right)
      {
        Q.push(dq->right);
      }
    }
    cout << endl;
  }

  // Vertical Order
  // 1. NQ root
  // 2. Update horizontal distance(Hd) field for root
  // 3. Add Hd = 0 in Hashtable and root as the value
  // LOOP: 4. DQ
  //       4.1. Check for left and right and update Hd in Hashtable
  //       4.2. NQ the left and right child
  unordered_map<int, vector<Node *>> verticalOrder(Node *root)
  {
    unordered_map<int, vector<Node *>> nodeDistMap;
    queue<pair<Node *, int>> Q;
    Q.push(make_pair(root, 0));
    nodeDistMap[0].push_back(root);
    while (!Q.empty())
    {

      Node *curr = Q.front().first;
      int Hd = Q.front().second;
      Q.pop();

      if (curr->left)
      {
        int lHd = Hd - 1;
        // Update in Hashtable
        nodeDistMap[lHd].push_back(curr->left);
        Q.push(make_pair(curr->left, lHd));
      }
      if (curr->right)
      {
        int rHd = Hd + 1;
        // Update in Hashtable
        nodeDistMap[rHd].push_back(curr->right);
        Q.push(make_pair(curr->right, rHd));
      }
    }

    // Print Hashtable
    for (auto node : nodeDistMap)
    {
      cout << node.first << " -> ";
      for (auto i : node.second)
      {
        cout << i->data << " ";
      }
      cout << endl;
    }
    return nodeDistMap;
  }

  // Top View (levelOrder + verticalOrder):
  // 1. Find levelOrder
  // 2. Find vertical Order
  // 3. For each Hd, pick the node which appeares first in the level Order
  void topView(Node *root)
  {
    unordered_map<int, vector<Node *>> nodeDistMap = verticalOrder(root);
    vector<int> keys;

    for (auto kv : nodeDistMap)
    {
      cout << kv.first << " ";
      keys.push_back(kv.first);
    }
    cout << endl;
    for (auto k : keys)
      cout << k << " ";

    cout << endl;

    sort(keys.begin(), keys.end());
    for (auto k : keys)
      cout << k << " ";
    cout << endl;
    for (auto i : keys)
    {
      cout << nodeDistMap.at(i)[0]->data << " ";
    }
  }

  // Height
  int height(Node *root)
  {
    return treeHeight(root) - 1;
  }

  // LCA (Lowest Common Ancestor) of two given nodes
  // 1. search for each nodes
  // 2. if node found, return node else return NULL
  // 3. If any node recieves node from both sides (left and right) that node is the  LCA of the given pair of nodes
  Node *LCA(Node *root, Node *n1, Node *n2)
  {
    if (root)
    {

      if (root == n1 || root == n2)
      {
        cout << root->data << endl;
        return root;
      }
      Node *left, *right;
      left = LCA(root->left, n1, n2);
      right = LCA(root->right, n1, n2);
      if (left != NULL && right != NULL)
      {
        cout << root->data << endl;
        return root;
      }
      else
        return left ? left : right;
    }
    return NULL;
  }
  Node *findN(Node *root, int data)
  {
    Node *node = root;
    while (node)
    {
      if (node->data < data)
      {
        node = node->right;
      }
      else if (node->data > data)
      {
        node = node->left;
      }
      else if (node->data == data)
      {
        return node;
      }
    }
    return NULL;
  }
}

;

// Huffman Coding:
class HuffNode
{
public:
  int freq;
  char sym;
  string code;
  HuffNode *left;
  HuffNode *right;

  HuffNode(int f, char s = '\0')
  {
    freq = f;
    sym = s;
    code = "";
    left = right = NULL;
  }
};

bool HuffSorter(HuffNode *lhn, HuffNode *rhn)
{
  return lhn->freq < rhn->freq;
}

class HuffTree
{
public:
  void encodeTree(HuffNode *root, string code)
  {
    if (root)
    {
      root->code += code;
      if (root->left)
      {
        encodeTree(root->left, root->code + "0");
      }
      if (root->right)
      {
        encodeTree(root->right, root->code + "1");
      }
    }
  }
  unordered_map<char, string> huffCodes(HuffNode *root)
  {
    static unordered_map<char, string> hfcode;
    if (root)
    {
      if (root->sym != '\0')
      {
        hfcode[root->sym] = root->code;
      }
      huffCodes(root->left);
      huffCodes(root->right);
    }
    return hfcode;
  }
  void inOrder(HuffNode *root)
  {
    if (root)
    {
      inOrder(root->left);
      cout << root->freq << " ";
      inOrder(root->right);
    }
  }
  HuffNode *constructHuffTree(string stmt)
  {
    vector<HuffNode *> chList = createChList(stmt);
    while (chList.size() > 1)
    {
      sort(chList.begin(), chList.end(), &HuffSorter);
      HuffNode *least = chList[0];
      HuffNode *sleast = chList[1];
      chList.erase(chList.begin());
      chList.erase(chList.begin());
      HuffNode *newNode = new HuffNode(least->freq + sleast->freq);
      newNode->left = least;
      newNode->right = sleast;
      vector<HuffNode *>::iterator it = chList.insert(chList.begin(), newNode);
    }
    HuffNode *root = chList.front();
    chList.erase(chList.begin());
    return root;
  }

  vector<HuffNode *> createChList(string stmt)
  {
    vector<HuffNode *> chList;
    unordered_map<char, int> charCountMap;
    for (char ch : stmt)
    {
      charCountMap[ch]++;
    }
    for (auto m : charCountMap)
    {
      chList.push_back(new HuffNode(m.second, m.first));
    }
    // for (auto node : chList)
    // {
    //   cout << "(" << node->freq << " " << node->sym << ")" << endl;
    // }
    return chList;
  }

  string decoded(string encoded, HuffNode *root)
  {
    string decodedStr = "";
    HuffNode *node = root;
    for (char code : encoded)
    {
      if (code == '0')
      {
        node = node->left;
        if (node->sym != '\0')
        {
          decodedStr += node->sym;
          node = root;
        }
      }
      else if (code == '1')
      {
        node = node->right;
        if (node->sym != '\0')
        {
          decodedStr += node->sym;
          node = root;
        }
      }
    }
    return decodedStr;
  }
};

int main()
{
  Tree myTree;
  Node *root = NULL;

  int t;
  int data;
  cin >> t;

  // Insert
  while (t-- > 0)
  {
    std::cin >> data;
    root = myTree.insert(root, data);
  }
  // LCA
  Node *n1 = myTree.findN(root, 7);
  Node *n2 = myTree.findN(root, 1);
  cout << n1->data << " " << n2->data << endl;

  Node *lca = myTree.LCA(root, n1, n2);
  cout << lca->data << " " << endl;

  // Inorder
  myTree.inOrder(root);
  cout << endl;

  // Height
  // cout << myTree.height(root);
  // cout << endl;

  // LevelOrder
  // myTree.levelOrder(root);

  // Vertical Order
  // myTree.verticalOrder(root);

  // Top View
  // myTree.topView(root);

  // // Huffman Encoding
  // HuffTree hftree;
  // HuffNode *Huffroot = hftree.constructHuffTree("abbcdbcccdccaecfeccc");
  // cout << "Statement to be encoded : "
  //      << "abbcdbcccdccaecfeccc" << endl;
  // // hftree.inOrder(Huffroot);

  // // Encode Tree
  // hftree.encodeTree(Huffroot, "");
  // unordered_map<char, string> huffCodes = hftree.huffCodes(Huffroot);
  // cout << "Huffman Codes" << endl;
  // for (auto kv : huffCodes)
  //   cout << kv.first << " : " << kv.second << endl;

  // // Huffman Decoding
  // string encoded = "001010110000010101";
  // cout << "Code to be decoded : " << encoded << endl;
  // string decoded = hftree.decoded(encoded, Huffroot);
  // cout << "After Decoding : " << decoded;
}