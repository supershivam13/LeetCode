class MyHashMap {
    vector<list<pair<int,int>>> map;
    int m_size = 10000;

public:
    
    MyHashMap() {
        map.resize(m_size);
    }
    
    void put(int key, int value) {
        auto &list = map[key % m_size];
        for (auto & val : list) {
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }
    
    int get(int key) {
        const auto &list = map[key % m_size];
        if (list.empty()) {
            return -1;
        }
        for (const auto & val : list) {
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        auto& pairs = map[key%m_size];
        for(auto i=pairs.begin(); i!= pairs.end(); i++) {
            if(i->first==key) { 
                pairs.erase(i); return; 
            }
        }
    }
};

// ***********************************************************

// Method - 2

// Simple solution when we know the key range (given in constraints)
// But interviewers wouldnt be happy if you solve this question like this since key can be very very huge as well.
// We would waste a lot of space here in case of huge key values since we are using arrays as a hash map.

// vector<int> map;

// MyHashMap() { 
//     map.resize(1000001,-1);
// }

// void put(int key, int value) {
//     map[key] = value;
// }

// int get(int key) {
//     return map[key];
// }

// void remove(int key) {
//     map[key] = -1;
// }