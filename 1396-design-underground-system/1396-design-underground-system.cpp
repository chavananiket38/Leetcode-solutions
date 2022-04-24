class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> station;
    unordered_map<string, pair<double, int>> route;
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        station[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = station[id];
        station.erase(id);
        
        string routeName = checkIn.first + "_" + stationName;
        route[routeName].first += t - checkIn.second;
        route[routeName].second += 1; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto &temp = route[routeName];
        return temp.first/temp.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */