class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        int totGas = 0;
        int totCost = 0;

        for(int i=0;i<n;i++)
        {
            totGas += gas[i];
            totCost += cost[i];
        }

        if(totGas < totCost){
            return -1;
        }

        int startInd = 0;
        int cur = 0;

        for(int i=0;i<n;i++){

            cur += (gas[i] - cost[i]);

            if(cur < 0){
                startInd = i + 1;
                cur = 0;

            }

        }

        return startInd;
    }
};