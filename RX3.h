/************************************************************
		module RX3.h -
*************************************************************/

forward(YREAL R1,YREAL X3){

	YS1 = pow((R1/X3),4.);	
}

//===========================================================
backward(YREAL R1,YREAL X3){

	YJ1I1 = 4.*pow(R1,3.)/pow(X3,4.);
	YJ1I2 =  (-4.) * pow(R1,4.)/pow(X3,5.);	
}
 