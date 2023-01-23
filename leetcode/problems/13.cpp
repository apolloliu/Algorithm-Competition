class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int n = s.size();
        for(int i = 0; i < n; ){
            if(s[i] == 'M'){res += 1000; i++;}
            else if(s.substr(i, 2) == "CM"){res += 900; i+=2;}
            else if(s[i] == 'D'){res += 500; i++;}
            else if(s.substr(i, 2) == "CD"){res += 400; i+=2;}
            else if(s[i] == 'C'){res += 100; i++;}
            else if(s.substr(i, 2) == "XC"){res += 90; i+=2;}
            else if(s[i] == 'L'){res += 50; i++;}
            else if(s.substr(i, 2) == "XL"){res += 40; i+=2;}
            else if(s[i] == 'X'){res += 10; i++;}
            else if(s.substr(i, 2) == "IX"){res += 9; i+=2;}
            else if(s[i] == 'V'){res += 5; i++;}
            else if(s.substr(i, 2) == "IV"){res += 4; i+=2;}
            else if(s[i] == 'I'){res ++; i++;}
        }
        return res;
    }
};
