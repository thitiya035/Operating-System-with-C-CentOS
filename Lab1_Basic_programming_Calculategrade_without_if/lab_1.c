 #include<stdio.h>
 #include<stdlib.h>
 
float calculategrade( int sub_score){
		int   int_score;
		float score, point_score;
		float grade;

		score  		= (sub_score)/10.0;				// 1.1
		int_score 	= (sub_score)/10;				// 1
		point_score	= score - int_score;			// 0.1

		int chk_socre = point_score*10;
		switch(chk_socre){
			case 0 ... 4 :  point_score = 0.0; break;
			case 5 ... 10:  point_score = 0.5; break;
		}

		switch(int_score){
			case 0 ... 4:   int_score 	= 0;
							point_score = 0.0;
							break;
							
			case 5:  		int_score 	= 1;	break;
			case 6:  		int_score 	= 2;	break;
			case 7:  		int_score 	= 3;	break;
			case 8 ... 10:  int_score 	= 4;
							point_score = 0.0;	
							break;
		}
	grade = int_score+point_score;
	return grade; 
}


int main()
{
	#define num_subject 3
	int score[num_subject];
	int weigh[num_subject];

	float sum_score_weigh 	= 0;
	float sum_weigh			= 0;
	float aver_grade 		= 0;

	printf("INPUT SCORE EACH SUBJECT \n");

	for( int i = 0 ; i < num_subject ; i++ ){
		
		printf("\nSubject : %d\n", i+1);
		
		printf(" -> Input score : ");
		scanf("%d", &score[i]);
		while(!(score[i] >= 0 && score[i] <= 100)){
			printf(" !!! -> Input score again : ");
			scanf("%d", &score[i]);
		}

		printf(" -> Input weigh : ");
		scanf("%d", &weigh[i]);	
		while(!(score[i] >= 0 && score[i] <= 100)){
			printf(" !!! -> Input weigh again : ");
			scanf("%d", &weigh[i]);
		}

		printf("    ** Grade -> ( %.1f )",calculategrade(score[i]));
		
		sum_score_weigh +=calculategrade(score[i])*weigh[i];
		sum_weigh		+=weigh[i];
	}
	printf("\n\nAverage Grade = %.2f\n\n", sum_score_weigh/sum_weigh);
}
