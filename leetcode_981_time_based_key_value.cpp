class TimeMap {
public:
unordered_map<string,map<string,int>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][value]=timestamp;
    }
    
    string get(string key, int timestamp) {
        int mx=INT_MIN;
        if(m.find(key)!=m.end())
        {
            for(auto x:m[key])
            {
                int t=x.second;
                if(t<=timestamp)
                {
                    mx=max(mx,t);
                }
            }
            for(auto x:m[key])
            {
                if(x.second==mx) return x.first;
            }
        }
        return "";
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
