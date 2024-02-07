
//https://leetcode.com/explore/interview/card/google/65/design-4/3090/
class LRUCache {
    
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> key_val_map;
    list<pair<int, int>> lru;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
       
        auto it = key_val_map.find(key);
        
        if(it == key_val_map.end())
            return -1;
        
        int value = it->second->second;
        lru.erase(it->second);
        lru.push_front({key, value});
        
        key_val_map.erase(it);
        key_val_map[key] = lru.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto it = key_val_map.find(key);
        
        if (key_val_map.find(key) != key_val_map.end()) {
            lru.erase(it->second);
            key_val_map.erase(it);
        }
        
        lru.push_front({key, value});
        key_val_map[key] = lru.begin();
        
        if (key_val_map.size() > capacity) {
            auto it = key_val_map.find(lru.rbegin()->first);
            key_val_map.erase(it);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */