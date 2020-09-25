class Solution {
    class Car{
    public:
        int position;
        double time;
        Car(int p, double t){
            position = p;
            time = t;
        }
    };
    struct Comp{
        bool operator()(const Car& c1, const Car& c2){
            return c1.position < c2.position;
        }
    };
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int N = position.size();
        vector<Car> cars;
        for(int i = 0; i < N; ++i){
            cars.push_back(Car(position[i], (double) (target - position[i]) / speed[i]));
        }
        sort(cars.begin(), cars.end(), Comp());
        int ans = 0, t = N;
        while(--t > 0){
            if(cars[t].time < cars[t-1].time) ans++;
            else cars[t-1] = cars[t];
        }
        return ans + (t == 0 ? 1 : 0);
    }
};