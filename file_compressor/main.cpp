#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, string str, unordered_map<char, string>& huffCode) {
    if (!root) return;
    if (!root->left && !root->right)
        huffCode[root->ch] = str;
    buildCodes(root->left, str + "0", huffCode);
    buildCodes(root->right, str + "1", huffCode);
}

void saveTree(Node* root, ofstream &out) {
    if (!root) return;
    if (!root->left && !root->right) {
        out << "1" << root->ch;
    } else {
        out << "0";
    }
    saveTree(root->left, out);
    saveTree(root->right, out);
}

Node* loadTree(ifstream &in) {
    char bit;
    in.get(bit);
    if (bit == '1') {
        char c;
        in.get(c);
        return new Node(c, 0);
    }
    Node* node = new Node('\0', 0);
    node->left = loadTree(in);
    node->right = loadTree(in);
    return node;
}

void compress(const string &inputFile, const string &outputFile) {
    ifstream in(inputFile, ios::binary);
    if (!in) {
        cout << "File not found.\n";
        return;
    }

    unordered_map<char, int> freq;
    char ch;
    while (in.get(ch)) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *node = new Node('\0', left->freq + right->freq);
        node->left = left;
        node->right = right;
        pq.push(node);
    }

    Node* root = pq.top();

    unordered_map<char, string> huffCode;
    buildCodes(root, "", huffCode);

    in.clear(); in.seekg(0);

    ofstream out(outputFile, ios::binary);
    saveTree(root, out);
    out << '|';

    string encodedStr = "";
    while (in.get(ch)) {
        encodedStr += huffCode[ch];
    }

    int padding = 8 - (encodedStr.size() % 8);
    if (padding != 8)
        encodedStr.append(padding, '0');

    bitset<8> bits;
    for (size_t i = 0; i < encodedStr.size(); i += 8) {
        bits = bitset<8>(encodedStr.substr(i, 8));
        out.put((char)bits.to_ulong());
    }
    out << (char)padding;

    in.close(); out.close();
    cout << "File compressed successfully.\n";
}

void decompress(const string &inputFile, const string &outputFile) {
    ifstream in(inputFile, ios::binary);
    if (!in) {
        cout << "Compressed file not found.\n";
        return;
    }

    Node* root = loadTree(in);
    char sep;
    in.get(sep); // skip '|'

    string encodedStr = "";
    char byte;
    in.seekg(-1, ios::end);
    int lastPos = in.tellg();
    in.seekg(lastPos);
    in.get(byte);
    int padding = (int)byte;

    in.seekg(0);
    string treeStr;
    getline(in, treeStr, '|'); // skip tree
    while (in.get(byte)) {
        if ((int)in.tellg() == lastPos + 2) break;
        bitset<8> bits((unsigned char)byte);
        encodedStr += bits.to_string();
    }

    encodedStr = encodedStr.substr(0, encodedStr.size() - padding);
    ofstream out(outputFile, ios::binary);

    Node* curr = root;
    for (char bit : encodedStr) {
        curr = (bit == '0') ? curr->left : curr->right;
        if (!curr->left && !curr->right) {
            out.put(curr->ch);
            curr = root;
        }
    }

    in.close(); out.close();
    cout << "File decompressed successfully.\n";
}

int main() {
    int choice;
    string input, output;
    cout << "🔧 Mini WinRAR - Huffman Compressor 🔧\n";
    cout << "1. Compress File\n2. Decompress File\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter input file path: ";
        cin >> input;
        cout << "Enter output compressed file name (.huf): ";
        cin >> output;
        compress(input, output);
    } else if (choice == 2) {
        cout << "Enter input compressed file (.huf): ";
        cin >> input;
        cout << "Enter output decompressed file name: ";
        cin >> output;
        decompress(input, output);
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
