class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq; // max element top pr aata jayega
        for(int i=0 ; i<n ; i++)
        {
            pq.push(stones[i]);
        }
        //jab tak pq me 2 ya usse jyada elements h tab tak unke top 2 maximum walo ka difference nikalke store krte jao
        while(pq.size() >= 2)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            if(a != b)   // agar a and b are not equal toh unka difference push krdo pq mein.
            {
                pq.push(a-b);
            }
        }
        // agar pq empty h toh return 0 else return top element of pq.
        return pq.empty() ? 0 : pq.top();
    }
};