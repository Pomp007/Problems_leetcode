class DisjointSet{
public:
    vector<int> parent , size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n , 1);
        for(int i = 0; i < n ; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void UnionbySize(int u , int v){
        int Unp_u = findUPar(u);
        int Unp_v = findUPar(v);
        if(Unp_u == Unp_v){
            return;
        }
        if(size[Unp_u] < size[Unp_v]){
            parent[Unp_u] = Unp_v;
            size[Unp_v] = size[Unp_u] + 1;
        }
        else{
            parent[Unp_v] = Unp_u;
            size[Unp_u] = size[Unp_v] + 1;
        }
    }    
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string , int>mapMailNode;
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ;  j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) != mapMailNode.end()){
                    ds.UnionbySize(i , mapMailNode[mail]);
                    mapMailNode[mail] = i;
                }
                else{
                    mapMailNode[mail] = i;
                }
  
            }   
        }
        vector<string> mailMerge[n];
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findUPar( it.second);
            mailMerge[node].push_back(mail);
            
        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++ ){
            if(mailMerge[i].size() == 0){
                continue;
            }
            sort(mailMerge[i].begin() , mailMerge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mailMerge[i]){
                temp.push_back(it);

            }
            ans.push_back(temp);
        }
        return ans;


    }
};