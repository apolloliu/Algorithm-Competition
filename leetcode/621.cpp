int num[26];
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        memset(num, 0, sizeof(num));
        int m = tasks.size();
        for(int i = 0; i < m; ++i){
            int c = tasks[i] - 'A';
            num[c]++;
        }
        sort(num, num+26, greater<int>());
        int i = 0, step = 0, sum = 0, t = 0;
        n++;
        while(true){
            step = 0;
            sort(num, num+26, greater<int>());
            for(i = 0; i < 26; i++){
                if(num[i]){
                    num[i]--;
                    sum++;
                    step++;
                    t++;
                    if(step == n)break;
                }
            }
            if(t == m)break;
            if(step < n)sum += (n-step);
        }
        return sum;
    }
};

