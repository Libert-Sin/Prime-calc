#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define PRINUM 698522
#define MOVE 1000000000



int main()
{
	clock_t start_t,end_t;
	float timer;
	start_t=clock();

//////////////////////////////////////////////////////////////
	char cmd_buffer[162];
	int prime[PRINUM];
	int division[PRINUM];
	int calc[PRINUM];
	int i1,i2;
	int j1,j2,j3;
	
	//배열 초기화
	for(i1=PRINUM;i1>=0;i1--)
	{
		prime[i1]=0;
		division[i1]=0;
		calc[i1]=0;
	}	
	prime[0]=2;
	division[0]=2;

		
	for(;;)
	{	
	  	for(i1=0;i1<=PRINUM;i1++)
                {
			calc[i1]=prime[i1];
		}
		
		for(;;)
		{
			//전체 크기 비교
			j1=0;
			for(i1=PRINUM;i1>=0;i1--)
			{
				if(prime[i1]>=division[i1])
				{
					j1=1;break;
				}
				else if(prime[i1]<division[i1])
	                	{
        	                	j1=2;break;
                		}
			}	
	
	

			//뺄샘 반복
			if(j1==1)
			{
				for(i1=0;i1<PRINUM;i1++)
				{
					calc[i1]-=division[i1];
					
					j3=0;
					for(i2=PRINUM;i2>=0;i2--)
					{
						if(calc[i2]<division[i2])
						{
		 					j3=1;break;
						}
					}
                       
					
					
					for(i2=PRINUM;i2>0;i2--)
					{
						if(calc[i2]>0)
						{
							if(calc[i2-1]<MOVE)
							{
								calc[i2]--;
								calc[i2-1]+=MOVE;
							}
						}
					}
					

					
				}
			}
			else if(j1==2)
			{
				break;
			}
			if(j3==1)
			{
				break;
			}
		}

		j2=0;

		//배열 동일성 확인
		for(i1=0;i1<=PRINUM;i1++)
		{
			if(prime[i1]!=division[i1])
      			{
				j2++;
			}
		}
		j3=0;
		for(i1=0;i1<=PRINUM;i1++)
                {
			j3+=calc[i1];
                }


		if(j3==0)
		{
			if(j2==0)
			{
				for(i1=PRINUM;i1>=0;i1--)
        	       	 	{
                	        	printf("%d ",prime[i1]);
					sprintf(cmd_buffer,"echo -n %d >> /home/libert/Works/prime/prime", prime[i1]);
					system(cmd_buffer);
              	  		}
				printf("\n");
                                system("echo "" >> /home/libert/Works/prime/prime");
			
			}
			for(i1=0;i1<=PRINUM;i1++)
                	{
                        	division[i1]=0;
                        	calc[i1]=0;
                	}
                	division[0]=1;
	
			prime[0]++;
			for(i1=0;i1<PRINUM;i1++)
	                {
        	                if(prime[i1]>MOVE)
                	        {
                        	        prime[i1]-=MOVE;
                                	prime[i1+1]++;
                        	}
                	}

		}
		division[0]++;
		for(i1=0;i1<PRINUM;i1++)
		{
			if(division[i1]>MOVE)
			{
				division[i1]-=MOVE;
				division[i1+1]++;
			}
		}
	}






//////////////////////////////////////////////////////////////

	end_t=clock();
	timer=(float)(clock()-start_t)/CLOCKS_PER_SEC;
	printf("소요시간 : %.6fs \n",timer);
	sprintf(cmd_buffer,"echo -ne \n\n소요시간 : %.6fs \n >> /home/libert/Works/prime/prime",timer);
	system(cmd_buffer);
}

