/************************************************************
		module INTERC.h -
*************************************************************/

forward(YREAL P,YREAL E){
	
	if (P>=E){
		YS1 = P-E;		
	}
	else{
		YS2 = E-P;
		
	}
	
}

//===========================================================
backward(YREAL P,YREAL E){
	
	if(P>=E){
		YJ1I1 = 1.;
		YJ1I2 = -1.;
	}
	else{
		YJ2I1 = -1.;
		YJ2I2 = 1.;	
	}	
}
 
