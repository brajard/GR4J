/************************************************************
		module ENX1.h -
*************************************************************/

forward(YREAL EN,YREAL X1){

	YS1 = EN/X1;
}

//===========================================================
backward(YREAL EN,YREAL X1){
	
	YJ1I1 = 1./X1;
	YJ1I2 = -EN/pow(X1,2.);
	
}
 
