class Solution {
public:
    int getMatNum(int i,int j){
        return (i/3)*3 + j/3;
    }
    void SS(vector<vector<char>>& board,int i,int j,bool ans_found,vector<vector<int>>& rf,vector<vector<int>>& cf,vector<vector<int>>& mf, vector<vector<char>>& ans){
    if(ans_found){
            return;
        }
    if(i==9){
        ans_found=true;
        ans=board;
        return;
    }
    if(board[i][j]!='.'){
        if(j<8){
            SS(board,i,j+1,ans_found,rf,cf,mf,ans);
        }
        else{
            SS(board,i+1,0,ans_found,rf,cf,mf,ans);
        }
        return;
    }
    int mat_num=getMatNum(i,j);
    for(int val=1;val<=9;val++){
        
        if(rf[i][val-1]==0 && cf[j][val-1]==0 && mf[mat_num][val-1]==0){
            board[i][j] = static_cast<char>('0' + val);
            rf[i][val-1]=1,cf[j][val-1]=1,mf[mat_num][val-1]=1;
            
            
                if(j<8){
                    SS(board,i,j+1,ans_found,rf,cf,mf,ans);
                }
                else{
                    SS(board,i+1,0,ans_found,rf,cf,mf,ans);
                }
            
            
            board[i][j]='.';
            rf[i][val-1]=0,cf[j][val-1]=0,mf[mat_num][val-1]=0;
        }
    }
}
    void solveSudoku(vector<vector<char>>& board) {
        bool ans_found=false;
        vector<vector<int>> rf;
        vector<vector<int>> cf;
        vector<vector<int>> mf;
        for(int i=0;i<9;i++){
            vector<int> vec(9,0);
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    vec[board[i][j]-'1']=1;
                }
            }
             rf.push_back(vec);
        }
        for(int j=0;j<9;j++){
            vector<int> vec(9,0);
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    vec[board[i][j]-'1']=1;
                }
            }
            cf.push_back(vec);
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                
                vector<int> vec(9,0);
                for(int i1=i;i1<i+3;i1++){
                    for(int j1=j;j1<j+3;j1++){
                        if(board[i1][j1]!='.'){
                            vec[board[i1][j1]-'1']=1;
                        }
                    }
                }
                mf.push_back(vec);
            }
        }
        vector<vector<char>> ans;
        SS(board,0,0,ans_found,rf,cf,mf,ans);
        board=ans;
    }
};
