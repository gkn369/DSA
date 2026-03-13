class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives = 0, tens = 0;

        for(int i = 0; i < n; i++)
        {
            if(bills[i] == 5)
            {
                fives++;
            }
            else if(bills[i] == 10)
            {
                if(fives)
                {
                    fives--;
                    tens++;
                }
                else
                    return false;
            }
            else if(bills[i] == 20)
            {
                if(tens && fives)
                {
                    tens--;
                    fives--;
                }
                else if(fives >= 3)
                {
                    fives = fives - 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};