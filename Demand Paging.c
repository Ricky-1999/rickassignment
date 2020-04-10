#include <stdio.h>
#include <stdlib.h>
double page_fault_rate();
void userInput(void);

double sp_fault_empty;
double sp_fault_modified;
double mat;
double tp_modified;
double eat;
double pageFaultRate;
double sp_fault_empty_ns;
double sp_fault_modified_ns;
double tp_modified_per;
	

void main(){
	int swtch;
	
	do{
	
	
	printf("Select the required option \n");
	printf("1.Find the PageFault Rate \n");
	printf("2.Exit");
	scanf("%d",&swtch);
	switch(swtch){
		case 1:userInput();break;
		case 2:exit(0);
	}
	printf("\n\n");

}while(swtch<3);
}
void userInput(){
	
	
	printf("\nEnter service Page Fault [Empty|Page is not Modified][in ms]");
	scanf("%lf",&sp_fault_empty);
	printf("Enter Service Page Fault [Modified Page][in ms]");
	scanf("%lf",&sp_fault_modified);
	printf("Enter Memory Access Time[in ns]");
	scanf("%lf",&mat);
	printf("Enter Percentage of time the page to be replaced is modified[0-100]");
	scanf("%lf",&tp_modified);
	printf("Enter Effective Access time[in ns]");
	scanf("%lf",&eat);

	sp_fault_empty_ns = (sp_fault_empty*1000000);
	sp_fault_modified_ns = (sp_fault_modified*1000000);
	tp_modified_per = (tp_modified/100);   
	printf("\nPage Fault rate calculated For:\n");
	printf("Service Page Fault[Empty|Page Not Modified]=%lf \n",sp_fault_empty_ns);
	printf("Service Page Fault [Modified Page][in ns] %lf \n",sp_fault_modified_ns);
	printf("Memory Access Time[in ns]%lf\n",mat);
	printf("Effective Access Time %lf\n",eat);
    pageFaultRate =  page_fault_rate(sp_fault_empty_ns,sp_fault_modified_ns,mat,tp_modified_per,eat);
	printf("\nMaximum Acceptable Page Fault rate = %.2e[exponential notation]",pageFaultRate);

}

double page_fault_rate(double servicePageFaultEmpty,double servicePageFaultMod,double memAccess,double timesPages,double effAccess){
	double assume,serve;
	double numErator,denOminator;
	double pageFault;
	 assume = (1- timesPages)*servicePageFaultEmpty;
	 serve = timesPages*servicePageFaultMod;
	 numErator = effAccess - memAccess;
     denOminator = (assume+serve);

	pageFault = numErator/denOminator;
	return pageFault;


} 
