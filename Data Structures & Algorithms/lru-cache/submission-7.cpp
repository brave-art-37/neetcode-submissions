class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val):key(key),val(val),prev(nullptr),next(nullptr){}
    };

    //dummy head and tail to avoid edge cases
    Node* head; Node* tail;
    unordered_map<int,Node*> mp;
    int size; int cap;

    LRUCache(int cap):mp(),size(0),cap(cap) {
        size=0;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node* data){//insert before tail
        //fwd connect
        tail->prev->next = data;
        data->next = tail;
        //bwd connect
        data->prev = tail->prev;
        tail->prev = data;
    }

    void remove(Node* data){ //cut out Node 
        //fwd connect
        data->prev->next = data->next;
        //bwd connect
        data->next->prev = data->prev;
    }
    
    int get(int key) {
        if(mp.count(key)==0) return -1; //not present
        Node* data = mp[key];
        remove(data); insert(data); //make it recent
        return data->val;
    }

    void put(int key, int value) {
        if(mp.count(key)!=0){ //already present
            Node* data = mp[key];
            remove(data); insert(data); //make it recent
            data->val = value; //update val
            return;
        }
        Node* data = new Node(key,value);
        mp[key]=data;
        insert(data);
        size++;

        while(size>cap){
            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
            size--;
        }
    }
};
