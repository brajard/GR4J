/************************************************************
		module PS1.h -
*************************************************************/

forward(YREAL S,YREAL SX1, YREAL tanhPS,YREAL tanhES, YREAL X1){		
	
	YS1=X1*(1.0-pow(SX1,2.0))*tanhPS;

	YS2 = S*(2.0-SX1)*tanhES;
}

//===========================================================
backward(YREAL S,YREAL SX1, YREAL tanhPS,YREAL tanhES, YREAL X1){
		
	YJ1I2 = (-2.) * tanhPS * X1 * SX1;
	YJ1I3 = X1*(1.-pow(SX1,2.));
	YJ1I5 = (1.-pow(SX1,2.))*tanhPS;

	YJ2I1 = (2.-SX1)*tanhES;
	YJ2I2 = (-1. ) * tanhES * S;
	YJ2I4 = S*(2.-SX1);	
}
 
