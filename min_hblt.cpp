/**
 ADS Project 1
 min_hblt.cpp
 Purpose: Implementation of methods for the Min Height-biased leftist tree class.
 
 @author Terek Arce
 @version 2.0 1/13/16
 */

#include "queue.h"
#include "exceptions.h"

template <class T>
MinHblt<T>::MinHblt() {
    root_ = NULL;
    size_ = 0;
}

template <class T>
MinHblt<T>::~MinHblt() {
    PostOrder(Destroy);
    root_ = NULL;
    size_ = 0;
}

template <class T>
void MinHblt<T>::Destroy(HbltNode<T> *t) {
    delete t;
}

template <class T>
void MinHblt<T>::PostOrderOutput() {
    PostOrder(Output); cout << endl;
}

template <class T>
void MinHblt<T>::PreOrderOutput() {
    PreOrder(Output); cout << endl;
}

template <class T>
void MinHblt<T>::LevelOrderOutput() {
    LevelOrder(Output); cout << endl;
}

template <class T>
void MinHblt<T>::InOrderOutput() {
    InOrder(Output); cout << endl;
}

template <class T>
void MinHblt<T>::Output(HbltNode<T> *t) {
    cout << t->element_ << ' ';
}

template <class T>
void MinHblt<T>::PostOrder(void (*theVisit) (HbltNode<T> *)) {
    Visit_ = theVisit;
    PostOrder(root_);
}

template <class T>
void MinHblt<T>::LevelOrder(void (*theVisit) (HbltNode<T> *)) {
    Visit_ = theVisit;
    LevelOrder(root_);
}

template <class T>
void MinHblt<T>::PreOrder(void (*theVisit) (HbltNode<T> *)) {
    Visit_ = theVisit;
    PreOrder(root_);
}

template <class T>
void MinHblt<T>::InOrder(void (*theVisit) (HbltNode<T> *)) {
    Visit_ = theVisit;
    InOrder(root_);
}

template <class T>
void MinHblt<T>::PostOrder(HbltNode<T>* t) {
    if (t != NULL) {
        PostOrder(t->left_);
        PostOrder(t->right_);
        MinHblt<T>::Visit_(t);
    }
}

template <class T>
void MinHblt<T>::PreOrder(HbltNode<T>* t) {
    if (t != NULL) {
        MinHblt<T>::Visit_(t);
        PostOrder(t->left_);
        PostOrder(t->right_);
    }
}

template <class T>
void MinHblt<T>::InOrder(HbltNode<T>* t) {
    if (t != NULL) {
        PostOrder(t->left_);
        MinHblt<T>::Visit_(t);
        PostOrder(t->right_);
    }
}

template <class T>
void MinHblt<T>::LevelOrder(HbltNode<T>* t) {
    Queue<HbltNode<T> *> q;
    while (t != NULL) {
        Visit_(t);
        if (t->left_ != NULL)
            q.push(t->left_);
        if (t->right_ != NULL)
            q.push(t->right_);
        if (q.Empty()) {
            return;
        }
        else {
            t = q.Remove();
        }
    }
}

template<class T>
void MinHblt<T>::Initialize(T* elements, int size) {
    Queue<HbltNode<T>*> q(size);
    PostOrder(Destroy);
    
    for (int i = 1; i <= size; i++)
        q.Add(new HbltNode<T>(elements[i]));
    
    for (int i = 1; i <= size - 1; i++) {
        HbltNode<T> *a = q.Remove();
        HbltNode<T> *b = q.Remove();
        Meld(a,b);
        q.Add(a);
    }
    
    if (size > 0)
        root_ = q.Peek();
    size_ = size;
}

template<class T>
void MinHblt<T>::Meld(HbltNode<T>* &x, HbltNode<T>* &y) {
    if (y == NULL)
        return;
    if (x == NULL) {
        x = y;
        return;
    }
    if (y->element_ < x->element_) //change to > for maxHblt
        swap(x, y);
    // now x->element_ <= y->element_
    Meld(x->right_,y);
    
    if (x->left_ == NULL) {
        x->left_ = x->right_;
        x->right_ = NULL;
        x->sVal_ = 1;
    }
    else {
        if (x->left_->sVal_ < x->right_->sVal_)
            swap(x->left_, x->right_);
        x->sVal_ = x->right_->sVal_ + 1;
    }
}

template<class T>
void MinHblt<T>::Add(const T& element) {
    HbltNode<T> *q = new HbltNode<T>(element);
    Meld(root_, q);
    size_++;
}


// meld *this and theHblt
template<class T>
void MinHblt<T>::Meld(MinHblt<T>& hblt) {
    Meld(root_, hblt.root_);
    size_ += hblt.size_;
    hblt.root_ = NULL;
    hblt.size_ = 0;
}

template<class T>
T& MinHblt<T>::RemoveMin() {
    if (root_ == NULL)
        throw queueEmpty();
    HbltNode<T> *left = root_->left_;
    HbltNode<T> *right = root_->right_;
    T& min = root_->element_;
    delete root_;
    root_ = left;
    Meld(root_, right);
    size_--;
    return min;
}

template <class T>
bool MinHblt<T>::IsEmpty() const {
    return size_ == 0;
}

template <class T>
const T& MinHblt<T>::Peek() {
    if (size_ == 0)
        throw queueEmpty();
    return root_->element_;
}

template <class T>
int MinHblt<T>::Size() const {
    return size_;
}



