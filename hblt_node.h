#pragma once

template <class T>
struct HbltNode {
    int sVal_;
    T element_;
    HbltNode<T> *left_, *right_;
    
    HbltNode() {
        sVal_ = 0;
        left_ = NULL;
        right_ = NULL;
    }
    HbltNode(const T& element):element_(element) {
        sVal_ = 1;
        left_ = NULL;
        right_ = NULL;
    }
};