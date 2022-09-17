#pragma once
#include <string>

using namespace std;

struct node
{
    int key;
    string FIO;
    unsigned char height;
    node* left;
    node* right;
    node(int k, string fio)
    {
        FIO = fio;
        key = k;
        left = right = 0;
        height = 1;
    }
};

unsigned char height(node* p);

int bfactor(node* p);

void fixheight(node* p);

node* rotateright(node* p);

node* rotateleft(node* p);

node* balance(node* p);

string search(node* p, int k);

node* insert(node* p, int k, string FIO);

node* findmin(node* p);

node* findmax(node* p);

node* removemin(node* p);

node* remove(node* p, int k);

void print(node* p, int level);
