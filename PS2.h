/************************************************************
		module PS2.h -
*************************************************************/

forward(YREAL SX1, YREAL tanhPS,YREAL tanhES){

		YS1= 1.+(SX1*tanhPS);
	
		YS2= 1.+(1.-SX1)*tanhES;
	
}

//===========================================================
backward(YREAL SX1, YREAL tanhPS,YREAL tanhES){

	YJ1I1 = tanhPS;
	YJ1I2 = SX1;
	
	YJ2I1 = -tanhES;
	YJ2I3 =  1.-SX1;
}
 
