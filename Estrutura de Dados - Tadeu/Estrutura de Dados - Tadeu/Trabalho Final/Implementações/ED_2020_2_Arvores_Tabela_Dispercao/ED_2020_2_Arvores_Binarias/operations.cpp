/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "operations.h"

TNODO * createNodo(INFO info) {
    TNODO * nodo = new TNODO;
    nodo->info = info;
    nodo->left = nodo->right = NULL;
    nodo->count = 1;
    nodo->bal = 0;
    return nodo;
}

Tree * getRightNode(Tree * tree) {
    return tree->right;
}

Tree * getLeftNode(Tree * tree) {
    return tree->left;
}

INFO getInfo(Tree * tree) {
    return tree->info;
}

void showTabs(int desloc) {
    for (; desloc >= 0; desloc--) {
        std::cout << "\t";
    }
}

void showNode(Tree * tree, int desloc) {
    int i = desloc;

    if (tree == NULL) {
        return;
    }

    std::cout << std::endl;
    showTabs(desloc);
    showNode(getRightNode(tree), desloc + 1);
    std::cout << std::endl;
    showTabs(desloc);
    std::cout << getInfo(tree);
    if ((tree)->count > 1) {
        std::cout << "(" << tree->count << ")";
    }
    std::cout << std::endl;
    showTabs(desloc);
    showNode(getLeftNode(tree), desloc + 1);
}

bool isEmpty(Tree ** tree) {
    return *tree == NULL ? true : false;
}

void addLeft(Tree ** tree, INFO info) {
    TNODO * aux = createNodo(info);

    if (isEmpty(tree)) {
        *tree = aux;
        return;
    }

    if ((*tree)->left == NULL) {
        (*tree)->left = aux;
    }

    return;
}

void addRight(Tree ** tree, INFO info) {
    TNODO * aux = createNodo(info);

    if (isEmpty(tree)) {
        *tree = aux;
        return;
    }

    if ((*tree)->right == NULL) {
        (*tree)->right = aux;
    }

    return;
}

void addOrd(Tree ** tree, INFO info) {
    if (isEmpty(tree)) {
        (*tree) = createNodo(info);
        return;
    }

    if ((*tree)->info >= info) {
        if ((*tree)->left != NULL) {
            addOrd(&((*tree)->left), info);
        } else {
            (*tree)->left = createNodo(info);
        }
        return;
    }

    if ((*tree)->right != NULL) {
        addOrd(&((*tree)->right), info);
    } else {
        (*tree)->right = createNodo(info);
    }
}

void getAscOrd(Tree * tree) {
    if (tree->left != NULL) {
        getAscOrd(tree->left);
    }

    std::cout << tree->info << "\t";

    if (tree->right != NULL) {
        getAscOrd(tree->right);
    }
}

void getDescOrd(Tree * tree) {
    if (tree->right != NULL) {
        getDescOrd(tree->right);
    }

    std::cout << tree->info << "\t";

    if (tree->left != NULL) {
        getDescOrd(tree->left);
    }
}

TNODO * search(Tree * tree, INFO info) {
    if (tree->info == info) {
        return tree;
    }

    if (tree->info > info && tree->left != NULL) {
        return search(tree->left, info);
    }

    if (tree->info < info && tree->right != NULL) {
        return search(tree->right, info);
    }

    return NULL;

}

void insertBalance(Tree ** tree, INFO info, bool * h) {
    TNODO * p1;
    TNODO * p2;

    if (*tree == NULL) {
        (*tree) = createNodo(info);
        *h = true;
    } else {
        if ((*tree)->info > info) {
            insertBalance(&((*tree)->left), info, h);
            if (*h) {
                switch ((*tree)->bal) {
                    case 1:
                    {
                        (*tree)->bal = 0;
                        *h = false;
                        break;
                    }
                    case 0:
                    {
                        (*tree)->bal = -1;
                        break;
                    }
                    case -1:
                    {
                        p1 = (*tree)->left;
                        if (p1->bal == -1) {
                            (*tree)->left = p1->right;
                            p1->right = (*tree);
                            (*tree)->bal = 0;
                            (*tree) = p1;
                        } else {
                            p2 = p1->right;
                            p1->right = p2->left;
                            p2->left = p1;
                            (*tree)->left = p2->right;
                            p2->right = (*tree);
                            if (p2->bal == -1) {
                                (*tree)->bal = 1;
                            } else {
                                (*tree)->bal = 0;
                            }
                            if (p2->bal == 1) {
                                p1->bal = -1;
                            } else {
                                p1->bal = 0;
                            }
                            (*tree) = p2;
                        }
                        (*tree)->bal = 0;
                        *h = false;
                    }
                } // switch
            }
        } else {
            if ((*tree)->info < info) {
                insertBalance(&((*tree)->right), info, h);
                if (*h) {
                    switch ((*tree)->bal) {
                        case -1:
                        {
                            (*tree)->bal = 0;
                            *h = false;
                            break;
                        }
                        case 0:
                        {
                            (*tree)-> bal = 1;
                            break;
                        }
                        case 1:
                        {
                            p1 = (*tree)->right;
                            if (p1->bal == 1) {
                                (*tree)->right = p1->left;
                                p1->left = (*tree);
                                (*tree)->bal = 0;
                                (*tree) = p1;
                            } else {
                                p2 = p1->left;
                                p1->left = p2->right;
                                p2->right = p1;
                                (*tree)->right = p2->left;
                                p2->left = (*tree);
                                if (p2->bal == 1) {
                                    (*tree)->bal = -1;
                                } else {
                                    (*tree)->bal = 0;
                                }
                                if (p2->bal == -1) {
                                    p1->bal = 1;
                                } else {
                                    p1->bal = 0;
                                }
                                (*tree) = p2;
                            }
                            (*tree)->bal = 0;
                            *h = false;
                        }
                    }// switch
                }

            } else {
                (*tree)->count = (*tree)->count + 1;
            }
        }
    }
}

























