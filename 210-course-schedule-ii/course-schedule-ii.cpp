class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>>adj(numCourses);

        for(auto it : prerequisites){
             adj[it[1]].push_back(it[0]);
}
  vector inDegree(numCourses,0);

   for(int u=0; u<numCourses; u++){
    for(int v : adj[u]){
        inDegree[v]++;
    }
   }

   queue<int>q;

   for(int i=0; i<numCourses; i++){
    if(inDegree[i]==0){
        q.push(i);
    }
   }
   vector<int> topo;
   while(!q.empty()){
    int node = q.front();
    q.pop();
    topo.push_back(node);

    for(int neigbhor : adj[node]){
        inDegree[neigbhor]--;
        if(inDegree[neigbhor]==0){
            q.push(neigbhor);
        
        }
    }
   }
 
 if(topo.size()!= numCourses){
    return{};
 }
return topo;
    }
};