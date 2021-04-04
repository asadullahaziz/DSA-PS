#pragma once

#include<iostream>

using namespace std;

template<class T>
class Node
{
public:

    T data;
    Node <T>* next;
    Node <T>* prev;
    
    Node()
    {
        data = 0;
        next = 0;
        prev = 0;
    }
    Node(T val)
    {
        data = val;
        next = 0;
        prev = 0;
    }
};