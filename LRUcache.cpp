struct node {
    node* pre;
    int key;
    int value;
    node* next;
    node(int k, int v):key(k),value(v),pre(NULL),next(NULL) {};
};

class LRUCache {
    map<int, node*> mp;
    node* head;
    node* tail;
    int size;
    int capacity;
public:
    LRUCache(int c) {
        if (c < 1)return;
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->pre = head;
        mp.clear();
        size = 0;
        capacity = c;
    }

    int get(int k) {
        map<int, node*>::iterator it = mp.find(k);
        if (it != mp.end()) {
            node* cur = (*it).second;
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            putToHead(cur);
            return cur->value;
        } else
            return -1;
    }

    void set(int k, int val) {
        if (capacity < 1)return;
        map<int, node*>::iterator it = mp.find(k);
        if (it != mp.end()) {//find
            node* cur = (*it).second;
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            cur->value = val;
            putToHead(cur);
        } else {//not find
            node* tmp = new node(k,val);
            putToHead(tmp);
            mp[k] = tmp;
            if (size < capacity) {//size < capacity
                size++;
            } else {//size >= capacity
                node* deltmp = tail->pre;
                tail->pre = deltmp->pre;
                deltmp->pre->next = tail;
                it = mp.find(deltmp->key);
                mp.erase(it);
                delete deltmp;
            }
        }
    }
    void putToHead(node* cur)
    {
        cur->next = head->next;
        cur->pre = head;
        cur->next->pre = cur;
        head->next = cur;
    }

};
