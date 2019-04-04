#include <iostream>
#include <vector>
using namespace std;
int main()
{
    char case_num = 0;
    
    scanf("%d", &case_num);
    vector<short> scores(case_num, 0);
    for(short i=0; i<case_num; i++)
    {
    
        vector<short> score(101, 0);
        short test_num = 0;
     
        scanf("%hd", &test_num);
        for(int j=0; j<1000; j++){
            short value = 0;
            scanf("%hd", &value);
            score[value] += 1;
        }
        
        short max_num = 0;	//ÃÖºó ¼ö
        short max_score = 0;	//ÃÖºó ½ºÄÚ¾î
        
        for(short j=0; j<101; j++)
        {
            if( score[j] >= max_num)
            {
                
                max_num = score[j];
                max_score = j;
            }
        }
        scores[test_num-1] = max_score;
    }
    
    for(int i=0; i<scores.size(); i++)
    {
        printf("#%d %d\n",i+1, scores[i]);
    }
    return 0;
}