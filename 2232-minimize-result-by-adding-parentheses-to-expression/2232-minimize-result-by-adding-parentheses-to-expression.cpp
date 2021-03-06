class Solution {
public:
    string minimizeResult(string s) {
        
        int plus = s.find("+");
        int smallest = INT_MAX, n = s.size();
        string res = "";
        
        for(int i=0; i<plus; i++){
            for(int j=plus+1; j<n ; j++){
                string a = s.substr(0, i);
                string b = s.substr(i, plus-i);
                string c = s.substr(plus+1, j-plus);
                string d = s.substr(j+1);
                
                int p = (a=="") ? 1 : stoi(a);
                int q = (b=="") ? 1 : stoi(b);
                int r = (c=="") ? 1 : stoi(c);
                int s = (d=="") ? 1 : stoi(d);
                
                int temp = p*(q+r)*s;
                if(temp<smallest){
                    smallest = temp;
                    res = a + "(" + b + "+" + c + ")" + d;
                }
            }
        }
         return res;
    }             
};