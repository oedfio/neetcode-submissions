class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity){
        
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        else {
            int res = it->second->second;
            auto list_it = it->second;
            list.erase(list_it);
            list.insert(list.begin(), {key, res});
            map[key] = list.begin();
            return res;
        }
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            list.push_front({key, value});
            list.erase(it->second);
            map[key] = list.begin();

        }
        else if (size == capacity) {
            auto it_last = prev(list.end());
            map.erase(it_last->first);
            list.pop_back();
            list.push_front({key, value});
            map[key] = list.begin();
        }
        else {
            size++;
            list.push_front({key, value});
            map[key] = list.begin();
        }
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int size = 0;
    int capacity;
    list<pair<int, int>> list;
};
