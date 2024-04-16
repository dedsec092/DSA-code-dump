/*
Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows.

*******************************************************************************************
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    vector<int> ans;
    map<int,int> mapping;

    for(int i=0;i<mat.size();i++){
        unordered_set<int> s;// SET USED TO STORE UNIQUE ELEMENTS(THERE CAN BE DUPLICATE ELEMENTS IN A SINGLE ROW)
        for(int j=0;j<mat[0].size();j++){
            s.insert(mat[i][j]);
        }
        for (auto x : s) {// TRAVERSING SET
            mapping[x]++;
        }
    }


        for(auto y:mapping){// TRAVERSING MAP
            if(y.second==mat.size()){
                ans.push_back(y.first);
            }
        }
    
    return ans;
}
*/