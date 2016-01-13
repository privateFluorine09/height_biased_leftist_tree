/**
 ADS Project 1
 min_hblt.h
 Purpose: Interfarce for a Min Height-biased leftist tree.
 
 @author Terek Arce
 @version 2.0 1/13/16
 */

#pragma once

#include "hblt_node.h"

template <class T>
class MinHblt {
	public:
    MinHblt();
    ~MinHblt();
    
    void PostOrderOutput();
    void LevelOrderOutput();
    void PreOrderOutput();
    void InOrderOutput();
    
    bool IsEmpty() const;
    
    int Size() const;
    const T& Peek();
    T& RemoveMin();
    void Add(const T&);
    void Initialize(T*, int);
    void Meld(MinHblt<T>&);

	private:
    HbltNode<T> *root_;
    int size_;
    static void (*Visit_) (HbltNode<T> *);
    
    void PostOrder(void (*theVisit) (HbltNode<T> *));
    void LevelOrder(void (*theVisit) (HbltNode<T> *));
    void PreOrder(void (*theVisit) (HbltNode<T> *));
    void InOrder(void (*theVisit) (HbltNode<T> *));
    
    static void PostOrder(HbltNode<T>*);
    static void LevelOrder(HbltNode<T>*);
    static void PreOrder(HbltNode<T>*);
    static void InOrder(HbltNode<T>*);

    static void Destroy(HbltNode<T> *);
    static void Output(HbltNode<T> *);

    void Meld(HbltNode<T> * &, HbltNode<T> * &);
};

template <class T>
void (*MinHblt<T>::Visit_)(HbltNode<T> *);

#include "min_hblt.cpp"