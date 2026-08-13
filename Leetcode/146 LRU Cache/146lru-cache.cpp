class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int x , int y)
    {
        key=x;
        val=y;
        next=nullptr;
        prev=nullptr;
    }
};

 
class LRUCache {
public:
Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);

int size;
unordered_map<int,Node*> mpp;
void insertafterhead(Node* node)
{
    Node* nextt=head->next;
    nextt->prev=node;
    head->next=node;
    node->prev=head;
    node->next=nextt;
    
}
void deletenode(Node* node)
{
    Node* before = node->prev;
    Node* after = node->next;
    before->next=after;
    after->prev=before;
}

    LRUCache(int capacity) {
        head->next=tail;
        head->prev=nullptr;
        tail->prev=head;
        tail->next=nullptr;
        mpp.clear();
        size=capacity;
        
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) 
        return -1;
        Node * node=mpp[key];
        deletenode(node);
        insertafterhead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            Node* node = mpp[key];
            node->val=value;
            deletenode(node);
            insertafterhead(node);
        }
        else if(mpp.size()==size)
        {
            Node* node=tail->prev;
            mpp.erase(node->key);
            deletenode(node);
            Node* n=new Node(key,value);
            insertafterhead(n);
            mpp[key]=n;
        }
        else
        {
            Node* n=new Node(key,value);
            insertafterhead(n);
            mpp[key]=n;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */