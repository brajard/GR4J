/************************************************************
		module SH1.h -
*************************************************************/

forward(YREAL PR1,YREAL X4){

	int l = floor(X4)+1;
	int i=0;int k=0;int k1=0;int h=0;
	
	float somme=0;
	float tempk[SIZE];

	for(k=SIZE-1;k>0;k--){   //décalage
		temp[k] = temp[k-1];		
	}
	
	temp[0] = PR1;
	
	tempk[0] = 0;    //SH1
	for(h =1; h<SIZE;h++){
		if(h<X4){
			tempk[h] = pow((h/X4),2.5);
		}else if(h>X4){
			tempk[h] = 1;			
		}
	}	

	for(k1=7;k1>0;k1--){   //UH1
		tempk[k1] -= tempk[k1-1];	
	}

	for(i=1; i <=l;i++ ){
		somme+=	tempk[i]*temp[i-1];
	}
	YS1 = 0.9* somme;	
	
}

//===========================================================
backward(YREAL PR1 , YREAL X4){
	
	int l = floor(X4)+1;
	int h=0;
	int T=0;
	float tempk[SIZE];

	tempk[0] = 0;    //SH1
	for(h =1; h<SIZE;h++){
		if(h<X4){
			tempk[h] = - pow(h,2.5) * (1/(pow(X4,3.5)));//pow((h/X4),2.5);
		}else if(h>X4){
			tempk[h] = 0;			
		}
	}	
	
	for(T=YTemps;T<YTemps-l+1;T--){
		
		if(T>=0){
			YG1_PR(Yi,T) +=0.9*YG1_Q9(Yi,YTemps)*tempk[T-YTemps+1];
			YG2_PR(Yi,T) += 0.9*YG2_PR(Yi,T)*tempk[T-YTemps+1];
		}else{
			YG1_PR(Yi,0) +=0;
			YG2_PR(Yi,0) +=0;
		}
	}
}
 
