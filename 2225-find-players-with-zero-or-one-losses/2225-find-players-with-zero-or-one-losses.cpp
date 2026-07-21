class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int , int>lost_map;
        
        for(int i=0 ; i<matches.size() ; i++)
        {
            int loser = matches[i][1];
            lost_map[loser]++;
        }

        vector<int>lost_once;
        vector<int>always_winner;

        for(int i=0 ; i<matches.size() ; i++)
        {
            int winner = matches[i][0];
            int looser = matches[i][1];

            if(lost_map.find(winner) == lost_map.end())
            {
                always_winner.push_back(winner);
                lost_map[winner] = 2;
            }
            if(lost_map[looser] == 1)
            {
                lost_once.push_back(looser);
            }
        }
        sort(lost_once.begin() , lost_once.end());
        sort(always_winner.begin() , always_winner.end());

        return {always_winner , lost_once};
    }
};