/*
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{	// intersection..
	int intersections=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr1[i]==arr2[j]){
				intersections++;
			}
		}

	}   

	//union
	set<int> s;
	
	for(int i=0;i<n;i++){
		s.insert(arr1[i]);
	}
	for(int i=0;i<m;i++){
		s.insert(arr2[i]);
	}
	vector<int> un(s.begin(),s.end());
	int count=0;
	for(int i=0;i<un.size();i++){
		count++;
	}

	// storing in a pair..
	pair<int ,int> p;
	p.first=intersections;
	p.second=count;

	return p;

}
*/