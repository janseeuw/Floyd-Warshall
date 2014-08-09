//
//  Created by Jonas Anseeuw
//  Copyright (c) 2014 Jonas Anseeuw. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> &m){
	int vertices = m.size();
	for(int i=0; i<vertices; i++)
		cout << "\t" << i;
	cout<<"\n";
	for(int i = 0; i < vertices; i++){
		cout << i << "\t";
		for(int j = 0; j < vertices; j++)
			cout << m[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

void printPath(vector<vector<int>> &m, int i, int j){
	if(i == j){
		cout<<i;
	}else if (m[i][j] == -1){
		cout<<"Path does not exist";
	}else{
		printPath(m, i, m[i][j]);
		cout<<j;
	}
}

int main(){
	
	// Initialize
	int vertices = 5;
	vector<vector<int> > d(vertices, vector<int>(vertices,99));
	vector<vector<int> > p(vertices, vector<int>(vertices,-1));
	
	// Initialize diagonal
	for(int i=0; i < vertices; i++)
		d[i][i]=0;
	
	// Initialize distances
	d[0][1]=3;
	d[0][2]=8;
	d[0][4]=4;
	d[1][3]=1;
	d[1][4]=7;
	d[2][1]=4;
	d[3][0]=2;
	d[3][2]=5;
	d[4][3]=6;
	
	// Initialize predecessor
	for(int i = 0; i < vertices; i++)
		for(int j = 0; j < vertices; j++)
			if(i!=j && d[i][j]!=99){
				p[i][j] = i;
			}
	
	// Print out neighbour matrix
	cout<<"Distance matrix"<<endl;
	printMatrix(d);
	
	// Print out path matrix
	cout<<"Path matrix"<<endl;
	printMatrix(p);
	
	
	// Floyd-Warshall
	for(int k = 0; k < vertices; k++)
		for(int i = 0; i < vertices; i++)
			for(int j = 0; j < vertices; j++)
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					p[i][j] = p[k][j];
				}
	
	
	// Print out final distance matrix
	cout<<"Distance matrix"<<endl;
	printMatrix(d);
	
	// Print out final path matrix
	printMatrix(p);
	
	return 0;
}


