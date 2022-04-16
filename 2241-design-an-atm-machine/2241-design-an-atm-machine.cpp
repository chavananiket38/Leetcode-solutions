class ATM {
public:
    vector<long long> banknotes;
    vector<long long> notesType;
    ATM() {
        banknotes = vector<long long> (5, 0);
        notesType = {20, 50, 100, 200, 500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0; i<5; i++){
            banknotes[i] += banknotesCount[i]; 
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);
        
        for(int i=4; i>=0; i--){
            if(amount>0){
                ans[i] += min(banknotes[i], amount/notesType[i]);
                amount -= ans[i] * notesType[i];
            }
        }
        if(amount>0)
            return {-1};
        for(int i=0; i<5; i++) banknotes[i] -= ans[i];
        
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */