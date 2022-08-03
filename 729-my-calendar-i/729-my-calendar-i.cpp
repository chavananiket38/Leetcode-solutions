class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(v.empty()){
            v.push_back({start,end});
            return true;
        }
        
        for(int i=0; i<v.size(); i++){
            if(start>=v[i].first && start<v[i].second)
                return false;
            if(v[i].first<end and v[i].second>end)
                return false;
            if(v[i].first>start and v[i].second<=end)
                return false;
        }
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */