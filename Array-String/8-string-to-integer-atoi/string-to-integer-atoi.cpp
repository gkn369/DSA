class Solution {
public:
    int myAtoi(string str) {

        long long res = 0;
        int sign = 1;
        int i = 0;
        while(i < str.size() && str[i] == ' ')
            i++;
        if(str[i] == '+')
        {
            i++;
        }
        else if(str[i] == '-')
        {
            sign = -1;
            i++;
        }
        int n = str.size();
        while(i < n)
        {
            if(str[i] < '0' || str[i] > '9')
                break;
            int digit = str[i] - '0';
            res = res * 10 + digit;

            if(sign * res > INT_MAX )
                return INT_MAX;
            if (sign * res < INT_MIN)
                return INT_MIN;

            i++;
        }
        return  sign * res;
    }
};