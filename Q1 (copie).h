/************************************************************
		module SH1.h -
*************************************************************/

forward(YREAL PR1,YREAL X4){

	int m = floor(2*X4)+1;
	int i=0;int k1=0;int h=0;int k=0;

	
	float somme=0;	
	float tempk[SIZE];	

	/*for(k=SIZE-1;k>0;k--){   //décalage
		temp[k] = temp[k-1];		
	}*/
	
	//temp[0] = PR1;
	
	tempk[0] = 0;
	for(h =1; h<SIZE;h++){  //HU2
		if(h<X4){
			tempk[h] = 0.5*pow((h/X4),2.5);
		}else if(h<2*X4){
	
			tempk[h] = 1-(0.5*pow(2-(h/X4),2.5));

			}else{tempk[h]=1;}				
	}	
	

	for(k1=7;k1>0;k1--){   //SH2
		tempk[k1] -= tempk[k1-1];	
	}

	for(i=1; i <=m;i++ ){
		somme+=	tempk[i]*temp[i-1];
	}

	YS1 = 0.1* somme;		
	
}

//===========================================================
backward(YREAL PR1 , YREAL X4){
	
	int m = floor(2*X4)+1;
	int h=0;int k=0;
	int T=0;		
	float tempk[SIZE];


	tempk[0] = 0;
	for(h =1; h<SIZE;h++){  //HU2
		if(h<X4){
			tempk[h] = 0.5*pow((h/X4),2.5);
		}else if(h<2*X4){
	
			tempk[h] = 1-(0.5*pow(2-(h/X4),2.5));

			}else{tempk[h]=1;}				
	}		
	
	for(T=YTemps;T<YTemps-m+1;T--){
		
		if(T>=0){
			YG1_PR(Yi,T) +=0.1*YG1_Q1(Yi,YTemps)*tempk[T-YTemps+1];
		}else{
			YG1_PR(Yi,0) +=0;
		}
	}
	
}
 
