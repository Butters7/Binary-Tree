#pragma once

#include <iostream>
#include <string>
#include <fstream>

namespace BMSTU {
    template<typename K, typename V>
    class BinaryTree {
    public:
        BinaryTree() : root_(nullptr), size_(0) {}

        BinaryTree(K key, V value) {
            root_ = new TreeNode(key, value);
            root_->height = 0;
            size_ = 1;
        }

        ~BinaryTree() {
            DeleteTree(root_);
        }

        void Print();
        void Insert(K key, V value);
        void Remove(K key);
        bool Contains(K key);
        size_t Size() const;
        size_t Height(K key) const;
        size_t MaxHeight() const;
        void inorderTraversal();
        void preorderTraversal();
        void postorderTraversal();
        void Draw(std::string name);

    private:

        struct TreeNode {

            TreeNode(K key, V value) : key(key), value(value), height(0), left(nullptr), right(nullptr) {

            };
            K key;
            V value;
            uint8_t height;
            TreeNode *left;
            TreeNode *right;
        };
        //Update
        void RotateWithLeftChild(TreeNode *track);
        void RotateWithRightChild(TreeNode *track);
        void RotateDoubleWithRightChild(TreeNode *track);
        void RotateDoubleWithLeftChild(TreeNode *track);
        uint8_t HeightOfTree(TreeNode *track);
        void ReBalance(TreeNode* track);
        void Balance(TreeNode *track);
        void DeleteTree(TreeNode *track);
        void PrintTree(TreeNode *track);
        void HeightReplace(TreeNode *track);
        void inorderTraversal(TreeNode *track);
        void preorderTraversal(TreeNode *track);
        void postorderTraversal(TreeNode *track);
        void GraphvizOutput(std::string str);
        void GraphvizOutput(TreeNode* node, std::ofstream &file);

        size_t size_;
        TreeNode *root_;
    };
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K, V>::Print() {
        PrintTree(root_);
        std::cout << std::endl;
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K, V>::Insert(K key, V value) {
        if (size_ == 0) {
            root_ = new TreeNode(key, value);
            root_->height = 0;
            size_ = 1;
        } else {
            TreeNode *track = root_;
            while (track && track->key != key) {
                if(track->left == nullptr && track->right == nullptr) {
                    if(key > track->key) {
                        TreeNode *replacement = new TreeNode(track->key, track->value);
                        track->key = key;
                        track->value = value;
                        track->left = replacement;
                        HeightReplace(root_);
                        ReBalance(root_);
                        ++size_;
                        return;
                    }
                    else if (key < track->key) {
                        track->left = new TreeNode(key, value);
                        HeightReplace(root_);
                        ReBalance(root_);
                        ++size_;
                        return;
                    }
                }
                else if (key < track->key && track->left == nullptr) {
                    track->left = new TreeNode(key, value);
                    HeightReplace(root_);
                    ReBalance(root_);
                    ++size_;
                    return;
                }
                else if (key > track->key && track->right == nullptr) {
                    track->right = new TreeNode(key, value);
                    HeightReplace(root_);
                    ReBalance(root_);
                    ++size_;
                    return;
                }
                if (key < track->key) {
                    track = track->left;
                } else {
                    track = track->right;
                }
            }
        }
    }
    ////////////////////////////////
    template<typename K, typename V>
    uint8_t BinaryTree<K,V>::HeightOfTree(TreeNode* track) {
        if(track) {
            return track->height + 1;
        }
        else {
            return 0;
        }
    }
    ////////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::ReBalance(TreeNode *track) {
        if(track) {
            ReBalance(track->left);
            ReBalance(track->right);
            Balance(track);
        }
    }
    ////////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K, V>::Remove(K key) {
        if (size_ == 1) {
            delete root_;
            size_ = 0;
            root_ = nullptr;
            return;
        } else {
            TreeNode *track = root_;
            TreeNode *parent = nullptr;

            while (track && track->key != key) {
                parent = track;
                if (key < track->key)
                    track = track->left;
                if (key > track->key)
                    track = track->right;
            }
            if (track->left == nullptr) {
                if (parent->left == track) {
                    parent->left = track->right;
                }
                if (parent->right == track) {
                    parent->right = track->right;
                }
                HeightReplace(root_);
                --size_;
                delete track;
                ReBalance(root_);
                return;
            }
            if (track->right == nullptr) {
                if (parent->left == track) {
                    parent->left = track->left;
                }
                if (parent->right == track) {
                    parent->right = track->left;
                }
                HeightReplace(root_);
                --size_;
                delete track;
                ReBalance(root_);
                return;
            }
            TreeNode *replacement = track->right;
            while (replacement->left != nullptr)
                replacement = replacement->left;
            K replace_value = replacement->key;
            Remove(replace_value);
            track->key = replace_value;
            HeightReplace(root_);
        }
    }
    ////////////////////////////////
    template<typename K, typename V>
    bool BinaryTree<K, V>::Contains(K key) {
        TreeNode *track = root_;
        while (track && track->key != key) {
            if (key < track->key)
                track = track->left;
            else
                track = track->right;
        }
        return track != nullptr;
    }
    ///////////////////////////////
    template<typename K, typename V>
    size_t BinaryTree<K, V>::Size() const {
        return size_;
    }
    ///////////////////////////////
    template<typename K, typename V>
    size_t BinaryTree<K, V>::Height(K key) const {
        TreeNode *track = root_;
        while (track && track->key != key) {
            if (key < track->key)
                track = track->left;
            else
                track = track->right;
        }
        if (track && track->key == key) {
            return track->height;
        } else {
            return -1;
        }
    }
    template<typename K, typename V>
    size_t BinaryTree<K, V>::MaxHeight() const {
        return root_->height;
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::inorderTraversal() {
        inorderTraversal(root_);
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::preorderTraversal() {
        preorderTraversal(root_);
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::postorderTraversal() {
        postorderTraversal(root_);
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::RotateWithLeftChild(TreeNode *track)  {
        if(track == root_) {
            TreeNode *left_track = track->left;
            track->left = left_track->right;
            left_track->right = track;
            track = left_track;
            root_ = track;
            HeightReplace(root_);
        }
        else {
            TreeNode *replacement = new TreeNode(track->key, track->value);
            TreeNode *rep = track->right;
            track->key = track->left->key;
            track->value = track->left->value;
            track->right = replacement;
            replacement->left = track->left->right;
            replacement->right = rep;
            replacement = track->left->left;
            delete track->left;
            track->left = replacement;
            HeightReplace(root_);
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::RotateWithRightChild(TreeNode *track) {
        if(track == root_) {
            TreeNode *right_track = track->right;
            track->right = right_track->left;
            right_track->left = track;
            track = right_track;
            root_ = track;
            HeightReplace(root_);
        }
        else {
            TreeNode *replacement = new TreeNode(track->key, track->value);
            TreeNode *rep = track->left;
            track->key = track->right->key;
            track->value = track->right->value;
            track->left = replacement;
            replacement->right = track->right->left;
            replacement->left = rep;
            replacement = track->right->right;
            delete track->right;
            track->right = replacement;
            HeightReplace(track);
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::RotateDoubleWithLeftChild(TreeNode *track) {
        RotateWithRightChild(track->left);
        RotateWithLeftChild(track);
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::RotateDoubleWithRightChild(TreeNode *track) {
        RotateWithLeftChild(track->right);
        RotateWithRightChild(track);
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::Balance(TreeNode *track) {
        if(!track) {
            return;
        }
        else {
            if (HeightOfTree(track->left) - HeightOfTree(track->right) > 1) {
                if (HeightOfTree(track->left->left) >= HeightOfTree(track->left->right)) {
                    RotateWithLeftChild(track);
                } else {
                    RotateDoubleWithLeftChild(track);
                }
            } else if (HeightOfTree(track->right) - HeightOfTree(track->left ) > 1) {
                if (HeightOfTree(track->right->right) >= HeightOfTree(track->right->left)) {
                    this->RotateWithRightChild(track);
                } else {
                    this->RotateDoubleWithRightChild(track);
                }
            }
            HeightReplace(track);
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K, V>::PrintTree(TreeNode *track) {
        if (track) {
            PrintTree(track->left);
            std::cout << track->key << ' ';
            PrintTree(track->right);
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K, V>::DeleteTree(TreeNode *track) {
        if (track) {
            DeleteTree(track->left);
            DeleteTree(track->right);
            delete track;
        }
    }
    ////////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K, V>::HeightReplace(TreeNode *track) {
        if (track) {
            HeightReplace(track->left);
            HeightReplace(track->right);
            if(!track->left && !track->right) {
                track->height = 0;
            }
            else {
                if(track->left && track->right)
                    (track->right->height > track->left->height) ? track->height = track->right->height + 1 : track->height = track->left->height + 1;
                else if(track->left)
                    track->height = track->left->height + 1;
                else if(track->right)
                    track->height = track->right->height + 1;
            }
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::inorderTraversal(TreeNode *track) {
        if (track) {
            PrintTree(track->left);
            std::cout << track->key << ' ';
            PrintTree(track->right);
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::preorderTraversal(TreeNode *track) {
        if (track) {
            std::cout << track->key << ' ';
            PrintTree(track->left);
            PrintTree(track->right);
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::postorderTraversal(TreeNode *track) {
        if (track) {
            PrintTree(track->left);
            PrintTree(track->right);
            std::cout << track->key << ' ';
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::Draw(std::string str) {
        if(root_ != nullptr) {
            GraphvizOutput(str);
            std::string cmd = "dot -Tsvg " + str + "_output.txt > Visualisation_" + str + ".svg";
            std::cout << system(cmd.c_str());
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::GraphvizOutput(std::string str) {
        if (root_ != nullptr) {
            std::string file_name = str + "_output.txt";
            std::ofstream file(file_name);
            file << "digraph {" << std::endl;
            GraphvizOutput(root_, file);
            file << "}";
        }
    }
    ///////////////////////////////
    template<typename K, typename V>
    void BinaryTree<K,V>::GraphvizOutput(TreeNode *track, std::ofstream &file) {
        if(track->left != nullptr){
            file << '\t' << track->key << " -> " << track->left->key << std::endl;
            GraphvizOutput(track->left, file);
        }
        if(track->right != nullptr) {
            file << '\t' << track->key << " -> " << track->right->key << std::endl;
            GraphvizOutput(track->right, file);
        }
    }
}