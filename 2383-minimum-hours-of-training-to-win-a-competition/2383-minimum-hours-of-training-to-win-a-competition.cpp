class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int res = 0;
        for(int i = 0;i<energy.size();i++){
            // Energy part
            if(initialEnergy <= energy[i]){
                res += energy[i] - initialEnergy + 1;
                initialEnergy += energy[i]-initialEnergy+1;
            }
            if(initialExperience <= experience[i]){
                res+= experience[i]-initialExperience +1;
                initialExperience += experience[i]-initialExperience+1; 
            }

            initialEnergy = initialEnergy-energy[i];
            initialExperience += experience[i];
        }
        return res;
    }
};