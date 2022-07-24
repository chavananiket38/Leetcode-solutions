class FoodRatings {
public:
    map<string, set<pair<int, string>>> cuisine_rating_food;
    map<string, string> food_cuisine;
    map<string, int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            cuisine_rating_food[cuisines[i]].insert({-ratings[i], foods[i]});
            food_cuisine[foods[i]] = cuisines[i];
            food_rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &c = food_cuisine.find(food)->second;
        cuisine_rating_food[c].erase({-food_rating[food], food});
        cuisine_rating_food[c].insert({-newRating, food});
        food_rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_rating_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */