class HitCounter{
    public:
        deque<int>q;

        HitCounter(){

        }

        void hit(int timestamp){
            q.push_back(timestamp);
            int start = timestamp - 300 + 1;
            while(q.top() < start){
                q.pop_front();
            }
        }

        int getHits(int timestamp){
            int start = timestamp - 300 + 1;
            while(q.top() < start){
                q.pop_front();
            }
            return q.size();
        } 
};