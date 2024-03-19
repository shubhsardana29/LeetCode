class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        //for storing least number of units of times that the CPU will take
        int ans=0;
        unordered_map<char,int> mp;
        priority_queue<int> q;
        // storing count of each character in map
        for(auto i: tasks){
            mp[i]++;
        }
        // Pushing all elements to the Priority Queue
        for(auto j: mp){
            q.push(j.second);
        }
        while(!q.empty()){
            int time=0;
            vector<int> v; 
            // executing the n+1 task
            for(int i=0;i<=n;i++){
                if(!q.empty()){
                    v.push_back(q.top()-1);
                    q.pop();
                    time=time+1;
                }
            }
             // If elements in vector are still greater than 0 then again push them back to the priority queue)
            for(auto i: v){
                if(i>0){
                    q.push(i);
                }
            }
            // If all the task are over(priority queue is empty) then adding 'tt' to the ans variable otherwise adding n+1 which includes idle time as well
            if(q.empty()){
                ans+=time;
            }
            else{
                ans+=(n+1);
            }
        }
        return ans;
    }
};