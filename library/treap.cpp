struct Node {
    int x;
    ll y;
    int sz;
    Node* left;
    Node* right;
    Node(int x = 0)
        : x(x)
        , y((ll)rnd())
        , sz(1)
        , left(NULL)
        , right(NULL)
    {
    }
};

int sz(Node* v) { return (v == NULL ? 0 : v->sz); }

Node* upd(Node* v)
{
    if (v != NULL) { v->sz = 1 + sz(v->left) + sz(v->right); }
    return v;
}

Node* merge(Node* l, Node* r)
{
    if (l == NULL) { return r; }
    if (r == NULL) { return l; }
    if (l->y < r->y) {
        l = merge(l, r->left);
        r->left = l;
        r = upd(r);
        return r;
    }
    r = merge(l->right, r);
    l->right = r;
    l = upd(l);
    return l;
}

pair<Node*, Node*> keySplit(Node* v, int key)
{ // l's keys <= key, r's keys > key
    if (v == NULL) { return { v, v }; }
    if (v->x <= key) {
        auto a = keySplit(v->right, key);
        v->right = a.first;
        v = upd(v);
        return { v, a.second };
    }
    auto a = keySplit(v->left, key);
    v->left = a.second;
    v = upd(v);
    return { a.first, v };
}

pair<Node*, Node*> sizeSplit(Node* v, int siz)
{ // l's size is siz
    if (!v) { return { v, v }; }
    if (sz(v->left) >= siz) {
        auto a = sizeSplit(v->left, siz);
        v->left = a.second;
        v = upd(v);
        return { a.first, v };
    }
    auto a = sizeSplit(v->right, siz - sz(v->left) - 1);
    v->right = a.first;
    v = upd(v);
    return { v, a.second };
}

void gogo(Node* v)
{
    if (v == NULL) { return; }
    gogo(v->left);
    cerr << v->x << endl;
    gogo(v->right);
}