class Encrypter {
public:
    map<char, string> mp;
    vector<string> dict;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        for(int i=0; i<n; i++)
            mp[keys[i]] = values[i];
        
        dict = dictionary;
    }
    
    string encrypt(string word1) {
        string ans;
        for(char i:word1){
            ans += mp[i];
        }
        
        return ans;
    }
    
    int decrypt(string word2) {
        int cnt = 0;
        
        for(auto i:dict){
            if(word2==encrypt(i))
                cnt++;
        }
        
        return cnt;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */