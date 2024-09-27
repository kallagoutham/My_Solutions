class MyCalendarTwo {
public:
    map<int, int> cal;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        cal[start]++;
        cal[end]--;
        int active_events = 0;
        for (auto& event : cal) {
            active_events += event.second;
            if (active_events >= 3) {
                cal[start]--;
                cal[end]++;
                if (cal[start] == 0) cal.erase(start);
                if (cal[end] == 0) cal.erase(end);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
