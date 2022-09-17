#include "Tree.h"
#include <iostream>

//высота
unsigned char height(node* p)
{
    if (p)
    {
        return p->height;
    }
    else
    {
        return 0;
    }
}

//вычисляет балансирующий фаактор
int bfactor(node* p)
{
    return height(p->right) - height(p->left);
}

//восстанавливает корректное значение поля heigh
void fixheight(node* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    if (hl > hr)
    {
        p->height = hl + 1;
    }
    else
    {
        p->height = hr + 1;
    }
}

//поворот вправо
node* rotateright(node* p)
{
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

//поворот влево
node* rotateleft(node* p)
{
    node* q = p->right;
    p->right = q->left;
    q->left = p;
    fixheight(p);
    fixheight(q);
    return q;
}

//балансировка
node* balance(node* p)
{
    fixheight(p);
    if (bfactor(p) == 2)
    {
        if (bfactor(p->right) < 0)
        {
            p->right = rotateright(p->right);
        }

        return rotateleft(p);
    }
    if (bfactor(p) == -2)
    {
        if (bfactor(p->left) > 0)
        {
            p->left = rotateleft(p->left);
        }

        return rotateright(p);
    }

    return p;
}

string search(node* p, int k)
{
    if (p == 0)
    {
        return "Not found";
    }

    if (k == p->key)
    {
        return p->FIO;
    }
    else
    {
        if (k < p->key)
        {
            return search(p->left, k);
        }
        else
        {
            return search(p->right, k);
        }
    }
}

node* insert(node* p, int k, string FIO)
{
    if (!p)
    {
        return new node(k, FIO);
    }

    if (k < p->key)
    {
        p->left = insert(p->left, k, FIO);
    }
    else
    {
        p->right = insert(p->right, k, FIO);
    }

    return balance(p);
}

node* findmin(node* p)
{
    if (p->left)
    {
        return findmin(p->left);
    }
    else
    {
        return p;
    }
}

node* findmax(node* p)
{
    if (p->right)
    {
        return findmax(p->right);
    }
    else
    {
        return p;
    }
}

node* removemin(node* p)
{
    if (p->left == 0)
    {
        return p->right;
    }

    p->left = removemin(p->left);
    return balance(p);
}

node* remove(node* p, int k)
{
    if (!p)
    {
        return 0;
    }

    if (k < p->key)
    {
        p->left = remove(p->left, k);
    }
    else
    {
        if (k > p->key)
        {
            p->right = remove(p->right, k);
        }
        else
        {
            node* q = p->left;
            node* r = p->right;
            delete p;
            if (!r)
            {
                return q;
            }

            node* min = findmin(r);
            min->right = removemin(r);
            min->left = q;
            return balance(min);
        }
    }

    return balance(p);
}

void print(node* p, int level)
{
    if (p)
    {
        print(p->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            cout << "    ";
        }

        cout << p->key << "(" << p->FIO << ")" << endl;

        print(p->left, level + 1);
    }
}
