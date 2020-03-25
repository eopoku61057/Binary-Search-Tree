#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

#define RIGHT 1
#define LEFT 0

#define max(x,y) x>y?x:y

using namespace std;

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    std::vector<T> *inorder_helper(Node<T> *n, T isFirst);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    std::vector<T> *postorder_helper(Node<T> *n, T isFirst);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    std::vector<T> *preorder_helper(Node<T> *n, T isFirst);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    Node<T> *get_root();
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
    int get_size1(Node<T> *n);
    Node<T> *root;
private:
    // the root node of the tree
    
    // the number of nodes in the tree
    int node_count;
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    Node<T> *n;
    T x = 1;

    // std::vector<T> *vec =new std::vector<T>;
    vector<T> *vec = inorder_helper(n, x);
    
    return vec;
}

template<class T>
 std::vector<T> * BST<T>::inorder_helper(Node<T> *n, T isFirst)
{
    // check if root is null the return
    if (root == NULL)
        return NULL;
    if (n == NULL)
    {
        if(isFirst == 1)
            n = root;
        else
            return NULL;
    }

    std::vector<T> *vec = new std::vector<T>;
    std::vector<T> *ret = new std::vector<T>;

    // recur to the left subtree
    ret = inorder_helper(n->get_left(), 0);

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());

    //THEN GET CURRENT
    vec->push_back(n->get_data());

    // then recur to the right subtree
    ret = inorder_helper(n->get_right(), 0);

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());
    
    return vec;
}

template<class T>
 std::vector<T> * BST<T>::preorder()
{
    Node<T> *n;
    T x = 1;

    std::vector<T> *vec =new std::vector<T>;
    vec = preorder_helper(n, x);
    
    return vec;
}

template<class T>
 std::vector<T> * BST<T>::preorder_helper(Node<T> *n, T isFirst)
{
    // check if root is null the return
    if (root == NULL)
        return NULL;
    if (n == NULL)
    {
        if(isFirst == 1)
            n = root;
        else
            return NULL;
    }

    std::vector<T> *vec = new std::vector<T>;
    std::vector<T> *ret = new std::vector<T>;

    // first print the data
    // cout <<  n->get_data() << " ";
    vec->push_back(n->get_data());

    // then recur to the left subtree
    ret = preorder_helper(n->get_left(), 0);

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());

    // then recur to the right subtree
    ret = preorder_helper(n->get_right(), 0);

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());
    
    return vec;
}

template<class T>
 std::vector<T> * BST<T>::postorder()
{
    Node<T> *n;
    T x = 1;

    std::vector<T> *vec =new std::vector<T>;
    vec = postorder_helper(n, x);
    
    return vec;
}

template<class T>
 std::vector<T> * BST<T>::postorder_helper(Node<T> *n, T isFirst)
{
    // check if root is null the return
    if (root == NULL)
        return NULL;
    if (n == NULL)
    {
        if(isFirst == 1)
            n = root;
        else
            return NULL;
    }

    std::vector<T> *vec = new std::vector<T>;
    std::vector<T> *ret = new std::vector<T>;

    // recur to the left subtree
    ret = postorder_helper(n->get_left(), 0);

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());

    // recur to the right subtree
    ret = postorder_helper(n->get_right(), 0);

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());

    // NOW THE POST ORDER
    vec->push_back(n->get_data());
    
    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
    Node<T> *data = new Node<T>;
    if(root == NULL)
    {
        root = new Node<T>;
        root->set_data(new_data);
    }

    else
    {
        Node<T>* runner = root;

        while(runner != NULL)
        {
            if(new_data > runner->get_data())
            {
                if(runner->get_right() == NULL)
                {
                    //auto n = new Node<T>;
                    data->set_data(new_data);
                    runner->set_right(data);
                    break;
                }
                else
                {
                    runner = runner->get_right();
                }
            }
            else
            {
                if(runner->get_left() == NULL)
                {
                    //auto n = new Node<T>;
                    data->set_data(new_data);
                    runner->set_left(data);
                    break;
                }
                else
                {
                    runner = runner->get_left();
                }
            }
        }
    }
}


template<class T>
Node<T> *BST<T>::search(T val)
{
    Node<T>* runner = root;

    while(runner != NULL)
    {
        T tmp = runner->get_data();
        if(tmp == val)
            return runner;
        else if(val > tmp)
            runner = runner->get_right();
        else
            runner = runner->get_left();
    }

    return NULL;
}

template<class T>
Node<T> *BST<T>::get_root()
{
    return root;
}



template<class T>
void BST<T>::remove(T val)
{
    //SO WE FIRST HAVE TO FIND THE NODE POINTER AND ALSO WE HAVE TO KEEP TRACK OF THE PARENT
    //IF IT HAS 2 CHILDREN, THEN ONE CHILD RIGHT, THEN ALL THE WAY LEFT TAKES ITS SPOT
    //IF IT HAS 1 CHILD, THEN THE CHILD TAKES ITS PLACE
    //IF IT HAS NO CHILDREN, THEN WE SET NULL

    //FIND THE NODE
    Node<T>* runner = root;
    Node<T>* parent = runner;
    T new_root = 0;

    while(runner != NULL)
    {
        T tmp = runner->get_data();
        if(tmp == val)
            break;

        //SET THE PARENT TO HOLD ON
        parent = runner;

        if(val > tmp)
            runner = runner->get_right();
        else
            runner = runner->get_left();
    }

    if(runner == NULL)
        return;

    if(runner == root)
        new_root = 1;

    //CHECK IF IT IS LEFT OR RIGHT OF THE PARENT (0 for left 1 for right)
    int dir = runner->get_data() > parent->get_data() ? RIGHT : LEFT;
    //IF THERE ARE NO CHILDREN
    if(runner->get_left() == NULL && runner->get_right() == NULL)
    {
        //IF THIS IS THE ROOT
        if(new_root)
            root = NULL;
        else
        {
            if(dir == RIGHT)
                parent->set_right(NULL);
            else if(dir == LEFT)
                parent->set_left(NULL);
        }

        delete(runner);
    }

    //IF THERE IS 1 RIGHT CHILD
    else if(runner->get_right() != NULL && runner->get_left() == NULL)
    {
        //IF WE DELETED THE ROOT
        if(new_root)
            root = runner->get_right();
        else
        {
            if(dir == RIGHT)
                parent->set_right(runner->get_right());
            else if(dir == LEFT)
                parent->set_left(runner->get_right());
         }

        delete(runner);
    }

    //IF THERE IS 1 LEFT CHILD
    else if(runner->get_left() != NULL && runner->get_right() == NULL)
    {
        //IF WE DELETED THE ROOT
        if(new_root)
            root = runner->get_left();
        else
        {
            if(dir == RIGHT)
                parent->set_right(runner->get_left());
            else if(dir == LEFT)
                parent->set_left(runner->get_left());
        }

        delete(runner);
    }

    //IF THERE ARE 2 CHILDREN
    else
    {
        //FIND THE SMALLEST VAL BIGGER THAN OUR RUNNER
        Node<T>* smallest_bigger_child = runner->get_right();
        int mov_val = -1;

        //CHECK IF JUST ONE DEEP
        if(smallest_bigger_child->get_left() == NULL)
        {
            mov_val = smallest_bigger_child->get_data();
            runner->set_data(mov_val);
            runner->set_right(smallest_bigger_child->get_right());

            delete(smallest_bigger_child);
        }
        //OTHERWISE WE CAN KEEP GOING LEFT
        else
        {
            //WALK TO THE BOTTOM
            while(smallest_bigger_child->get_left()->get_left() != NULL)
                smallest_bigger_child = smallest_bigger_child->get_left();

            //HOLD PARENT OF FINAL LEFTMOST NODE
            Node<T>* new_found_parent = smallest_bigger_child;
            smallest_bigger_child = new_found_parent->get_left();

            //FIX THE RIGHT NOW
            new_found_parent->set_left(smallest_bigger_child->get_right());

            //SET THE CORRECT VAL INTO THE RUNNER
            mov_val = smallest_bigger_child->get_data();
            runner->set_data(mov_val);
            delete(smallest_bigger_child);
        }
    }

    return;
}

template<class T>
int BST<T>::get_size()
{
    int size = get_size1(root);

    return size;
    
}

template<class T>
int BST<T>::get_size1(Node<T> *n)
{
    if(n == NULL) return 0;

    int m = max(get_size(n->get_left()), get_size(n->get_right()));

    return 1 + m;
}
