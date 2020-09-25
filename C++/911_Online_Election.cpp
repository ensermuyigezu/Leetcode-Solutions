class TopVotedCandidate {
    struct Vote{
        int person, time;
        Vote(int p, int t){
            person = p;
            time = t;
        }
    };
public:
    vector<Vote> A;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> count;
        int leader = -1;
        int m = 0;
        for(int i = 0; i < persons.size(); ++i){
            int p = persons[i];
            int t = times[i];
            int c = count[p] + 1;
            count[p] = c;
            if(c >= m){
                if(p != leader){
                    leader = p;
                    A.push_back(Vote(leader, t));
                }
                if(c > m) m = c;
            }
        }
    }
    int q(int t) {
        int lo = 1;
        int hi = A.size();
        while(lo < hi){
            int mi = lo + (hi - lo) / 2;
            if(A[mi].time <= t){
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return A[lo-1].person;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */