#include<iostream>
#include <vector>
using namespace std;
vector<vector<int>> zeroRemover(vector<vector<int>> array, int array_size, string command) {
	if(command =="up") {
    	for(int i = 0 ; i <array_size-1 ; i++){
            	for(int j = 0 ; j < array_size; ) {
                    bool flag = true;
                	if(array[i][j] == 0) {
                        for(int q = i+1; q < array_size; q++) {
                            if(array[q][j] > 0) {
                            	flag = false; break;
                            }
                        }
                    	for(int q = i; q < array_size-1;q++) {
                        	array[q][j] =array[q+1][j];
                            array[q+1][j] = 0;
                        }
                    }
                    if(flag) j++;
                }
            }
    }
    else if(command == "down") {
    	for(int i = array_size-1 ; i >0 ; i--){
            	for(int j = 0 ; j < array_size; ) {
                    bool flag = true;
                	if(array[i][j] == 0) {
                        for(int q = i; q >= 0; q--) {
                            if(array[q][j] > 0) {
                            	flag = false; break;
                            }
                        }
                    	for(int q = i; q > 0;q--) {
                        	array[q][j] =array[q-1][j];
                            array[q-1][j] = 0;
                        }
                    }
                    if(flag) j++;
                }
            }
    }
    else if(command == "left"){
    	for(int j = 0 ; j < array_size ; j++) {
        	for(int i = 0 ; i < array_size;) {
                bool flag = true;
                if(array[i][j] ==0) {
            		for(int k =j+1; k < array_size ; k++) {
                		if(array[i][k] > 0) {
                    		flag = false; break;
                    	}
                	}
                	for(int k = j; k <array_size-1; k++) {
                		array[i][k] = array[i][k+1];
                    	array[i][k+1] =0;
                	}
                }
                if(flag) i++;
            }
        }
    }
    else if(command == "right") {
        for(int j = array_size-1 ; j > 0 ; j--) {
        	for(int i = array_size-1 ; i >= 0;) {
                bool flag = true;
                if(array[i][j] ==0) {
            		for(int k =j-1; k >= 0 ; k--) {
                		if(array[i][k] > 0) {
                    		flag = false; break;
                    	}
                	}
                	for(int k = j; k >0; k--) {
                		array[i][k] = array[i][k-1];
                    	array[i][k-1] =0;
                	}
                }
                if(flag) i--;
            }
        }
    }
    return array;
}
vector<vector<int>> sumArray(vector<vector<int>> array, int array_size, string command) {
	if(command == "up") {
        for(int u = 0 ; u < array_size-1; u++) {
           	for(int p = 0 ; p < array_size ; p++) {
               	if(array[u][p] == array[u+1][p] && array[u][p] != 0) { 
                    array[u][p] = array[u][p] +array[u+1][p];
                    array[u+1][p] = 0;
                }
            }
        }
    }
    else if(command == "down") {
        for(int u = array_size-1 ; u > 0; u--) {
           	for(int p = 0 ; p < array_size ; p++) {
               	if(array[u][p] == array[u-1][p] && array[u][p] != 0) { 
                    array[u][p] = array[u][p] +array[u-1][p];
                    array[u-1][p] = 0;
                }
            }
        }
    }
    else if(command == "left") {
        for(int j = 0 ; j < array_size-1; j++) {
        	for(int i = 0; i < array_size ; i++) {
                if(array[i][j] == array[i][j+1] && array[i][j]!=0) {
                	array[i][j] = array[i][j] + array[i][j+1];
                    array[i][j+1] = 0;
                }
            }
        }
    }
    else if(command =="right") {
        for(int j = array_size-1 ; j > 0; j--) {
        	for(int i = 0; i < array_size ; i++) {
                if(array[i][j] == array[i][j-1] && array[i][j] != 0) {
                	array[i][j] = array[i][j] + array[i][j-1];
                    array[i][j-1] = 0;
                }
            }
        }
    }
    return array;
}

int main(int argc, char** argv)
{
    // test_case count
	int T;
   	int array_size;
    string comnd;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" <<test_case<<endl;
    	//command
		cin>>array_size >> comnd;
        //배열 초기화
        vector< vector<int>> array;
        array.assign(array_size, vector<int>(array_size,0));
        for(int i = 0 ; i < array_size; i++)
            for(int j=0;j<array_size;j++) 
            {
                cin >> array[i][j];
            }
        
            array = zeroRemover(array, array_size, comnd);
        	array = sumArray(array, array_size, comnd);
        	array = zeroRemover(array, array_size, comnd);
        for(int u = 0 ; u <array_size ; u++){
            	for(int p = 0 ; p < array_size; p++) {
                	cout << array[u][p] << " " ;
                }
                cout << endl;
            }
		
        
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}