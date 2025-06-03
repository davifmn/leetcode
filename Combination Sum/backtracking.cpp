class Solution {
public:
    vector<vector<int>> possibilidades;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        backtrack(candidates, target, 0, current);
        return possibilidades;
    }

    void backtrack(const vector<int>& candidates, int target, int start, vector<int>& current) {
        if (target == 0) {
            possibilidades.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i, current); // i é o start novamente
                current.pop_back(); // remove ultima escolha
            }
        }
    }
};
