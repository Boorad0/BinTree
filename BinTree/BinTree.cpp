#include <string>
#include <iostream>


using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* back;

    Node(int data1) {
        data = data1;
        left = NULL;
        right = NULL;
        back = NULL;

    }
};
class BinTree {
public:
    Node* root;
    BinTree() {
        this->root = NULL;
    }
    void printTree(Node* root, int level) {
        if (root != NULL) {
            printTree(root->right, level + 1);
            for (int i = 0; i < level; i++) {
                cout << "    ";
            }
            cout << root->data << endl;
            printTree(root->left, level + 1);
        }
    }

    void startAdd() {
        if (root == NULL) {


            cout << "Введите элемент в начало дерева: " << endl;
            string temp;
            int elem;
            cin >> temp;
            try {
                elem = stoi(temp);
            }
            catch (const invalid_argument& e) {
                cout << "Молодец, держи дерево " << endl;
                return;
            }
            Node* node = new Node(elem);
            root = node;
        }
        else {

            string temp;
            int elem;
            cin >> temp;
            try {
                elem = stoi(temp);
            }
            catch (const invalid_argument& e) {
                cout << "Молодец, держи дерево " << endl;
                printTree(root, 5);
                exit(0);
            }

            Node* current = root;

            while (true)
            {
                if ((current->left == NULL) && (current->data > elem)) {
                    current->left = new Node(elem);
                    break;

                }
                else if ((current->right == NULL) && (current->data <= elem)) {
                    current->right = new Node(elem);
                    break;
                }
                else {
                    if (current->data <= elem)
                    {
                        //cout << "Здесь находится элемент " << current->right->data << endl;
                        current = current->right;
                    }
                    else if (current->data > elem) {
                        //cout << "Здесь находится элемент " << current->left->data << endl;
                        current = current->left;
                    }
                }
            }
        }

    }

};
int main()
{

    BinTree tree;
    setlocale(LC_ALL, "ru");
    cout << "Бинарное дерево~ " << endl;
    cout << "Вводите цифры для дерева. Чтобы завершить программу и вывести дерево введите любое слово" << endl;
    while (true) {
        tree.startAdd();
    }







    cout << endl;


}
