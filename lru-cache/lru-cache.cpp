class Node{
public:
    int key;
    int value;
    
    Node(int key,int value){
        this->key=key;
        this->value=value;
    }
};

class LRUCache {
    int cap;
    list<Node> l;
    unordered_map< int, list<Node>::iterator > m;
    
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        
        if(m.count(key)!=0){
            
            auto it=m[key];
            int ans=it->value;
            l.push_front(*it);
            l.erase(it);
            m[key]=l.begin();
            return ans;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        cout<<"put ";
        
        if(m.count(key)!=0){
            
            auto it=m[key];
            it->value= value;
            l.push_front(*it);
            l.erase(it);
            m[key]=l.begin();
            
        }
        else{
            
            cout<<"else ";
            
            if(l.size()==cap){
                auto it = l.back();
                m.erase(it.key);
                l.pop_back();
                cout<<"hi";
            }
            cout<<"out ";
            Node* n= new Node(key,value);
            l.push_front(*n);
            m[key] = l.begin();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */