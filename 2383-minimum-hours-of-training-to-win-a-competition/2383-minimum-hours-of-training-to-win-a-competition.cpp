class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int total = 0;
        int totalExp = 0;
        for(auto i:energy)
            total += i;
        for(auto i:experience)
            totalExp += i;
        
        if(initialEnergy>total && initialExperience>totalExp)
            return 0;
        
        int exp = initialExperience;
        int diff = 0;
        for(auto i:experience){
            if(exp<=i)
                diff = max(i-exp+1,diff);
            exp += i;
        }
        
        cout<<diff;
        if(total>=initialEnergy)
        return total-initialEnergy+diff+1;
        
        return diff;
    }
};


// 11
// 23
// [69,22,93,68,57,76,54,72,8,78,88,15,58,61,25,70,58,91,79,22,91,74,90,75,31,53,31,7,51,96,76,17,64,89,83,54,28,33,32,45,20]
// [51,81,46,80,56,7,46,74,64,20,84,66,13,91,49,30,75,43,74,88,82,51,72,4,80,30,10,19,40,27,21,71,24,94,79,13,40,28,63,85,70]