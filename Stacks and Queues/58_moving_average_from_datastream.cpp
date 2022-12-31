class MovingAverage{
    public:
        queue<int>q;
        int size;
        int sum;

        MovingAverage(int s){
            size = s;
            sum = 0;
        }

        double next(int val){
            sum += val;
            q.push(val);
            if(q.size() > size){
                sum -= q.back();
            }
            double avg = ((double)sum) / q.size();
            return avg;
        }
};