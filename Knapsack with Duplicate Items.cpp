//TLE approach
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> ratio(N,0);
        
        // for(int i=0;i<N;i++){
            
        // }
        
        priority_queue<pair<int,pair<int,int>>> pq;
        
        int maxwt,mwt,mval,ans=0;
        while(W){
           maxwt=INT_MIN;
           mwt=0;
           mval=0;
           for(int i=0;i<N;i++){
               if(wt[i]<=W){
                   float ratio=(val[i]/wt[i]);
                   if(ratio>maxwt){
                       maxwt=ratio;
                       mwt=wt[i];
                       mval=val[i];
                   }
               }
           }
           W-=mwt;
           ans+=mval;
        }
        
        return ans;
    }
};

// Priority queue approach : TLE
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> ratio(N,0);
        
        // for(int i=0;i<N;i++){
            
        // }
        
        priority_queue<pair<double,pair<double,double>>> pq;
         for(int i=0;i<N;i++){
             pq.push({(val[i]/wt[i]),{val[i],wt[i]}});
         }
        
        int maxwt,mwt,mval,ans=0;
        while(W){

         // pair<double, pair<double, double>> ap=pq.top();
          // if(ap.second.second>W) just an alternative way
           if(pq.top().second.second>W)
           pq.pop();
        
           W-=pq.top().second.second;
           ans+=pq.top().second.first;
        }
        
        return ans;
    }
};

//Easy Tabulation with space Optimization Striver Approach 

//time complexity - O(n*w)

//space complexity - O(w)

 

int helper(int ind,int w,int val[],int wt[]){
        vector<int> dummy(w+1,0);
        for(int j=0;j<=w;j++){
            if(j>=wt[0]){
                dummy[j] = (j/wt[0])*val[0];
            }
        }
        for(int i=1;i<=ind;i++){
            vector<int> cur(w+1,0);
            for(int j=0;j<=w;j++){
                 int notTake = dummy[j];
                 int take=0;
                 if(j>=wt[i]) take = cur[j-wt[i]] + val[i];
                 cur[j] = max(take,notTake);
            }
            dummy=cur;
        }
        return dummy[w];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return helper(N-1,W,val,wt);
    }
