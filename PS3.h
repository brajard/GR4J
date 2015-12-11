/************************************************************
		module PS3.h -
*************************************************************/

forward(YREAL PS11,YREAL PS12, YREAL PS21,YREAL PS22, YREAL PN){
	if(PN!=0){
		YS1 = PS11/PS21;
		YS2=0;
		
	}else{
		YS1=0;
		YS2= PS12/PS22;
		
	}
}

//===========================================================
backward(YREAL PS11,YREAL PS12, YREAL PS21,YREAL PS22, YREAL PN){

	if(PN!=0){
		
		YJ1I1 = 1./PS21;
		YJ1I3 = -PS11/pow(PS21,2.); 
				
	}else{
		YJ2I2 = 1./PS22;
		YJ2I4 = -PS12/pow(PS22,2.); 
	}
}
 
