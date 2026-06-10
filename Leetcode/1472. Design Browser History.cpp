class BrowserHistory {
public:
    stack<string> forwardHistory,backwardHistory;
    BrowserHistory(string homepage) {
        backwardHistory.push(homepage);
    }   
    
    void visit(string url) {
        backwardHistory.push(url);
        forwardHistory = {};
    }
    
    string back(int steps) {
        while(steps && backwardHistory.size()>1){
            forwardHistory.push(backwardHistory.top());
            backwardHistory.pop();
            steps--;
        }
        return backwardHistory.top();
    }
    
    string forward(int steps) {
        while(steps && !forwardHistory.empty()){
            backwardHistory.push(forwardHistory.top());
            forwardHistory.pop();
            steps--;
        }
        return backwardHistory.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forwardHistory(steps);
 */
