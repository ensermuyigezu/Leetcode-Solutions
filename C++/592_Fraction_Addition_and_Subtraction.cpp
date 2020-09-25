class Solution {
public:
    int findGCD(int a, int b){
        if(a == 0)
            return b;
        return findGCD(b % a, a); 
    }
    int findLCM(int a, int b){
        int gcd= findGCD(a, b);
        int lcm = a*b / gcd;
        return lcm;
    }
    string fractionAddition(string expression) {
        vector<int> num;
        vector<int> den;
        string seq = "";
        bool denflag = false;
        for (int i = 0; i < expression.size(); i++){
            if (denflag && (expression[i] == '+' || expression[i] == '-')){
                int temp = stoi(seq);
                den.push_back(temp);
                seq = "";
                if(expression[i] == '-'){
                    seq = "-";
                }
                denflag = false;
            } else if (expression[i] == '/'){
                int temp = stoi(seq);
                num.push_back(temp);
                seq = "";
                denflag = true;
            } else {
                seq += expression[i];
            }
        }
        int temp = stoi(seq);
        den.push_back(temp);
        int noOfFractions = num.size();
        string resultFraction = "";
        if (noOfFractions > 0){
            int lcm = 1;
            for (int i = 0; i < noOfFractions; i++){
                lcm = findLCM(lcm, den[i]);
            }
            int resNum = 0;
            for (int i = 0; i < noOfFractions; i++){
                resNum += num[i] * lcm / den[i];
            }
            int common_factor = findGCD(lcm, abs(resNum));
            resNum = resNum / common_factor;
            lcm = lcm / common_factor;
            resultFraction = to_string(resNum) + "/" + to_string(lcm);
        }
        return resultFraction;
    }
};