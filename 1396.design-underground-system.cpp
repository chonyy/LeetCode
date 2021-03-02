/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System

hashMap<int, pair<string, int>>
    - record all the checkintgs 
    - map the ID to the station and the time

when there's a checkout:
    1. get the pair with the ID
    2. record the travel time

preprocessing:
    - Taiwan to Japan => "Taiwan-Japan"

hashMap<string, vector<int>>
    - record the checkin/out stations and all the travel time between the two stations


checkIn: save it in the map O(1)
checkOut: calcualte the travel

 */

// @lc code=start
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInTime;
    unordered_map<string, pair<int, int>> travelTimes;
    UndergroundSystem() {
        // No need to initialize
    }
    
    // O(1)
    void checkIn(int id, string stationName, int t) {
        // Save it in the map
        checkInTime[id] = {stationName, t};
    }
    
    // O(1)
    void checkOut(int id, string stationName, int t) {
        // Get the check int time and station
        auto checkInRecord = checkInTime[id];

        // Save it to the travelTime map
        saveTravelTime(checkInRecord.first, stationName, t - checkInRecord.second);
    }
    
    // O(N) => N = the total travels between the two stations
    double getAverageTime(string startStation, string endStation) {
        // Loop through all the travels times between the stations
        // Calculate the average

        string stationKey = startStation + '-' + endStation;
        auto times = travelTimes[stationKey];
        cout << times.first << " " << times.second << endl;
        return (double)times.first / times.second;
    }

    void saveTravelTime(string& startingStation, string& endingStation, int travelTime) {
        string stationKey = startingStation + '-' + endingStation;
        auto& times = travelTimes[stationKey];
        times.first += travelTime;
        times.second ++;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

