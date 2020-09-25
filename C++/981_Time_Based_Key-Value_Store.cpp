class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<string, int>>> mp; // [key, vec[val, time]]
    TimeMap() {   
    }
    
    void set(string key, string value, int timestamp) {
       mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& v = mp[key];
        auto it = upper_bound(v.begin(), v.end(), timestamp, [](int val, auto& p){return val < p.second;});
        return it == v.begin() ? "" : prev(it)->first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */