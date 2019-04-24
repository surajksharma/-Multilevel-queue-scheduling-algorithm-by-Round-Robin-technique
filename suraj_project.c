#include<stdio.h>
#include<stdbool.h>

//SORTIING

int main()
	{
		system("color 3B");		
	int N,i,pq1=0,pq2=0,pq3=0,tt=0;
	int Q1[5]={0},Q2[5]={0},Q3[5]={0};
	// Q1=
	//pq= no. of processes in queue.
	//tt= total time to complete the process.
	printf("Enter the number of processes :-\n");
	scanf("%d",&N);
	int processes[N],waiting_time[N],burst[N],priority[N],rem_bt[N];
	//  N = no. of processes.
	//  processes[N] = array to store n processes.
	//  waiting_time[N] = array to store waiting time of N processes.
	//  priority[N] = array to store priority of N processes.
	//  burst[N] = burst time of N processes.
	//  rem_bt[N]= remaining burst time of processes.
	
	/* TO TAKE INPUTS FROM THE USER	*/
	for(i=0;i<N;i++){
		int b;		//b = input of burst time for every process.
		int pr;		//pr = input of priority for each process.
		processes[i]=i+1;
		burst[i]=0;
		priority[i]=0;
		printf("Enter the burst item for process %d\n",i+1);
		scanf("%d",&b);
		burst[i]=b;
		printf("Enter the priority for process %d\n",i+1);
		scanf("%d",&pr);
		priority[i]=pr;
		if(pr==1||pr==2){
			Q1[pq1]=i+1;
			pq1++;
		}
		else if(pr==3||pr==4){
			Q2[pq2]=i+1;
			pq2++;
		}
		else{
			Q3[pq3]=i+1;
			pq3++;
		}	
	}
	//sorting performed.
   int  j; 
   for (i = 0; i < pq2-1; i++)   
   {
       for (j = 0; j < pq2-i-1; j++) 
	   {
           if (priority[Q2[j]-1]> priority[Q2[j+1]-1]) {
           	int temp=Q2[j];
           	Q2[j]=Q2[j+1];
           	Q2[j+1]=temp;
       }
} }
	//creating of reamainig burst time array.
	for(i=0;i<N;i++){
		waiting_time[i]=0;//waiting time array to zer0.
		rem_bt[i]=burst[i];
	}	
	while(1){
		bool done=true;
		int Qt=10;
		//Qt =10s; for multilevel queue scheduling.
		while(Qt>0)
		{
		for(i=0;i<pq1 && Qt>0;i++){
			if(rem_bt[Q1[i]-1]>0){
				done =false;
				if(rem_bt[Q1[i]-1]<=Qt){
					if(rem_bt[Q1[i]-1]>4){
						tt=tt+4;
						Qt=Qt-4;
						rem_bt[Q1[i]-1]-=4;
						
						printf("%d\t",processes[Q1[i]-1]);
					}
					else{
						tt=tt+rem_bt[Q1[i]-1];
						Qt=Qt-rem_bt[Q1[i]-1];
						waiting_time[Q1[i]-1]=tt-burst[Q1[i]-1];
						rem_bt[Q1[i]-1]=0;
						printf("%d\t",processes[Q1[i]-1]);
					}
				}
				else{
					rem_bt[Q1[i]-1]=rem_bt[Q1[i]-1]-Qt;
					tt=tt+Qt;
					Qt=0;
					printf("%d\t",processes[Q1[i]-1]);
					break;// break always breaks from the loop.
				}
			}	
		}
		int esc=0;
		for(i=0;i<pq1;i++){
			if(rem_bt[Q1[i]-1]==0){
				esc++;
			}
		}
		if(esc==pq1){
			break;
		}
		}
		Qt=10;

		while(Qt>0){
		
		for(i=0;i<pq2 && Qt>0;i++){ //loop to traverse queue 2
			if(rem_bt[Q2[i]-1]>0){
				done =false;
				if(rem_bt[Q2[i]-1]<=Qt){
					tt=tt+rem_bt[Q2[i]-1];
					Qt=Qt-rem_bt[Q2[i]-1];
					rem_bt[Q2[i]-1]=0;
					waiting_time[Q2[i]-1]=tt-burst[Q2[i]-1];
					printf("%d\t",processes[Q2[i]-1]);	
				}
				else{
					tt=tt+Qt;
					rem_bt[Q2[i]-1]=rem_bt[Q2[i]-1]-Qt;
					Qt=0;
					printf("%d\t",processes[Q2[i]-1]);
					break;
				}
			}
		}
		int esc=0;
		for(i=0;i<pq2;i++){
			if(rem_bt[Q2[i]-1]==0){
				esc++;
			}
		}
		if(esc==pq2){
			break;
		}
		}
		Qt=10;
		while(Qt>0){
		
		for(i=0;i<pq3 && Qt>0;i++){
			if(rem_bt[Q3[i]-1]>0){
				done =false;
				if(rem_bt[Q3[i]-1]<=Qt){
					tt=tt+rem_bt[Q3[i]-1];
					Qt=Qt-rem_bt[Q3[i]-1];
					rem_bt[Q3[i]-1]=0;
					waiting_time[Q3[i]-1]=tt-burst[Q3[i]-1];
					printf("%d\t",processes[Q3[i]-1]);
				}
				else{
					tt=tt+Qt;
					rem_bt[Q3[i]-1]=rem_bt[Q3[i]-1]-Qt;
					Qt=0;
					printf("%d\t",processes[Q3[i]-1]);
					break;
				}
			}
		}
		int esc=0;
		for(i=0;i<pq3;i++){
			if(rem_bt[Q1[i]-1]==0){
				esc++;
			}
		}
		if(esc==pq3){
			break;
		}
		}
		
	if(done==true){
		break;
	}
	}
	printf("\n");
	printf("Waiting Time\t\tTurnAround Time\n");
	for(i=0;i<N;i++){
		printf("%d\t\t\t\t%d\n",waiting_time[i],waiting_time[i]+burst[i]);
	}
	printf("\n");
	
	printf("Average waiting time = ");
	int waitsum=0,turnsum=0;
	for(i=0;i<N;i++){
		waitsum+=waiting_time[i];
		turnsum+=waiting_time[i]+burst[i];
	}
	printf("%f",(float)waitsum/(float)N);
	printf("\n");
	printf("Average turnaroud time = ");
	printf("%f",(float)turnsum/(float)N);
}
